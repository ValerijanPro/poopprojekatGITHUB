
#pragma once
#include <iostream>

#include "tinyxml2.h"
#include <string>
#include"Image.h"
using namespace std;
using namespace tinyxml2;

class XMLOPERATIONwriter {

public:
	void ispisiXML(std::string s, Image* image) {
		ofstream myfile;
		myfile.open(s);

		


		XMLPrinter printer;

		printer.OpenElement("Operacije");
		printer.PushAttribute("Medijana", image->getMedijana());
		for (auto operacija : image->getOperacije()) {
			printer.OpenElement("Operacija");
			printer.PushAttribute("ImeOperacije", typeid(*operacija).name());
			printer.PushAttribute("Value", operacija->getValue());
			printer.CloseElement();
		}

		printer.CloseElement();

		//printer.CloseElement();

		string text = printer.CStr();
		myfile << text;
		myfile.close();
		//file.write(printer.CStr(), sizeof(printer.CStr()));
	//	std::cout << text;


	}
};