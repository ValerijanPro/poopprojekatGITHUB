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
#include"MainMeni.h"
void main() {
	MainMeni mm = MainMeni();
	int Radi = 1;
	while (1) {
		mm.IspisiMainMeni();
		int opcija = mm.UcitajOpciju();

		if (opcija == 1) {
			
			UcitavanjeSlikeMeni um = UcitavanjeSlikeMeni();
			
			um.UcitajFormat();
			if (um.getFormat() == 0) {
				continue;
			}
			um.UcitajSliku();
			continue;
		}
		else {
			
			break;
		}

			
		
			
		
	}


	PamCitac p = PamCitac();
	//p.ucitaj("p7_3x2_12b_3d.pam");
	p.ucitaj("IMG_20190809_154608083.pam");
	BMPcitac b=BMPcitac();

	b.ucitaj("RAY.BMP");
	//BLK,WHT,VENUS,LAND,LAND2, BLU SKORO
	 stek s;
	 NoviPiksel p1 = NoviPiksel(3, 3, 3);
	 NoviPiksel p2 = NoviPiksel(127, 127, 127);
	 NoviPiksel p3 = NoviPiksel(255, 255, 255);
	
	 argumenti ar = { p1};
	 std::vector<ioperation*> niz;
	niz = {&Push(0),&Pow(2),&Add(6),&Div(15),&Siva()};
	for (auto i : niz) {
		i->run(s, ar);
	}
	NoviPiksel p4 = s.top();

	return;
	
}