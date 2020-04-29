#pragma once
#include <iostream>

#include "tinyxml2.h"
#include <string>
#include"Image.h"
using namespace std;
using namespace tinyxml2;

class XMLIMAGEwriter {

public:
	void ispisiXML(std::string s, Image* image) {
		ofstream myfile;
		myfile.open(s+".xml");
		
		std::cout << "Koji lejeri ce ucestovati u formiranju slike? (Napisite -1 za kraj)" << std::endl;
		int xx = 10; aktivni ak; ak.clear();
		while (1) {
			std::cin >> xx;
			if (xx == -1) break;
			ak.push_back(xx);
		}
		image->setAkt(ak);
	//	std::shared_ptr<Layer>  lejer = image->konstruisiFinalniLayer(ak);


		XMLPrinter printer;

		int visina = image->getvisina();
		int sirina = image->getSirina();
		int brbitapopixelu=image->getBrBitaPoPixelu();



		printer.OpenElement("Image");
		printer.PushAttribute("Visina", visina);
		printer.PushAttribute("Sirina", sirina);
		printer.PushAttribute("Brbitapopixelu", brbitapopixelu);
		for (auto lejer: image->getLayers())
		{
			printer.OpenElement("Layer");
			printer.PushAttribute("Sirina", sirina );
			printer.PushAttribute("Visina", visina);
			//lejer.second->
			for (int h = 0; h < visina; h++)
			{
				for (int w = 0; w < sirina; w++)
				{
					printer.OpenElement("Piksel");
					printer.PushAttribute("R", lejer.second->getPixel(w, h).getR());
					printer.PushAttribute("G", lejer.second->getPixel(w, h).getG());
					printer.PushAttribute("B", lejer.second->getPixel(w, h).getB());
					printer.PushAttribute("Opacity", lejer.second->getPixel(w, h).getOpacity());
					printer.PushAttribute("Offset", lejer.second->getPixel(w, h).getOffset());
					printer.CloseElement();
				}
			}
			printer.CloseElement();
		}


		for (auto selekcija : image->getSelekcije()) {
			printer.OpenElement("Selekcija");
			printer.PushAttribute("Ime", selekcija.getIme().c_str());
			printer.PushAttribute("Aktivna", selekcija.getStanje());
			for (auto w : selekcija.getNiz()) {
				printer.OpenElement("Pravougaonik");
				printer.PushAttribute("X", w.getX());
				printer.PushAttribute("Y", w.getY());
				printer.PushAttribute("sirina", w.getSirina());
				printer.PushAttribute("visina", w.getVisina());
				printer.CloseElement();
			}
			printer.CloseElement();
		}
		for (auto active : image->getAkt()) {
			printer.OpenElement("StanjeLejera");
			
			printer.PushAttribute("aktivna", active);
			printer.CloseElement();
		}
		for (auto operacija : image->getOperacije()) {
			printer.OpenElement("Operacija");
			printer.PushAttribute("Ime operacije:", typeid(*operacija).name());
			printer.PushAttribute("Value:", operacija->getValue());
			printer.CloseElement();
		}
	


		printer.CloseElement();

		string text = printer.CStr();
		myfile << text;
		myfile.close();
		//file.write(printer.CStr(), sizeof(printer.CStr()));
	//	std::cout << text;


	}
};