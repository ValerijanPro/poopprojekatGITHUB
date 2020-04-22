#pragma once
#include<iostream>

#include <vector>
#include<string>
#include"pamcitac.h"
#include"BMPcitac.h"
#include"Selekcija.h"
typedef std::vector<Selekcija*> selekcije; // ovo treba u image da postoji, da bi se poslalo u writer
typedef std::vector<bool> aktivne; //vec u selekciji imam da li je aktivna
class MeniZaSelekcije {
	
	aktivne a;
public:
	MeniZaSelekcije() {
		//s.clear();

		a.clear();
	}
	void UcitajSelekciju(Image* i) {
		int dosta = 1;
		pravougaonici pp;
		std::cout << "Unesite redom pravougaonike jedne selekcije: "<<std::endl;
		while (dosta!=2) {
			int x, y, sir, vis;
			std::cout << "Koordinate gornjeg levog ugla pravougaonika: " << std::endl;
			std::cin >> x;
			std::cin >> y;
			std::cout << "Sirina pravougaonika: " << std::endl;
			std::cin >> sir;
			std::cout << "Visina pravougaonika: " << std::endl;
			std::cin >> vis;
			std::cout << "Kraj ove selekcije? " << std::endl;
			std::cout << "1. Da" << std::endl;
			std::cout << "2. Ne" << std::endl;
			std::cin >> dosta;
			Pravougaonik kvadrat(x, y, sir, vis);
			pp.push_back(kvadrat);
		} 
		std::cout << "Ime ove selekcije: " << std::endl;
		std::string ime;
		std::cin >> ime;
		Selekcija se(ime, pp);
		std::cout << "Aktivna ili neaktivna selekcija? " << std::endl;
		std::cout << "1. Aktivna   0. Neaktivna" << std::endl;
		bool stanje;
		std::cin >> stanje;
		i->dodajSelekciju(ime,pp,stanje);
	}

	~MeniZaSelekcije() {
	//	s.clear();
		a.clear();
	}
};