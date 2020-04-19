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
	void ucitaj(std::string s) {
		std::ifstream binarnifajl;
		binarnifajl.open(s, std::ios::in | std::ios::binary);
		
	//	std::fstream citac(s, std::ios::binary|std::ios::in);
	//	if (!citac) {
	//		return;//greska
	//	}
		BMPzaglavlje bmpzaglavlje;
		binarnifajl.read((char*)&bmpzaglavlje, sizeof(bmpzaglavlje));
	//	std::cout << bmpzaglavlje.PocetakPiksela;
		bmpzaglavlje.zamenibitove();

		DIBzaglavlje dibzaglavlje;
		binarnifajl.read((char*)& dibzaglavlje, sizeof(dibzaglavlje));
		


		//dibzaglavlje.zamenibitove();
		//std::cout << dibzaglavlje.reserved4;
		//std::cout << (int)bmpzaglavlje.idpolje;
		//std::cout << dibzaglavlje.brBitaPoPixelu;
		std::cout << std::endl;
		long long pixel;
		bool state = 1;
		//std::fstream file("testiramo.bmp", std::ios::binary | std::ios::out);
		/*if (!file.is_open) {

		}*/
		bmpzaglavlje.zamenibitove();
		//bmpzaglavlje.idpolje = 0;
	//	file.write((char*)& bmpzaglavlje, sizeof(bmpzaglavlje));
	//	file.write((char*)& dibzaglavlje, sizeof(dibzaglavlje));
		//binarnifajl.seekg(bmpzaglavlje.PocetakPiksela);
		Layer l = Layer(dibzaglavlje.sirinaSlike, dibzaglavlje.visinaSlike);
		
		//for (int j = dibzaglavlje.visinaSlike-1; j >0 ; j--) { // obrnuto
		//	for (int i=0; i < dibzaglavlje.sirinaSlike; i++) {
		//		//char temp;
		//		//binarnifajl.read((char*)& temp, sizeof(temp));
		//		//char blue=temp;
		//		//binarnifajl.read((char*)& temp, sizeof(temp));
		//		//char green = temp;
		//		//binarnifajl.read((char*)& temp, sizeof(temp));
		//		//char red=temp;
		//		//binarnifajl.read((char*)& temp, sizeof(temp)); //00
		//		//
		//		//l.overwritepixel(i,j,Piksel(red,green,blue));
		//		if (dibzaglavlje.sirinaSlike % 2 == 1 && j % 2 == 1 && i == dibzaglavlje.sirinaSlike) {
		//			state = 0;
		//		}
		//		if (state) {
		//			//char temp;
		//			//binarnifajl.read((char*)& temp, sizeof(temp));
		//			binarnifajl.read((char*)& pixel, sizeof(pixel));
		//		//	file.write((char*)& pixel, sizeof(pixel));
		//			//std::cout << std::hex << pixel;
		//			pixel = _byteswap_uint64(pixel);
		//			char red1, green1, blue1;
		//			char red2, green2, blue2;
		//			blue1 = (pixel >> 56) & 0xFF;
		//			green1 = (pixel >> 48) & 0xFF;
		//			red1 = (pixel >> 40) & 0xFF;
		//			l.overwritepixel(i, j, Piksel(red1,green1 ,blue1, pixel & 0xFFFF));
		//			i++;
		//			blue2 = (pixel >> 32) & 0xFF;
		//			green2 = (pixel >> 24) & 0xFF;
		//			red2 = (pixel >> 16) & 0xFF;
		//			l.overwritepixel(i, j, Piksel(red2, green2, blue2,pixel&0xFFFF));
		//		}
		//		else {
		//			binarnifajl.read((char*)& pixel, sizeof(pixel));
		//			char red1, green1, blue1;
		//			char red2, green2, blue2;
		//			blue1 = (pixel >> 56) & 0xFF;
		//			green1 = (pixel >> 48) & 0xFF;
		//			red1 = (pixel >> 40) & 0xFF;
		//			l.overwritepixel(i, j, Piksel(red1, green1, blue1, pixel & 0xFFFF));
		//			blue2 = (pixel >> 32) & 0xFF;
		//			green2 = (pixel >> 24) & 0xFF;
		//			red2 = (pixel >> 16) & 0xFF;
		//			l.overwritepixel(0, j-1, Piksel(red2, green2, blue2, pixel & 0xFFFF));
		//			state = 1;

		//		}
		//	

		//	}
		//	
		//}
		
		for (int j = dibzaglavlje.visinaSlike - 1; j > 0; j--) { // obrnuto
			for (int i = 0; i < dibzaglavlje.sirinaSlike; i++) {
				char temp;
				binarnifajl.read((char*)& temp, sizeof(temp));
				char blue=temp;
				binarnifajl.read((char*)& temp, sizeof(temp));
				char green = temp;
				binarnifajl.read((char*)& temp, sizeof(temp));
				char red=temp;
				binarnifajl.read((char*)& temp, sizeof(temp));
				char opacity = temp;
				l.overwritepixel(i, j, Piksel(red, green, blue, 0,opacity));
				//l.overwritepixel(i, j, Piksel(red, green, blue, 0, 0)); 
			}
		}
		BMPwriter bmpwriter;
		Image i = Image(l.getSirina(), l.getvisina(), 1,dibzaglavlje.brBitaPoPixelu);
		Layer l22 = Layer(300, 150);
		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 150; j++) {
				l22.overwritepixel(i, j, Piksel(255, 0, 0));
			}
		}
		//i.DodajSloj(&l22, 0);
		//i.DodajSloj(&l, 4);
		i.DodajSloj(&l, 0);
		Layer* ll = i.konstruisiFinalniLayer();

		Image i1 = Image(300, 150, 1);
		i1.DodajSloj(&l22, 0);
		//bmpwriter.upisi(&i1);
		bmpwriter.upisi(&i);
	}
};