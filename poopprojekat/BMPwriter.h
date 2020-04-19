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
#include"DIBzaglavlje1.h"
#include"BMPzaglavlje1.h"
class BMPwriter {
public:
	//void upisi(int velBMPfajla,int sirina,int visina,int velbitmape) {
	void upisi(Image* i) {
		std::fstream file("testiram.bmp", std::ios::binary | std::ios::out);
		//if (!file.is_open) {
			//gresku napraviti
		//}
		Layer* lejer = i->konstruisiFinalniLayer();
		
		// testiramo
		//Pravougaonik kvadrat1 = Pravougaonik(0, 0, 400, 300);
		Pravougaonik kvadrat2 = Pravougaonik(0, 300, 800 , 200);
		//Pravougaonik kvadrat3 = Pravougaonik(0, 0, 750, 450);
		pravougaonici pp;
		/*pp.push_back(kvadrat1);
		pp.push_back(kvadrat2);*/
		//pp.push_back(kvadrat1);
		pp.push_back(kvadrat2);
		//pp.push_back(kvadrat3);
		Selekcija se = Selekcija("Nekatamo", pp);

		//testiramo
		/*DIBzaglavlje dibzaglavlje = DIBzaglavlje(lejer->getSirina(), lejer->getvisina(), lejer->getSirina()* lejer->getvisina());
		dibzaglavlje.brBitaPoPixelu = brbitovapopix;*/
		/*DIBzaglavlje1 dibzaglavlje = DIBzaglavlje1(lejer->getSirina(), lejer->getvisina(), lejer->getSirina() * lejer->getvisina());
		dibzaglavlje.brBitaPoPixelu = brbitovapopix;*/

		DIBzaglavlje dibzaglavlje = DIBzaglavlje(lejer->getSirina(), lejer->getvisina(), lejer->getSirina()* lejer->getvisina()*3);
		dibzaglavlje.brBitaPoPixelu = i->getBrBitaPoPixelu();
		//dibzaglavlje.brBitaPoPixelu = ;
		//BMPzaglavlje bmpzaglavlje = BMPzaglavlje(lejer->getSirina() * lejer->getvisina()+54);
	/*	BMPzaglavlje1 bmpzaglavlje = BMPzaglavlje1(lejer->getSirina() * lejer->getvisina()*3+122); */
		BMPzaglavlje bmpzaglavlje = BMPzaglavlje(lejer->getSirina() * lejer->getvisina()*3 + 56);
		//bmpzaglavlje.zamenibitove();
		//bmpzaglavlje.zamenibitove();
	//	dibzaglavlje.zamenibitove();
		file.write((char*)& bmpzaglavlje, sizeof(bmpzaglavlje));
		file.write((char*)& dibzaglavlje, sizeof(dibzaglavlje));
		

		bool state = 1;
		Piksel p2;
		int print = 0;
		int x=0, y=0;
		int paja = 0;
		for (int j = dibzaglavlje.visinaSlike - 1; j >= 0; j--) { // obrnuto
			for (int i = 0; i < dibzaglavlje.sirinaSlike; i++) {
				
				/*if (dibzaglavlje.sirinaSlike % 2 == 1 && j % 2 == 1 && i == dibzaglavlje.sirinaSlike) {
					state = 0;
				}
				char temp;
				*/
				Piksel* p1 = &lejer->getPixel(i, j);
				//p1->crnobela();
				
				if (se.USelekciji(i,j)) {
				//	std::cout <<j<<", "<< i<<std::endl;
					print++;
					p1->oboji(0xFF, 0xFF, 0xFF);
				}
				
				char temp;
				
				temp = p1->getB(); 
				//if (print)
				//std::cout <<"B:"<< (int)temp;
				file.write((char*)& temp, sizeof(temp));
				temp = p1->getG();
				//if (print)
				//std::cout << "G:" << (int)temp;
				file.write((char*)& temp, sizeof(temp));
				temp = p1->getR();
				//if (print)
				//std::cout << "R:" << (int)temp;
				file.write((char*)& temp, sizeof(temp));
				paja++;
				x = i;
				y = j;
		
				temp = p1->getOpacity();
				//temp = 200;
				file.write((char*)& temp, sizeof(temp));
				
				//if (!state) {
				//	short temp = p1->getOffset();
				//	temp = zamenitempbitove16(temp);
				//	file.write((char*)& temp, sizeof(temp));
				//	paja++;
				//	/*temp = 255;
				//	file.write((char*)& temp, sizeof(temp));
				//	state = 1;*/
				//	state = 1;
				//}
				//else {
				//	
				//	state = 0;
				//}

				//if (state) {
				//	state = 0;
				//	Piksel p1 = lejer->getPixel(i, j);
				//	i++;
				//	Piksel p2 = lejer->getPixel(i, j);
				//	long long upis = (p1.getB() << 56) | (p1.getG() << 48) | (p1.getR() << 40) | (p2.getB() << 32) | (p2.getG() << 24) | (p2.getR() << 16);
				//	file.write((char*)& upis, sizeof(upis));
				//	//binarnifajl.read((char*)& pixel, sizeof(pixel));
				//	//	file.write((char*)& pixel, sizeof(pixel));
				//		//std::cout << std::hex << pixel;
				////	pixel = _byteswap_uint64(pixel);

				//	//std::cout << std::hex << pixel;
				////	l.overwritepixel(i, j, Piksel(pixel >> 56, (pixel >> 48) & 0xFF, (pixel >> 40) & 0xFF));
				//	i++;
				////	l.overwritepixel(i, j, Piksel((pixel >> 32) & 0xFF, (pixel >> 24) & 0xFF, (pixel >> 16) & 0xFF));
				//}
				//else {
				////	binarnifajl.read((char*)& pixel, sizeof(pixel));

				////	pixel = _byteswap_uint64(pixel);
				////	l.overwritepixel(i, j, Piksel(pixel >> 56, (pixel >> 48) & 0xFF, (pixel >> 40) & 0xFF));
				//	i = 0;
				////	l.overwritepixel(i, j, Piksel((pixel >> 32) & 0xFF, (pixel >> 24) & 0xFF, (pixel >> 16) & 0xFF));
				//	state = 1;

				//}


			}

		}
	/*	while (paja < 45000) {
			paja++;
			char temp;
			temp = p2.getB();
			file.write((char*)& temp, sizeof(temp));
			temp = p2.getG();
			file.write((char*)& temp, sizeof(temp));
			temp = p2.getR();
			file.write((char*)& temp, sizeof(temp));
		}
				*/
		std::cout << print;
		std::cout << paja;

	}
};