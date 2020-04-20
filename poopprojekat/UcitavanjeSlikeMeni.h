#pragma once
#include<iostream>

#include <vector>
#include<string>
#include"pamcitac.h"
#include"BMPcitac.h"
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
		std::cout << "0. Nazad na MainMenu" << std::endl;
		//std::cin >> ImeSlike;
	}
	void UcitajFormat() {
		PrintFormati();
		std::cin >> format;
	}
	void UcitajSliku() {
		std::cout << "Unesite ime slike, bez ekstenzije" << std::endl;
		std::cin >> ImeSlike;
		if (format == 1) {
			ImeSlike += ".bmp";
			b = BMPcitac();
			b.ucitaj(ImeSlike);
		}
		else if (format == 2) {
			ImeSlike += ".pam";
			p = PamCitac();
			p.ucitaj(ImeSlike);
		}
		else {

		}

	
	}
};