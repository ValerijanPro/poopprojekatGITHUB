#pragma once
#include<map>
#include<memory>
#include<iostream>
#include <vector>
#include"Piksel.h"
#include"Layer.h"
#include"GreskaPostojiKljuc.h"
#include"Selekcija.h"
#include"Timotije.h"
//typedef std::vector<Layer*> mapa;
typedef std::map<int, std::shared_ptr<Layer>> mapa;
typedef std::vector<Selekcija> selekcije;
typedef std::vector<std::shared_ptr<ioperation>> op;
class Image{
	//typedef std::vector<Layer> slojevi;
	mapa layers;
	int sirina, visina,brlejera;
	int brbitapopixelu;
	selekcije sel;
	op operacije;
public:
	Image(int s=0, int v=0,int bbpp=0) {
		sirina = s;
		visina = v;
		brlejera = 0;
		brbitapopixelu = bbpp;
		sel.clear();
		operacije.clear();
	}
	// 1. funkcije za : prosirenje slike (realokacija svakog lejera, tj matrica u svakom lejeru), on prodje kroz sve lejere i u njima prosirenje pozove
	// prosledim novu velicinu u funkciju
	// 2. funkcija za dodavanje lejera, i ako je sirina i visina lejera veca od image sir i visine, onda
	// prosiriti sirinu i visinu u svim lejerima
	// tj ako dodas lejer koji je veci od ostalih, svi ostali moraju da porastu
	op& getOperacije() { return operacije; }
	void dodajPush() {
		operacije.push_back(std::make_shared<Push>(0));
	}
	int DodajOperaciju(int input) {
		std::shared_ptr<ioperation> p1 = std::make_shared<Absolute>(0);
		if (input == 1) {
			operacije.push_back(std::make_shared<Absolute>(0));
			return 1;
		}
		else if (input == 2) {
			int broj;
			std::cout << "Unesite koji broj zelite da dodate: " << std::endl;
			std::cin >> broj;
			operacije.push_back(std::make_shared<Add>(broj)); return 1;
		}
		else if (input == 3) {
			//	i->getOperacije().push_back(&Crnobela());
			operacije.push_back(std::make_shared<Crnobela>()); return 1;
		}
		else if (input == 4) {
			int broj;
			std::cout << "Unesite broj kojim zelite da podelite" << std::endl;
			std::cin >> broj;
			operacije.push_back(std::make_shared<Div>(broj)); return 1;
		}
		else if (input == 5) {
			int broj;
			std::cout << "Unesite broj koji zelite da podelite" << std::endl;
			std::cin >> broj;
			operacije.push_back(std::make_shared<DivInvert>(broj)); return 1;
		}
		else if (input == 6) {
			operacije.push_back(std::make_shared<Inverzija>()); return 1;
		}
		else if (input == 7) {
			operacije.push_back(std::make_shared<Log>(0)); return 1;
		}
		else if (input == 8) {
			int broj;
			std::cout << "Unesite broj za max" << std::endl;
			std::cin >> broj;
			operacije.push_back(std::make_shared<Max>(broj)); return 1;
		}
		else if (input == 9) {
			int broj;
			std::cout << "Unesite broj za min" << std::endl;
			std::cin >> broj;
			operacije.push_back(std::make_shared<Min>(broj)); return 1;
		}
		else if (input == 10) {
			int broj;
			std::cout << "Unesite broj kojim zelite da pomnozite" << std::endl;
			std::cin >> broj;
			operacije.push_back(std::make_shared<Mul>(broj)); return 1;
		}
		else if (input == 11) {
			int broj;
			std::cout << "Unesite eksponent na koji podizete" << std::endl;
			std::cin >> broj;
			operacije.push_back(std::make_shared<Pow>(broj)); return 1;
		}
		else if (input == 12) {
			operacije.push_back(std::make_shared<Siva>()); return 1;
		}
		else if (input == 13) {
			int broj;
			std::cout << "Unesite koji broj zelite da oduzmete: " << std::endl;
			std::cin >> broj;
			operacije.push_back(std::make_shared<Sub>(broj)); return 1;
		}
		else if (input == 14) {
			int broj;
			std::cout << "Unesite koji broj od kog zelite da oduzmete: " << std::endl;
			std::cin >> broj;
			operacije.push_back(std::make_shared<SubInvert>(broj)); return 1;
		}

		else return 0;
	
	}

