#pragma once
#include<map>
#include<iostream>
#include <vector>
#include"Piksel.h"
#include"Layer.h"
#include"GreskaPostojiKljuc.h"
//typedef std::vector<Layer*> mapa;
typedef std::map<int, Layer*> mapa;
class Image{
	//typedef std::vector<Layer> slojevi;
	mapa layers;
	int sirina, visina,brlejera;
	int brbitapopixelu;
	
public:
	Image(int s=0, int v=0,int b=0,int bbpp=0) {
		sirina = s;
		visina = v;
		brlejera = b;
		brbitapopixelu = bbpp;
	
	}
	// 1. funkcije za : prosirenje slike (realokacija svakog lejera, tj matrica u svakom lejeru), on prodje kroz sve lejere i u njima prosirenje pozove
	// prosledim novu velicinu u funkciju
	// 2. funkcija za dodavanje lejera, i ako je sirina i visina lejera veca od image sir i visine, onda
	// prosiriti sirinu i visinu u svim lejerima
	// tj ako dodas lejer koji je veci od ostalih, svi ostali moraju da porastu
	
	void DodajSloj( Layer* l,int pozicija) { 


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
		}		if (l->getSirina() < sirina) {
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
		}
		else {
			throw GreskaPostojiKljuc("Greska vec postoji dati layer");
		}

		//else { // ako je istih dimenzija samo dodam na kraj
		//	//layers.push_back(l);
		//	brlejera++;
		//}
		
	}
	Layer* konstruisiFinalniLayer() {
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
			Layer l = *(*i).second;
			layers[(*i).first] =&l;
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

		//PROBLEM S BRISANJEM ILI OK?
		for (auto i = layers.begin(); i != layers.end(); i++) {
			i = layers.erase(i);

		}

		sirina = 0;
		visina = 0;
		brlejera = 0;
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
