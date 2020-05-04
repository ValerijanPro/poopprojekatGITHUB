#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<map>
#include<iostream>
#include<fstream>
#include <vector>
#include"BMPzaglavlje.h"
#include"DIBzaglavlje.h"
//#include"NizPiksela.h"
#include"BMPwriter.h"
#include"korisno.h"
#include"pamwriter.h"
#include"pamheder.h"
#pragma pack(push, 1)

class PamCitac {
public: 
	std::shared_ptr<Layer> ucitaj(std::string s) {


		std::ifstream binarnifajl;

		if (!PostojiFajl(s)) throw GreskaNemaFajla();
		binarnifajl.open(s.c_str(), std::ios::in | std::ios::binary);
		PamHeder pamheder=PamHeder();
		
		std::getline(binarnifajl, pamheder.magicNumber);
		std::getline(binarnifajl, pamheder.sirina);
		std::getline(binarnifajl, pamheder.visina);
		std::getline(binarnifajl, pamheder.dubina);
		std::getline(binarnifajl, pamheder.maxval);
		std::getline(binarnifajl, pamheder.tupltype);
		if (pamheder.tupltype == "ENDHDR") {
			pamheder.endhdr = pamheder.tupltype;
			pamheder.tupltype = "";
		}
		else {
			std::getline(binarnifajl, pamheder.endhdr);
		}
		int visina, sirina,brbajtova,maxval,dubina;
		visina = GetBroj(pamheder.visina);
		sirina = GetBroj(pamheder.sirina);
		maxval = GetBroj(pamheder.maxval);
		brbajtova = BrBajtova(maxval);
		dubina = GetBroj(pamheder.dubina);
		std::shared_ptr<Layer> l = std::make_shared<Layer>(sirina, visina);
		int paja = 0;
		std::cout << binarnifajl.width();
		//binarnifajl.seekg(66968);
		if (brbajtova == 1) {//1 bajt po boji
			if (dubina == 3) {
				for (int j = 0; j < visina; j++) { // uslovi za dubinu za citanje OK !
					for (int i = 0; i < sirina; i++) {
						uint8_t temp;
						paja++;
						if (paja <= 66967) {
							//std::cout << "paja";
						}
						//if (paja % 50000==0) binarnifajl.seekg(binarnifajl.tellg(),binarnifajl._Seekbeg);
						binarnifajl.read((char*)& temp, sizeof(temp));
						
						temp = SkalirajNa(temp, maxval, 255);
						char red = temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = SkalirajNa(temp, maxval, 255);
						char green = temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = SkalirajNa(temp, maxval, 255);
						char blue = temp;
						//binarnifajl.read((char*)& temp, sizeof(temp));
						/*	char opacity = temp;*/
						l->overwritepixel(i, j, Piksel(red, green, blue, 0, 255));
					}
				}
			}
			else if (dubina == 4) {
				for (int j = 0; j <visina; j++) { // uslovi za dubinu za citanje OK !
					for (int i = 0; i < sirina; i++) {
						char temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = SkalirajNa(temp, maxval, 255);
						char blue = temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = SkalirajNa(temp, maxval, 255);
						char green = temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = SkalirajNa(temp, maxval, 255);
						char red = temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = SkalirajNa(temp, maxval, 255);
						char opacity = temp;
						l->overwritepixel(i, j, Piksel(red, green, blue, 0, opacity));
					}
				}
			}

			else if (dubina==1){// kad je crnobelo
				for (int j = 0; j< visina; j++) { 
					for (int i = 0; i < sirina; i++) {
						char temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = SkalirajNa(temp, maxval, 255);
						//binarnifajl.read((char*)& temp, sizeof(temp));
						/*	char opacity = temp;*/
						if(temp==0)
							l->overwritepixel(i, j, Piksel(0, 0, 0, 0, 0));
						else {
							l->overwritepixel(i, j, Piksel(255, 255, 255, 0, 255));
						}
					}
				}
			} 
			else if (dubina == 2) { //crnobelo sa opacity
				for (int j = 0; j <visina; j++) { 
					for (int i = 0; i < sirina; i++) {
						char temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = SkalirajNa(temp, maxval, 255);
						
						char opacity;
						binarnifajl.read((char*)& opacity, sizeof(opacity));
						temp = SkalirajNa(temp, maxval, 255);
						if (temp == 0)
							l->overwritepixel(i, j, Piksel(0, 0, 0, 0, opacity));
						else {
							l->overwritepixel(i, j, Piksel(255, 255, 255, 0, opacity));
						}
					}
				}
			}
		}
		else { // kad po 2 bajta po boji
			if (dubina == 3) {
				for (int j =0; j<visina; j++) { // uslovi za dubinu za citanje OK !
					for (int i = 0; i < sirina; i++) {
						short temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = zamenibitove16(temp);
						char blue = temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = zamenibitove16(temp);
						char green = temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = zamenibitove16(temp);
						char red = temp;
						//binarnifajl.read((char*)& temp, sizeof(temp));
						/*	char opacity = temp;*/
						l->overwritepixel(i, j, Piksel(red, green, blue, 0, 255));
					}
				}
			}
			else if (dubina == 4) {
				for (int j = 0; j <visina; j++) { // uslovi za dubinu za citanje OK !
					for (int i = 0; i < sirina; i++) {
						short temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = zamenibitove16(temp);
						char blue = temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = zamenibitove16(temp);
						char green = temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = zamenibitove16(temp);
						char red = temp;
						binarnifajl.read((char*)& temp, sizeof(temp));
						temp = zamenibitove16(temp);
						char opacity = temp;
						l->overwritepixel(i, j, Piksel(red, green, blue, 0, opacity));
					}
				}
			}

			else if(dubina==1){// kad je crnobelo
				for (int j = 0; j <visina; j++) { 
					for (int i = 0; i < sirina; i++) {
						short temp;
						binarnifajl.read((char*)& temp, sizeof(temp));

						//binarnifajl.read((char*)& temp, sizeof(temp));
						/*	char opacity = temp;*/
						if (temp == 0)
							l->overwritepixel(i, j, Piksel(0, 0, 0, 0, 0));
						else {
							l->overwritepixel(i, j, Piksel(255, 255, 255, 0, 0));
						}
					}
				}
			} 
			else if (dubina == 2) { //crnobelo sa opacity
				for (int j = 0; j <visina; j++) {
					for (int i = 0; i < sirina; i++) {
						short temp;
						binarnifajl.read((char*)& temp, sizeof(temp));


						char opacity;
						binarnifajl.read((char*)& opacity, sizeof(opacity));
						if (temp == 0)
							l->overwritepixel(i, j, Piksel(0, 0, 0, 0, opacity));
						else {
							l->overwritepixel(i, j, Piksel(255, 255, 255, 0, opacity));
						}
					}
				}
			}
		}
		
		

		Image *i = new Image(l->getSirina(),l->getvisina(),brbajtova*8);
		i->DodajSloj(l, 0);
		//i->setBrBitaPoPixelu(brbajtova * 8);
		//return i;
		return l;
		/*PAMwriter pw;
		pw.upisi(&i);
		*/
		

	}
};



#pragma pack(pop)