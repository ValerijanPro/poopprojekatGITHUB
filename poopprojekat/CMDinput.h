#pragma once
#include<map>
#include<iostream>
#include<fstream>
#include <vector>
#include"BMPzaglavlje.h"
#include"DIBzaglavlje.h"
#include"NizPiksela.h"
#include"BMPwriter.h"
#include"XMLOPERATIONreader.h"
class CMDinput {
public:
	Image* ucitaj(std::string ImeSlike, std::string ImeOperacija) {
		Image* slika = new Image();
		slika->getOperacije().clear();
		if (SeZavrsavaSa(ImeSlike, ".BMP")) {
		
			BMPcitac b = BMPcitac();

			std::shared_ptr<Layer> p1 = b.ucitaj(ImeSlike);
			
			
			slika->DodajSloj(p1, slika->getBrlejera());
			XMLOPERATIONreader op;
			op.ucitajXML(ImeOperacija, slika);
			XMLOPERATIONwriter op1;
			op1.ispisiXML("BOLE", slika);
		}
		else if (SeZavrsavaSa(ImeSlike, ".PAM")) {
		
			PamCitac p = PamCitac();
			std::shared_ptr<Layer> p1 = p.ucitaj(ImeSlike);
			
			slika->DodajSloj(p1, slika->getBrlejera());
			XMLOPERATIONreader op;
			op.ucitajXML(ImeOperacija, slika);
		}
		else if (SeZavrsavaSa(ImeSlike, ".xml")) {
			ImeSlike += ".xml";
			XMLIMAGEreader xml;
			//	std::shared_ptr<Layer> p1=xml.ucitajXML(ImeSlike,i);
		
			//i->DodajSloj(p1, poz);
			xml.ucitajXML(ImeSlike, slika, slika->getBrlejera());
			XMLOPERATIONreader op;
			op.ucitajXML(ImeOperacija, slika);
		}
		else {
			//greska;
		}
		return slika;
	}
	
};