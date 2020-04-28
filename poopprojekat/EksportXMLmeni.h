#pragma once

#include<iostream>

#include <vector>
#include<memory>
#include<string>
#include"Image.h"
#include"Timotije.h"
#include"XMLIMAGEwriter.h"
#include"XMLOPERATIONwriter.h"
class EksportXMLmeni {
public:
	Image* ucitajImeFajla(Image* image){
		std::cout << "Unesite ime izlaznog xml fajla: " << std::endl;
		std::string s;
		std::cin >> s;
		XMLIMAGEwriter xml;
		xml.ispisiXML(s, image);
		return image;
	}
	Image* ucitajImeFajlaZaOperacije(Image* image) {
		std::cout << "Unesite ime izlaznog xml fajla: " << std::endl;
		std::string s;
		std::cin >> s;
		XMLOPERATIONwriter xml;
		xml.ispisiXML(s, image);
		return image;
	}
};