	void dodajSelekciju(std::string s,pravougaonici pp,bool stanje) {
		Selekcija* nova = new Selekcija(s, pp);
		nova->setStanje(stanje);
		sel.push_back(*nova);
		
	}
	selekcije& getSelekcije() { return sel; }
	void DodajSloj(std::shared_ptr<Layer>  l,int pozicija) {


		if ( l->getvisina() > visina) {
			//realociram sve lejere
			for (auto i = layers.begin(); i != layers.end(); i++) {
				
				(*i).second->realocirajPovecaj(sirina,l->getvisina());
		
			}
			visina = l->getvisina();
	
			// na poziciju upisati novi lejer

			//matricu piksela prosiris praznim pikselima tj crnim TREBA PROVIDNIM
		}
		if (l->getSirina() > sirina) {
			//realociram sve lejere
			/*for (std::vector<Layer*>::iterator i = layers.begin(); i != layers.end(); i++) {
				(*i)->realocirajPovecaj(l ->getSirina(), visina);
			}*/
			// na poziciju upisati novi lejer
			for (auto i = layers.begin(); i != layers.end(); i++) {

				(*i).second->realocirajPovecaj(l->getSirina(), visina);

			}
			sirina = l->getSirina();
			//matricu piksela prosiris praznim pikselima tj crnim TREBA PROVIDNIM
		}		
		if (l->getSirina() < sirina) {
			// l resize sirina
			l->realocirajPovecaj(sirina, l->getvisina());
		}
		if (l->getvisina() < visina) {
			//l resize visina
			l->realocirajPovecaj(l->getSirina(), visina);
		}
		//insert na poziciju
		if (layers.count(pozicija)==0) {
			layers[pozicija] = l;
			sirina = l->getSirina();
			visina = l->getvisina();
			brlejera++;
		}
		else {
			throw GreskaPostojiKljuc("Greska vec postoji dati layer");
		}

		//else { // ako je istih dimenzija samo dodam na kraj
		//	//layers.push_back(l);
		//	brlejera++;
		//}
		
	}
	std::shared_ptr<Layer> konstruisiFinalniLayer() {
		return layers[0];
	}
	void ObrisiSloj() {

	}
	int getSirina()const { return sirina; }
	int getvisina()const { return visina; }
	int getBrlejera()const { return brlejera; }
	int getBrBitaPoPixelu()const { return brbitapopixelu; }
	void setBrBitaPoPixelu(int bb) { brbitapopixelu = bb; }
private:
	void kopiraj(const Image& s) {
		visina = s.visina;
		sirina = s.sirina;
		brlejera = s.brlejera;
		for (auto i = s.layers.begin(); i != s.layers.end(); i++) {
			std::shared_ptr<Layer> l = (*i).second;
			layers[(*i).first] = l;
/*
			Layer l = *(*i).second;
			layers[(*i).first] =&l;*/
			//((*i).second).realocirajPovecaj(sirina, l->getvisina());
		}

	}
	void premesti(Image& s) {
		layers = s.layers;
		for (auto i = s.layers.begin(); i != s.layers.end(); i++) {
			i = s.layers.erase(i);

		}
		visina = s.visina;
		sirina = s.sirina;
		brlejera = s.brlejera;
		s.visina = 0;
		s.sirina = 0;
		s.brlejera = 0;
	}
	void brisi() {
		layers.clear();
		//PROBLEM S BRISANJEM ILI OK?
		/*for (auto i = m.begin(); i !=m.end(); i++) {
			m.erase(i);


		}*/

		sirina = 0;
		visina = 0;
		brlejera = 0;
		sel.clear();
		operacije.clear();
	}
public:
	Image(const Image& s) { kopiraj(s); }
	Image(Image&& s) { premesti(s); }
	Image& operator=(const Image& s) {
		if (this != &s) {
			brisi();
			kopiraj(s);
		}
		return (*this);
	}
	Image& operator=(Image&& s) {
		if (this != &s) {
			brisi();
			premesti(s);
		}
		return (*this);
	}
	virtual ~Image() { brisi(); }


}; 
