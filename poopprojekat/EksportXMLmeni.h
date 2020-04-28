#pragma once

#include<iostream>

#include <vector>
#include<memory>
#include<string>
#include"Image.h"
#include"Timotije.h"
#include"XMLwriter.h"

class EksportXMLmeni {
public:
	Image* ucitajImeFajla(Image* image){
		std::cout << "Unesite ime izlaznog xml fajla: " << std::endl;
		std::string s;
		std::cin >> s;
		XMLwriter xml;
		xml.ispisiXML(s, image);
		return image;
	}

};