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
	aktivni ak; 
	bool bojenje; 
	int rr = 0; int gg = 0; int bb = 0; int aa = 0;
public:
	void upisi(Image* image,std::string imeFajla) {
		//std::ofstream file;
		std::fstream file(imeFajla, std::ios::binary | std::ios::out);
		
		//file.open("testiram.pam");
		

		std::vector<Selekcija> aktivne;
		for (auto q : image->getSelekcije()) {

			if (q.getStanje()) {

				aktivne.push_back(q);

			}
		}

		std::shared_ptr<Layer>  lejer = image->konstruisiFinalniLayer(ak);
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

				NoviPiksel p3 = NoviPiksel(*p1);
				argumenti ar = { p3 };

				stek s;



				if (!bojenje) {
					if (aktivne.size() != 0) {
						for (auto q : aktivne) {

							if (q.USelekciji(i, j)) {
								for (auto q : image->getOperacije()) {
									q->run(s, ar);
								}
								NoviPiksel p4 = s.top();

								p1 = &p4.getPiksel();
								s.pop();
								ar.pop_back();
								break;
							}
						}
					}
					else { //TODO: uvek mora da ima push
						for (auto q : image->getOperacije()) {
							q->run(s, ar);
						}
						NoviPiksel p4 = s.top();

						p1 = &p4.getPiksel();
						s.pop();
						ar.pop_back();
					}

				}
				else {
					if (aktivne.size() != 0) {
						for (auto q : aktivne) {

							if (q.USelekciji(i, j)) {
								p1 = new Piksel(rr, gg, bb, 0, aa);
							}
						}
					}
					else { //TODO: uvek mora da ima push
						p1 = new Piksel(rr, gg, bb, 0, aa);
					}
				}
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
	void ucitajAtributeMeni() {
		std::cout << "Koji lejeri ce ucestovati u formiranju slike? (Napisite -1 za kraj)" << std::endl;
		int xx = 10;
		while (1) {
			std::cin >> xx;
			if (xx == -1) break;
			ak.push_back(xx);
		}

		std::cout << "Da li zelite da obojite aktivne selekcije?" << std::endl;
		std::cout << "1. Da" << std::endl;
		std::cout << "0. Ne" << std::endl;
		std::cin >> bojenje;
		if (bojenje) {
			std::cout << "Unesite redom R,G,B,A (0-255)" << std::endl;
			std::cin >> rr;
			std::cin >> gg;
			std::cin >> bb;
			std::cin >> aa;
		}
	}
	void ucitajAtributeCMD(aktivni a) {
		ak = a;


	}
};