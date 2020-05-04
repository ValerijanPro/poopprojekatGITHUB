#pragma once

#include <iostream>

#include "tinyxml2.h"
#include <string>
#include"Image.h"
using namespace std;
using namespace tinyxml2;

class XMLIMAGEreader {
public:

	void ucitajXML(std::string str,Image* i) {

		XMLDocument doc;
		//doc.LoadFile("svekrva.xml");
		if (!PostojiFajl(str)) throw GreskaNemaFajla();
		doc.LoadFile(str.c_str());
		auto xmlImage = doc.FirstChildElement("Image");
		auto xmlLayers = xmlImage->FirstChildElement("Layers");
		auto xmlLayer = xmlLayers->FirstChildElement("Layer");
		
		int temp = 0;
		
		while (xmlLayer != nullptr && xmlLayer->ClosingType()!=xmlLayer->CLOSED) {
			int visina = xmlLayer->FindAttribute("Visina")->IntValue();
			int sirina = xmlLayer->FindAttribute("Sirina")->IntValue();
			int id = xmlLayer->FindAttribute("ID")->IntValue();
			std::shared_ptr<Layer> l = std::make_shared<Layer>(sirina, visina);
			auto xmlPixel = xmlLayer->FirstChildElement("Piksel");
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
			i->DodajSloj(l, id);
			xmlLayer = xmlLayer->NextSiblingElement();
		}
		auto xmlAktivne = xmlImage->FirstChildElement("Aktivne");
		auto xmlAktivan = xmlAktivne->FirstChildElement("StanjeLejera");
		while (xmlAktivan != nullptr) {
			int active = xmlAktivan->FindAttribute("aktivna")->IntValue();
			i->dodajAktivan(active);
			xmlAktivan = xmlAktivan->NextSiblingElement();
		}

		auto xmlSelekcije = xmlImage->FirstChildElement("Selekcije");
		auto xmlSelekcija = xmlSelekcije->FirstChildElement("Selekcija");
		while (xmlSelekcija != nullptr) {
			auto xmlPravougaonik = xmlSelekcija->FirstChildElement("Pravougaonik");
			std::string ime; bool stanje;
			ime = xmlSelekcija->FindAttribute("Ime")->Value();
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
		
		auto xmlOperacije = xmlImage->FirstChildElement("Operacije");
		bool medijana;
		medijana = xmlOperacije->FindAttribute("Medijana");
		i->setMedijana(medijana);
		
		auto xmlOperation = xmlOperacije->FirstChildElement("Operacija");
		while (xmlOperation != nullptr) {
			std::string ImeOperacije = xmlOperation->FindAttribute("ImeOperacije")->Value();
			int Vrednost = xmlOperation->FindAttribute("Value")->IntValue();
			if (ImeOperacije == "class Push") {
				i->dodajPush();

			}
			else if (ImeOperacije == "class Absolute") {

				i->DodajOperaciju(1, Vrednost);
			}
			else if (ImeOperacije == "class Add") {

				i->DodajOperaciju(2, Vrednost);
			}
			else if (ImeOperacije == "class Crnobela") {

				i->DodajOperaciju(3, Vrednost);
			}
			else if (ImeOperacije == "class Div") {

				i->DodajOperaciju(4, Vrednost);
			}
			else if (ImeOperacije == "class DivInvert") {

				i->DodajOperaciju(5, Vrednost);
			}
			else if (ImeOperacije == "class Inverzija") {

				i->DodajOperaciju(6, Vrednost);
			}
			else if (ImeOperacije == "class Log") {

				i->DodajOperaciju(7, Vrednost);
			}
			else if (ImeOperacije == "class Max") {

				i->DodajOperaciju(8, Vrednost);
			}
			else if (ImeOperacije == "class Min") {

				i->DodajOperaciju(9, Vrednost);
			}
			else if (ImeOperacije == "class Mul") {

				i->DodajOperaciju(10, Vrednost);
			}
			else if (ImeOperacije == "class Pow") {

				i->DodajOperaciju(11, Vrednost);
			}
			else if (ImeOperacije == "class Siva") {

				i->DodajOperaciju(12, Vrednost);
			}
			else if (ImeOperacije == "class Sub") {

				i->DodajOperaciju(13, Vrednost);
			}
			else if (ImeOperacije == "class SubInvert") {

				i->DodajOperaciju(14, Vrednost);
			}




			xmlOperation = xmlOperation->NextSiblingElement();
		}
			

		//return l;
	}
};
