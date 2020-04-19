#include<iostream>

#include <vector>
#include<string>
#include"Piksel.h"
#include"Layer.h"
#include"Image.h"
#include"BMPcitac.h"
#include"Selekcija.h"
#include <map>
#include"ioperation.h"
#include<vector>
#include"Timotije.h"
#include"pamcitac.h"
#include"pamwriter.h"
void main() {

	PamCitac p = PamCitac();
	//p.ucitaj("p7_3x2_12b_3d.pam");
	p.ucitaj("IMG_20190809_154608083.pam");
	BMPcitac b=BMPcitac();

	b.ucitaj("RAY.BMP");
	//BLK,WHT,VENUS,LAND,LAND2, BLU SKORO
	 stek s;
	 Piksel p1 = Piksel(3, 3, 3);
	 Piksel p2 = Piksel(127, 127, 127);
	 Piksel p3 = Piksel(255, 255, 255);
	 argumenti ar = { p1};
	 std::vector<ioperation*> niz;
	niz = {&Push(0),&Pow(2),&Add(6),&Div(15),&Siva()};
	for (auto i : niz) {
		i->run(s, ar);
	}
	Piksel p4 = s.top();

	//Pixel result = stack.pop();

	Image i = Image(3, 3,3);
	Layer l = Layer(5,5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			l.getPixel(i, j).oboji(i,j,3);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (l.normalnaMedijana(i, j)) { 
				l.Medijana(i, j); }
			else l.IvicaMedijana(i, j);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << l.getPixel(i,j);
		}
	}
	
	Layer l1 = Layer(4, 4);
	Layer l2 = Layer(2, 3);
	Layer l3 = Layer(7, 2);

	std::cout << l;
	
}