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
#include"korisno.h"
#include"pamheder.h"
class PAMwriter {
public:
	void upisi(Image* i,std::string imeFajla) {
		//std::ofstream file;
		std::fstream file(imeFajla, std::ios::binary | std::ios::out);
		
		//file.open("testiram.pam");
		Layer* lejer = i->konstruisiFinalniLayer();
		//DIBzaglavlje1 dibzaglavlje = DIBzaglavlje1(lejer->getSirina(), lejer->getvisina(), lejer->getSirina() * lejer->getvisina());
		PamHeder pamheder = PamHeder(lejer->getSirina(), lejer->getvisina());
		//BMPzaglavlje1 bmpzaglavlje = BMPzaglavlje1(lejer->getSirina() * lejer->getvisina() * 3 + 122);
		ispisiString(&file, pamheder.magicNumber);
		ispisiString(&file, pamheder.sirina);
		ispisiString(&file, pamheder.visina);
		ispisiString(&file, pamheder.dubina);
		ispisiString(&file, pamheder.maxval);
		ispisiString(&file, pamheder.tupltype); 
		ispisiString(&file, pamheder.endhdr);
		Layer* novi = (lejer->IzvrsiMedijanu());
		//lejer = novi;

		
		std::vector<ioperation*> niz;
		niz.push_back(&Push(0));
		niz.push_back(&Inverzija());
/*
		file.close();
		file.write((char*)& pamheder, sizeof(pamheder));
		file.close();*/

		Pravougaonik kvadrat2 = Pravougaonik(300,300, 50, 50);
		Pravougaonik kvadrat3 = Pravougaonik(0, 0, 50, 50);
		pravougaonici pp;
		/*pp.push_back(kvadrat1);
		pp.push_back(kvadrat2);*/
		//pp.push_back(kvadrat1);
		pp.push_back(kvadrat2);
		pp.push_back(kvadrat3);
		Selekcija se = Selekcija("Nekatamo", pp);
		bool state = 1;
		Piksel p2;
		int print = 0;
		int x = 0, y = 0;
		long long int paja = 0;
		for (int j = 0; j < lejer->getvisina(); j++) {

			for (int i = 0; i < lejer->getSirina(); i++) {
				
				Piksel* p1 = &lejer->getPixel(i, j);
				/*
				NoviPiksel p3 = NoviPiksel(*p1);
				argumenti ar = { p3 };
				
				stek s;*/
				//if (se.USelekciji(i, j)) {
				//	//std::cout << "i:" << i << ", j:" << j << std::endl;
				//	p1->oboji(0xFF, 0xFF, 0x00);
				//}


			/*	for (auto i : niz) {
					i->run(s, ar);
				}
				NoviPiksel p4 = s.top();
				s.pop();
				p1 = &p4.getPiksel();
				ar.pop_back();*/
				char temp;
				temp = p1->getR();
				file.write((char*)& temp, sizeof(temp));
				temp = p1->getG();
				file.write((char*)& temp, sizeof(temp));
				temp = p1->getB();
				file.write((char*)& temp, sizeof(temp));
		
				x = i;
				y = j;
				temp = p1->getOpacity();
			}
			//if (paja > 68235) {
			//	break;
		//	};
		}
		file.close();
	}
};