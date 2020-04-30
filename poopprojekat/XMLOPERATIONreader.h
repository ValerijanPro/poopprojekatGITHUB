#pragma once
#include <iostream>

#include "tinyxml2.h"
#include <string>
#include"Image.h"
using namespace std;
using namespace tinyxml2;

class XMLOPERATIONreader {
public:
	void ucitajXML(std::string str, Image* image) {


		XMLDocument doc;
		//doc.LoadFile("svekrva.xml");
		doc.LoadFile(str.c_str());
		auto xmlOperation = doc.FirstChildElement("Operacija");
		while (xmlOperation != nullptr) {
			std::string ImeOperacije = xmlOperation->FindAttribute("ImeOperacije")->Name();
			int Vrednost = xmlOperation->FindAttribute("Value")->IntValue();
			if (ImeOperacije=="class Push") {
				image->dodajPush();
				
			}
			else if (ImeOperacije == "class Absolute") {
			
				image->DodajOperaciju(1, Vrednost);
			}
			else if (ImeOperacije == "class Add") {

				image->DodajOperaciju(2, Vrednost);
			}
			else if (ImeOperacije == "class Crnobela") {

				image->DodajOperaciju(3, Vrednost);
			}
			else if (ImeOperacije == "class Div") {

				image->DodajOperaciju(4, Vrednost);
			}
			else if (ImeOperacije == "class DivInvert") {

				image->DodajOperaciju(5, Vrednost);
			}
			else if (ImeOperacije == "class Inverzija") {

				image->DodajOperaciju(6, Vrednost);
			}
			else if (ImeOperacije == "class Log") {

				image->DodajOperaciju(7, Vrednost);
			}
			else if (ImeOperacije == "class Max") {

				image->DodajOperaciju(8, Vrednost);
			}
			else if (ImeOperacije == "class Min") {

				image->DodajOperaciju(9, Vrednost);
			}
			else if (ImeOperacije == "class Mul") {

				image->DodajOperaciju(10, Vrednost);
			}
			else if (ImeOperacije == "class Pow") {

				image->DodajOperaciju(11, Vrednost);
			}
			else if (ImeOperacije == "class Siva") {

				image->DodajOperaciju(12, Vrednost);
			}
			else if (ImeOperacije == "class Sub") {

				image->DodajOperaciju(13, Vrednost);
			}
			else if (ImeOperacije == "class SubInvert") {

				image->DodajOperaciju(14, Vrednost);
			}
			
				
			

			xmlOperation = xmlOperation->NextSiblingElement();
		}
	}
};