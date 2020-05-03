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
#include"korisno.h"
#include"SveGreske.h"
//typedef std::vector<Layer*> mapa;
typedef std::map<int, std::shared_ptr<Layer>> mapa;
typedef std::vector<Selekcija> selekcije;
typedef std::vector<std::shared_ptr<ioperation>> op;

class Image {
	//typedef std::vector<Layer> slojevi;
	mapa layers;
	int sirina, visina, brlejera;
	int brbitapopixelu;
	selekcije sel;
	op operacije;
	aktivni akt;
public:
	Image(int s = 0, int v = 0, int bbpp = 32) {
		sirina = s;
		visina = v;
		brlejera = 0;
		brbitapopixelu = bbpp;
		sel.clear();

		operacije.clear();
		dodajPush();
	}
	// 1. funkcije za : prosirenje slike (realokacija svakog lejera, tj matrica u svakom lejeru), on prodje kroz sve lejere i u njima prosirenje pozove
	// prosledim novu velicinu u funkciju
	// 2. funkcija za dodavanje lejera, i ako je sirina i visina lejera veca od image sir i visine, onda
	// prosiriti sirinu i visinu u svim lejerima
	// tj ako dodas lejer koji je veci od ostalih, svi ostali moraju da porastu
	void ObrisiLejer(int pozicija) {
		if (layers.count(pozicija) == 0)
			return;
		layers.erase(pozicija);

		/*return;*/
		//if (layers[pozicija] == nullptr) return; // THROW GRESKA U INDEKSIRANJU
		//std::shared_ptr<Layer> temp = layers[pozicija];
		//for (int i = pozicija; i != brlejera - 1; i++) {
		//	layers[i] = layers[i + 1]; 
		//}
		//layers[brlejera - 1] = temp;
		//layers[brlejera-1]->~Layer();
		//brlejera--;
	}
	op& getOperacije() { return operacije; }
	void dodajPush() {
		operacije.push_back(std::make_shared<Push>(0));
	}
	void DodajOperaciju(int input, int value) {
		if (input == 1) {
			operacije.push_back(std::make_shared<Absolute>(value));
			
		}
		else if (input == 2) {
			
			operacije.push_back(std::make_shared<Add>(value));
		}
		else if (input == 3) {
			//	i->getOperacije().push_back(&Crnobela());
			operacije.push_back(std::make_shared<Crnobela>());
		}
		else if (input == 4) {
			
			operacije.push_back(std::make_shared<Div>(value));
		}
		else if (input == 5) {
			
			operacije.push_back(std::make_shared<DivInvert>(value)); 
		}
		else if (input == 6) {
			operacije.push_back(std::make_shared<Inverzija>()); 
		}
		else if (input == 7) {
			operacije.push_back(std::make_shared<Log>(0)); 
		}
		else if (input == 8) {
			
			operacije.push_back(std::make_shared<Max>(value)); 
		}
		else if (input == 9) {
			
			operacije.push_back(std::make_shared<Min>(value));
		}
		else if (input == 10) {
			
			operacije.push_back(std::make_shared<Mul>(value)); 
		}
		else if (input == 11) {
	
			operacije.push_back(std::make_shared<Pow>(value));
		}
		else if (input == 12) {
			operacije.push_back(std::make_shared<Siva>());
		}
		else if (input == 13) {
			
			operacije.push_back(std::make_shared<Sub>(value));
		}
		else if (input == 14) {
			
			operacije.push_back(std::make_shared<SubInvert>(value)); 
		}
		else {
			throw GreskaNevalidnaOperacija();
		}
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
	void dodajAktivan(int novi) {
		akt.push_back(novi);
	}
	void dodajSelekciju(std::string s, pravougaonici pp, bool stanje) {

		bool VecPostoji = false;
		for (int i = sel.size() - 1; i >= 0; i--) {
			if (sel[i].getIme().compare(s) == 0) {
				
				VecPostoji = true;
			}
		}
		if (!VecPostoji) {
			Selekcija* nova = new Selekcija(s, pp);
			nova->setStanje(stanje);
			sel.push_back(*nova);
		}
		else {
			throw GreskaNepostojecaSelekcija("Selekcija sa datim imenom koju dodajete vec postoji");
		}
	

	}
	void ObrisiSelekciju(std::string poz) {
		//sel.erase(sel.begin()+poz-1);
		bool obrisan=false;
		for (int i = sel.size()-1; i >=0; i--) {
			if (sel[i].getIme().compare(poz) == 0) {
				sel.erase(sel.begin()+i);
				obrisan = true;
			}
		}
		if (!obrisan) {
			throw GreskaNepostojecaSelekcija();
		}
		//if los index greska
	}
	selekcije& getSelekcije() { return sel; }
	void DodajSloj(std::shared_ptr<Layer>  l, int pozicija) {


		if (l->getvisina() > visina) {
			//realociram sve lejere
			for (auto i = layers.begin(); i != layers.end(); i++) {

				(*i).second->realocirajPovecaj(sirina, l->getvisina());

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
		if (layers.count(pozicija) == 0) {
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
	std::shared_ptr<Layer> konstruisiFinalniLayer(aktivni a) {
		//return layers[0];// TODO: PRVO OVO OD ZIZE, a posle toga AKTIVNE LEJERE, a posle toga UVEK PUSH PAJA
		std::shared_ptr<Layer> lejer = std::make_shared<Layer>(sirina, visina);
		std::vector<std::shared_ptr<Layer>> aktivniLejeri;

		if (a.size() == 0) return lejer;
		for (const auto& i : layers) {
			if (inAktivni(i.first, a)) {
				aktivniLejeri.push_back(i.second);
			}
		}

		for (int i = 0; i < sirina; i++) {
			for (int j = 0; j < visina; j++) {
				Piksel piksel = aktivniLejeri[0]->getPixel(i, j);
				double r = piksel.getR() * 1.0 / 255;
				double g = piksel.getG() * 1.0 / 255;
				double b = piksel.getB() * 1.0 / 255;
				double opacity = piksel.getOpacity() * 1.0 / 255;

				
					for (int k = 1; k != aktivniLejeri.size(); k++) {
						if (opacity == 1.0) { break; }
						
						Piksel p1 = aktivniLejeri[k]->getPixel(i,j);
						double r1 = p1.getR() * 1.0 / 255;
						double g1 = p1.getG() * 1.0 / 255;
						double b1 = p1.getB() * 1.0 / 255;
						double opacity1= p1.getOpacity() * 1.0 / 255;
						if (opacity1 == 0)continue;
						double temp = (1 - opacity)* opacity1 ;
						double opt = opacity + temp;
						double temp2 = temp / opt;
						double temp3 = opacity / opt;
						double rt = r * temp3 + r1 * temp2;
						double gt = g * temp3 + g1 * temp2;
						double bt = b * temp3 + b1 * temp2;
						
						r = rt;
						b = bt;
						g = gt;
						opacity = opt;

					}
				
				Piksel novi = Piksel(r*255, g*255, b*255, 0, opacity*255);
				lejer->overwritepixel(i, j, novi);
			}
		}

		return lejer;
	


		for (int j = visina - 1; j > 0; j--) {
			int i = 0;
			for (i = 0; i < sirina; i++) {
				double A = 0, G = 0, R = 0, B = 0, A2 = 0;
				double Apret = 0, Atren = 0, Rpret = 0, Rtren = 0, Bpret = 0, Btren = 0, Gpret = 0, Gtren = 0;

				int k = 0;

				while (!inAktivni(k, a)) { k++; }

				A = layers[k]->getPixel(i, j).getOpacity() * 1.0 / 255;
				//Piksel p = layers[0]->getPixel(i, j);
				//uint8_t temp = (uint8_t)layers[0]->getPixel(i, j).getOpacity();
				Apret = A;
				//A = temp / 255;
				k++;
				while (k != brlejera) {
					if (!inAktivni(k, a)) { k++; continue; }
					Atren = layers[k]->getPixel(i, j).getOpacity() * 1.0 / 255;
					A = A + (1 - Apret) * Atren;
					Apret = Atren;
					k++;
				}
				k = 0; 	while (!inAktivni(k, a)) { k++; }

				A2 = layers[k]->getPixel(i, j).getOpacity() * 1.0 / 255; Apret = A2;
				R = layers[k]->getPixel(i, j).getR() * ((layers[k]->getPixel(i, j).getOpacity() * 1.0 / 255) * 1.0 / A);
				G = layers[k]->getPixel(i, j).getG() * ((layers[k]->getPixel(i, j).getOpacity() * 1.0 / 255) * 1.0 / A);
				B = layers[k]->getPixel(i, j).getB() * ((layers[k]->getPixel(i, j).getOpacity() * 1.0 / 255) * 1.0 / A);
				Rpret = R;
				Gpret = G;
				Bpret = B;
				k++;
				while (k != brlejera) {
					if (!inAktivni(k, a)) { k++; continue; }
					Atren = layers[k]->getPixel(i, j).getOpacity() * 1.0 / 255;
					Rtren = layers[k]->getPixel(i, j).getR();
					Gtren = layers[k]->getPixel(i, j).getG();
					Btren = layers[k]->getPixel(i, j).getB();
					R = R + Rtren * (1 - Apret) * (Atren * 1.0 / A);
					G = G + Gtren * (1 - Apret) * (Atren * 1.0 / A);
					B = B + Btren * (1 - Apret) * (Atren * 1.0 / A);
					Rpret = Rtren;
					Gpret = Gtren;
					Bpret = Btren;
					Apret = Atren;
					k++;
				}


				lejer->overwritepixel(i, j, Piksel(R, G, B, 0, A));
			}
		}
		return lejer;



	}
	
	aktivni& getAkt() { return akt; }
	void setAkt(aktivni& a) { akt = a; }
	mapa& getLayers() { return layers; }
	int getSirina()const { return sirina; }
	int getvisina()const { return visina; }
	int getBrlejera()const { return brlejera; }
	//int getBrBitaPoPixelu()const { return brbitapopixelu; }
	//void setBrBitaPoPixelu(int bb) { brbitapopixelu = bb; }

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
