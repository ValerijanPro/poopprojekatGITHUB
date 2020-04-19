#pragma once
#include<map>
#include<iostream>
#include<fstream>
#include <vector>
#include"BMPzaglavlje.h"
#include"DIBzaglavlje.h"
#include"NizPiksela.h"
#include"Image.h"
#include"Selekcija.h"
#include"Pravougaonik.h"

#include"pamcitac.h"

#pragma pack(push, 1)
struct PamHeder {
	std::string magicNumber;
	std::string sirina;
	std::string visina;
	std::string dubina;
	std::string maxval;
	std::string tupltype;
	std::string endhdr;
	PamHeder(int sir = 0, int vis = 0) {

		magicNumber = "P7\n";
		sirina = "WIDTH "; 
		std::string stringsirina = std::to_string(sir);
		for (int i = 0; i < stringsirina.length(); i++) {
			sirina.push_back(stringsirina[i]);

		}
		sirina.push_back('\n');
		visina = "HEIGHT ";
		std::string stringvisina = std::to_string(vis);
		for (int i = 0; i < stringvisina.length(); i++) {
			visina.push_back(stringvisina[i]);

		}
		visina.push_back('\n');
		int nula = 0;
		dubina = "DEPTH ";
		dubina.push_back((char)(3+48));
		dubina.push_back('\n');
		
		maxval = "MAXVAL ";
		maxval.push_back((char)(2+48));
		maxval.push_back((char)(5 + 48));
		maxval.push_back((char)(5 + 48));
		maxval.push_back('\n');
		tupltype = "TUPLTYPE RGB\n";
		endhdr = "ENDHDR\n";
	}

};




#pragma pack(pop)