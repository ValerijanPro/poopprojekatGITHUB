#pragma once

#include <iostream>

#include "tinyxml2.h"
#include <string>
#include"Image.h"
using namespace std;
using namespace tinyxml2;

class XMLIMAGEreader {
public:

	void ucitajXML(std::string str,Image* i,int poz) {

		XMLDocument doc;
		//doc.LoadFile("svekrva.xml");
		doc.LoadFile(str.c_str());
		auto xmlImage = doc.FirstChildElement("Image");
		int visina = xmlImage->FindAttribute("Visina")->IntValue();
		int sirina = xmlImage->FindAttribute("Sirina")->IntValue();
		auto xmlLayer = xmlImage->FirstChildElement("Layer");
		auto xmlPixel = xmlLayer->FirstChildElement("Piksel");
		int temp = 0;
		std::shared_ptr<Layer> l = std::make_shared<Layer>(sirina, visina);
			while (xmlPixel != nullptr)
			{
				//temp++;
				int r = xmlPixel->FindAttribute("R")->IntValue();
				int g = xmlPixel->FindAttribute("G")->IntValue();
				int b = xmlPixel->FindAttribute("B")->IntValue();
				int a = xmlPixel->FindAttribute("Opacity")->IntValue();
				int offset = xmlPixel->FindAttribute("Offset")->IntValue();
				int x = xmlPixel->FindAttribute("I")->IntValue();
				int y = xmlPixel->FindAttribute("J")->IntValue();
				l->overwritepixel(y, x, Piksel(r, g, b, offset, a));
				// cout << r << " " << g << " " << b << " " << a << endl;
				/*if (temp == 1420417) {
					std::cout << "blabla";
				}*/
				xmlPixel = xmlPixel->NextSiblingElement();
				//xmlPixel = xmlLayer->NextSiblingElement();
			}
			i->DodajSloj(l, poz);
			auto xmlSelekcija = xmlImage->FirstChildElement("Selekcija");
			while (xmlSelekcija != nullptr) {
				auto xmlPravougaonik = xmlSelekcija->FirstChildElement("Pravougaonik");
				std::string ime; bool stanje;
				ime = xmlSelekcija->FindAttribute("Ime")->Name();
				stanje = xmlSelekcija->FindAttribute("Aktivna")->BoolValue();
				pravougaonici pp;
				pp.clear();
				while (xmlPravougaonik != nullptr) {
					int X = xmlPravougaonik->FindAttribute("X")->IntValue();
					int Y = xmlPravougaonik->FindAttribute("Y")->IntValue();
					int SIR = xmlPravougaonik->FindAttribute("sirina")->IntValue();
					int VIS = xmlPravougaonik->FindAttribute("visina")->IntValue();
					pp.push_back(Pravougaonik(X, Y, SIR, VIS));
					xmlPravougaonik = xmlPravougaonik->NextSiblingElement();
				}
				i->dodajSelekciju(ime, pp, stanje);
				xmlSelekcija = xmlSelekcija->NextSiblingElement();
			}
			

		//return l;
	}
};
