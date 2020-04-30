#pragma once
#include<iostream>

#include <vector>
#include<string>
#include"pamcitac.h"
#include"BMPcitac.h"
#include"XMLIMAGEreader.h"
//TODO: NA PROIZVOLJNU POZICIJU UPISATI LEJER
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
			
			std::shared_ptr<Layer> p1=b.ucitaj(ImeSlike);
			//Layer* lejer = i->konstruisiFinalniLayer();
			std::cout << "Unesite poziciju na koju biste da upisete lejer: " << std::endl;
			int poz;
			std::cin >> poz;
			i->DodajSloj(p1, poz);
		//	i->DodajSloj(p1, i->getBrlejera());
			//std::cout << "opet";
		}
		else if (format == 2) {
			ImeSlike += ".pam";
			p = PamCitac();
			std::shared_ptr<Layer> p1 = p.ucitaj(ImeSlike);
			std::cout << "Unesite poziciju na koju biste da upisete lejer: " << std::endl;
			int poz;
			std::cin >> poz;
			i->DodajSloj(p1, poz);
			//i->DodajSloj(p1, i->getBrlejera());
		}
		else if (format==3){
			ImeSlike += ".xml";
			XMLIMAGEreader xml ;
		//	std::shared_ptr<Layer> p1=xml.ucitajXML(ImeSlike,i);
			std::cout << "Unesite poziciju na koju biste da upisete lejer: " << std::endl;
			int poz;
			std::cin >> poz;
			//i->DodajSloj(p1, poz);
			xml.ucitajXML(ImeSlike, i,poz);
			//i->DodajSloj(p1, i->getBrlejera());
		}
		return i;
	
	}
};