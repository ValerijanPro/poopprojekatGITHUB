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
	 
	void upisi(Image* image,std::string ImeFajla) {
		std::fstream file(ImeFajla, std::ios::binary | std::ios::out);
		//if (!file.is_open) {
			//gresku napraviti
		//}
		Layer* lejer = image->konstruisiFinalniLayer();
		

		//Pravougaonik kvadrat1 = Pravougaonik(400,400, 50, 50);
		//Pravougaonik kvadrat2 = Pravougaonik(200, 300, 200 , 200);
		//Pravougaonik kvadrat3 = Pravougaonik(0, 0, 100, 100);
		//pravougaonici pp;

		//pp.push_back(kvadrat1);
		//pp.push_back(kvadrat2);
		//pp.push_back(kvadrat3);
		//Selekcija se = Selekcija("Nekatamo", pp);


		DIBzaglavlje dibzaglavlje = DIBzaglavlje(lejer->getSirina(), lejer->getvisina(), lejer->getSirina()* lejer->getvisina()*4); //sir*vis*bitova/8

		BMPzaglavlje bmpzaglavlje = BMPzaglavlje(lejer->getSirina() * lejer->getvisina()*4 + 54);

		file.write((char*)& bmpzaglavlje, sizeof(bmpzaglavlje));
		file.write((char*)& dibzaglavlje, sizeof(dibzaglavlje));
		

		bool state = 1;
		Piksel p2;
		int print = 0;
		int x=0, y=0;
		int paja = 0;
		
		for (int j = dibzaglavlje.visinaSlike - 1; j >= 0; j--) { // obrnuto
			
			for (int i=0; i < dibzaglavlje.sirinaSlike; i++) {
				

				Piksel* p1 = &lejer->getPixel(i, j);

				NoviPiksel p3 = NoviPiksel(*p1);
				argumenti ar = { p3 };

				stek s;

				

				if (image->getSelekcije().size() != 0) {
					for (auto q : image->getSelekcije()) {

						if (q.getStanje() && q.USelekciji(i, j)) {
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
				/*else { //TODO: uvek mora da ima push
					for (auto q : image->getOperacije()) {
						q->run(s, ar);
					}
					NoviPiksel p4 = s.top();

					p1 = &p4.getPiksel();
					s.pop();
					ar.pop_back();
				}*/
			
				
				
				char temp;
				
				temp = p1->getB(); 
	
				file.write((char*)& temp, sizeof(temp));
				temp = p1->getG();
		
				file.write((char*)& temp, sizeof(temp));
				temp = p1->getR();
			
				file.write((char*)& temp, sizeof(temp));
				paja++;
				x = i;
				y = j;
		
				temp = p1->getOpacity();
				
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
		file.close();


	}
};