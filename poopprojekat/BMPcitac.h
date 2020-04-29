#pragma once
#include<map>
#include<iostream>
#include<fstream>
#include <vector>
#include"BMPzaglavlje.h"
#include"DIBzaglavlje.h"
#include"NizPiksela.h"
#include"BMPwriter.h"
class BMPcitac {
public:
	std::shared_ptr<Layer> ucitaj(std::string s) {
		std::ifstream binarnifajl;
		binarnifajl.open(s, std::ios::in | std::ios::binary);

		//rade: RAY, MARBLES,RED SKORO, YEL SKORO,BLU SKORO, BLK, FLAG_B24 
		// NE: venus, wht, LAND 123,
	//	std::fstream citac(s, std::ios::binary|std::ios::in);
	//	if (!citac) {
	//		return;//greska
	//	}
		BMPzaglavlje1 bmpzaglavlje;
		binarnifajl.read((char*)&bmpzaglavlje, sizeof(bmpzaglavlje));

		bmpzaglavlje.zamenibitove();

		DIBzaglavlje1 dibzaglavlje;
		binarnifajl.read((char*)& dibzaglavlje, sizeof(dibzaglavlje));


		long long pixel;
		bool state = 1;

		bmpzaglavlje.zamenibitove();
		binarnifajl.seekg(bmpzaglavlje.PocetakPiksela,0);
		//Layer* l = new Layer(dibzaglavlje.sirinaSlike, dibzaglavlje.visinaSlike);
		std::shared_ptr<Layer> l = std::make_shared<Layer>(dibzaglavlje.sirinaSlike, dibzaglavlje.visinaSlike);
		if (dibzaglavlje.brBitaPoPixelu == 32) {
			for (int j = dibzaglavlje.visinaSlike - 1; j > 0; j--) { // ako je 32
				int i = 0;
				for (i = 0; i < dibzaglavlje.sirinaSlike; i++) {
					char temp;
					binarnifajl.read((char*)& temp, sizeof(temp));
					char blue = temp;
					binarnifajl.read((char*)& temp, sizeof(temp));
					char green = temp;
					binarnifajl.read((char*)& temp, sizeof(temp));
					char red = temp;
					binarnifajl.read((char*)& temp, sizeof(temp));
					char opacity = temp;
					l->overwritepixel(i, j, Piksel(red, green, blue, 0, opacity));

				}
				while ((i % 4) != 0) {
					char temp;
					binarnifajl.read((char*)& temp, sizeof(temp));
					i++;
				}

				//jos kolko padinga ima
			}
		}
		else if (dibzaglavlje.brBitaPoPixelu == 24) {
			for (int j = dibzaglavlje.visinaSlike - 1; j > 0; j--) { // ako je 32
				int i = 0;
				for (i = 0; i < dibzaglavlje.sirinaSlike; i++) {
					char temp;
					binarnifajl.read((char*)& temp, sizeof(temp));
					char blue = temp;
					binarnifajl.read((char*)& temp, sizeof(temp));
					char green = temp;
					binarnifajl.read((char*)& temp, sizeof(temp));
					char red = temp;
				
					l->overwritepixel(i, j, Piksel(red, green, blue, 0, 127));

				}
				while ((i % 4) != 0) {
					char temp;
					binarnifajl.read((char*)& temp, sizeof(temp));
					binarnifajl.read((char*)& temp, sizeof(temp));
					binarnifajl.read((char*)& temp, sizeof(temp));
					i++;
				}

				//jos kolko padinga ima
			}
		}
		return l;
		//BMPwriter bmpwriter;
		//Image *i = new Image(l->getSirina(), l->getvisina(), 1,dibzaglavlje.brBitaPoPixelu);
		////Image* i = (Image*)malloc(sizeof(Image*));

		////Layer* lej = (Layer*)malloc(sizeof(Layer));
		////lej = &l;
		//i->DodajSloj(l, 0);
		//Layer* lejer = i->konstruisiFinalniLayer();
		//return i;

	//	bmpwriter.upisi(&i);
	}
};