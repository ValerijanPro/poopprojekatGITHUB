#pragma once
#include<iostream>

#include <vector>
#include<string>
#include"pamcitac.h"
#include"BMPcitac.h"
class IspisSlikeMeni {
	std::string imeFajla;
	int format;
	BMPwriter b;
	PAMwriter p;
public:
	int getFormat()const { return format; }
	void IspisiSliku(Image* i) {
		std::cout << "Izaberite format u kom zelite da ispisete sliku: " << std::endl;
		std::cout << "1. BMP" << std::endl;
		std::cout << "2. PAM" << std::endl;
	
		std::cout << " 0. Nazad na Glavni Meni" << std::endl;
		std::cin >> format;
		if (format !=1 && format!=2 ) throw GreskaFormatFajla() ; // THROW GRESKA
		std::cout << "Unesite ime izlaznog fajla bez ekstenzije: " << std::endl;
		std::cin >> imeFajla;
		if (format == 1) {
			imeFajla += ".bmp";
			b = BMPwriter();
			b.ucitajAtributeMeni();
			b.upisi(i,imeFajla);
		}
		else if (format == 2) {
			imeFajla += ".pam";
			p = PAMwriter();
			p.ucitajAtributeMeni();
			p.upisi(i,imeFajla);
		}
		
	}
};