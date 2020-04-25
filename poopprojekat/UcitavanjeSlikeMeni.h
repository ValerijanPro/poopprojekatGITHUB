#pragma once
#include<iostream>

#include <vector>
#include<string>
#include"pamcitac.h"
#include"BMPcitac.h"
class UcitavanjeSlikeMeni  {
	std::string ImeSlike;
	int format; // 1 BMP, 2 PAM, 3 image
	BMPcitac b;
	PamCitac p;
public:
	int getFormat()const { return format; }
	void PrintFormati() {
		std::cout << "Izaberite format slike koji zelite: " << std::endl;
		std::cout << "1.BMP" << std::endl;
		std::cout << "2.PAM" << std::endl;
		std::cout << "3.Image" << std::endl;
		std::cout << "0. Nazad na Glavni Meni" << std::endl;
		//std::cin >> ImeSlike;
	}
	void UcitajFormat() {
		PrintFormati();
		std::cin >> format;
	}
	Image* UcitajSliku(Image* i) {
		//Image* i=new Image();
		std::cout << "Unesite ime slike, bez ekstenzije" << std::endl;
		std::cin >> ImeSlike;
		if (format == 1) {
			ImeSlike += ".bmp";
			b = BMPcitac();
			Layer* l = b.ucitaj(ImeSlike,i);
			//if (i->getSirina() == 0 && i->getvisina() == 0) {
			//	//delete i;
			//	i= new Image(l->getSirina(), l->getvisina(), i->getBrBitaPoPixelu());
				
			//}
			//i->DodajSloj(l, i->getBrlejera());
			//i=b.ucitaj(ImeSlike);
			//Layer* lejer = i->konstruisiFinalniLayer();
			//std::cout << "opet";
		}
		else if (format == 2) {
			ImeSlike += ".pam";
			p = PamCitac();
			//i=p.ucitaj(ImeSlike);
			Layer* l = p.ucitaj(ImeSlike, i);
			if (i->getSirina() == 0 && i->getvisina() == 0) {
				//delete i;
				i = new Image(l->getSirina(), l->getvisina(), i->getBrBitaPoPixelu());

			}
			i->DodajSloj(l, i->getBrlejera());
		}
		else {

		}
		return i;
	
	}
};