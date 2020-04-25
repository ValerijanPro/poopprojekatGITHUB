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
	Layer* ucitaj(std::string s,Image* ii) {
		std::ifstream binarnifajl;
		binarnifajl.open(s, std::ios::in | std::ios::binary);
		
	//	std::fstream citac(s, std::ios::binary|std::ios::in);
	//	if (!citac) {
	//		return;//greska
	//	}
		BMPzaglavlje bmpzaglavlje;
		binarnifajl.read((char*)&bmpzaglavlje, sizeof(bmpzaglavlje));

		bmpzaglavlje.zamenibitove();

		DIBzaglavlje dibzaglavlje;
		binarnifajl.read((char*)& dibzaglavlje, sizeof(dibzaglavlje));


		long long pixel;
		bool state = 1;

		bmpzaglavlje.zamenibitove();

		Layer* l = new Layer(dibzaglavlje.sirinaSlike, dibzaglavlje.visinaSlike);

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
				
					l->overwritepixel(i, j, Piksel(red, green, blue, 0, 255));

				}
				while ((i % 4) != 0) {
					char temp;
					binarnifajl.read((char*)& temp, sizeof(temp));
					i++;
				}

				//jos kolko padinga ima
			}
		}
		
		//BMPwriter bmpwriter;
//		Image *i = new Image(l->getSirina(), l->getvisina(), 1,dibzaglavlje.brBitaPoPixelu);
		//Image* i = (Image*)malloc(sizeof(Image*));
		Image* i = new Image(l->getSirina(), l->getvisina(), dibzaglavlje.brBitaPoPixelu);
	//	Image* i = (Image*)malloc(sizeof(Image*));
		i->DodajSloj(l, 0);
		ii->setBrBitaPoPixelu(dibzaglavlje.brBitaPoPixelu);
		ii->DodajSloj(l, 0);
		return l;
		//Layer* lej = (Layer*)malloc(sizeof(Layer));
		//lej = &l;
		
	/*	i->DodajSloj(l, 0);
		Layer* lejer = i->konstruisiFinalniLayer();
		return i;*/


	//	bmpwriter.upisi(&i);
	}
};