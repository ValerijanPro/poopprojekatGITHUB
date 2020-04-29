#pragma once
#include<map>
#include<iostream>
#include<chrono>
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
typedef std::vector<int> aktivni;
class BMPwriter {
public:
	 //TODO: ODVOJENO OPERACIJE, NE TREBA U ISTOM FAJLU U KOME JE IMAGE
	void upisi(Image* image,std::string ImeFajla) {
		std::fstream file(ImeFajla, std::ios::binary | std::ios::out);
		//if (!file.is_open) {
			//gresku napraviti
		//}
		std::cout << "Koji lejeri ce ucestovati u formiranju slike? (Napisite -1 za kraj)" << std::endl;
		int xx = 10; aktivni ak; ak.clear();
		while (1) {
			std::cin >> xx;
			if (xx == -1) break;
			ak.push_back(xx);
		}
		bool bojenje;
		int rr, gg, bb, aa;
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
		auto t1 = std::chrono::high_resolution_clock::now();
		std::shared_ptr<Layer>  lejer = image->konstruisiFinalniLayer(ak);
		auto t2 = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

		std::cout << duration;

		//Pravougaonik kvadrat1 = Pravougaonik(400,400, 50, 50);
		//Pravougaonik kvadrat2 = Pravougaonik(200, 300, 200 , 200);
		//Pravougaonik kvadrat3 = Pravougaonik(0, 0, 100, 100);
		//pravougaonici pp;

		//pp.push_back(kvadrat1);
		//pp.push_back(kvadrat2);
		//pp.push_back(kvadrat3);
		//Selekcija se = Selekcija("Nekatamo", pp);


		DIBzaglavlje1 dibzaglavlje = DIBzaglavlje1(lejer->getSirina(), lejer->getvisina(), lejer->getSirina()* lejer->getvisina()*4); //sir*vis*bitova/8

		BMPzaglavlje1 bmpzaglavlje = BMPzaglavlje1(lejer->getSirina() * lejer->getvisina()*4 + 122);
		std::cout << sizeof(bmpzaglavlje) << std::endl;
		std::cout << sizeof(dibzaglavlje) << std::endl;
		file.write((char*)& bmpzaglavlje, sizeof(bmpzaglavlje));
		file.write((char*)& dibzaglavlje, sizeof(dibzaglavlje));
		

		bool state = 1;
		Piksel p2;
		int print = 0;
		int x=0, y=0;
		int paja = 0;
		
		std::vector<Selekcija> aktivne;
		for (auto q : image->getSelekcije()) {

			if (q.getStanje() ) {
				
				aktivne.push_back(q);

			}
		}


		for (int j = dibzaglavlje.visinaSlike - 1; j >= 0; j--) { // obrnuto
			
			for (int i=0; i < dibzaglavlje.sirinaSlike; i++) {
				

				Piksel* p1 = &lejer->getPixel(i, j);

				NoviPiksel p3 = NoviPiksel(*p1);
				argumenti ar = { p3 };

				stek s;

				//selekcije aktivne

				if (!bojenje) {
					if (aktivne.size()!=0) {
						for (auto q : aktivne) {

							if ( q.USelekciji(i, j)) {
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
					if (aktivne.size()!=0) {
						for (auto q : aktivne) {

							if ( q.USelekciji(i, j)) {
								p1 = new Piksel(rr, gg, bb, 0, aa);
							}
						}
					}
					else { //TODO: uvek mora da ima push
						p1 = new Piksel(rr, gg, bb, 0, aa);
					}
				}
				
				
				char temp;
				
				temp = p1->getB(); 
	
				file.write((char*)& temp, sizeof(temp));
				temp = p1->getG();
		
				file.write((char*)& temp, sizeof(temp));
				temp = p1->getR();
			
				file.write((char*)& temp, sizeof(temp));
			
				temp = p1->getOpacity();
			//	temp = 0;
				file.write((char*)& temp, sizeof(temp));
				


			}
		
		}
	
		file.close();


	}
};