#pragma once
#include<iostream>

#include <vector>
#include<string>
#include"pamcitac.h"
#include"BMPcitac.h"
#include"Selekcija.h"
//typedef std::vector<Selekcija*> selekcije;
typedef std::vector<bool> aktivne;
class MeniZaSelekcije {
	//selekcije s ;
//	aktivne a;
public:
	MeniZaSelekcije() {
	//	s.clear();
	//	a.clear();
	}
	void UcitajSelekciju(Image* i) {
		std::cout << "Da li zelite da obrisete neku selekciju?" << std::endl;
		bool odgovor;
		std::cout << "1. Da" << std::endl;
		std::cout << "0. Ne" << std::endl;
		std::cin >> odgovor;
		if (odgovor) {
			std::string imesel;
			std::cout << "Unesite ime selekcije koju zelite da obrisete: " << std::endl;
			std::cin >> imesel;
			i->ObrisiSelekciju(imesel);
		}
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
			std::cout << "1. Ne" << std::endl;
			std::cout << "2. Da" << std::endl;
			std::cin >> dosta;
			Pravougaonik kvadrat(x, y, sir, vis);
			pp.push_back(kvadrat);
		} 
		std::cout << "Ime ove selekcije: " << std::endl;
		std::string ime;
		std::cin >> ime;
	//	Selekcija se(ime, pp);
		std::cout << "Aktivna ili neaktivna selekcija? " << std::endl;
		std::cout << "1. Aktivna   0. Neaktivna" << std::endl;
		bool stanje;
		std::cin >> stanje;
		i->dodajSelekciju(ime, pp, stanje);
		//a.push_back(stanje);
		//s.push_back(&se);	
	}
	~MeniZaSelekcije() {
		//s.clear();
	//	a.clear();
	}
};