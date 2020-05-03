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
#include"tinyxml2.h"
#include"CMDinput.h"
#include"SveGreske.h"
void main(int argc, char* argv[]) {
	Image* slika = new Image();
	//std::cout << argc << std::endl;
	if (argc != 1) {
		
		//std::cout << argv[0]<<std::endl;
		std::string imefajlaSlike, imefajlaOperacija;
		imefajlaSlike = argv[1];

		//std::cout << argv[1]<<std::endl;
		imefajlaOperacija = argv[2];
	//	imefajlaOperacija = "svekrva.fun";
	//	std::cout << argv[2]<<std::endl;
		//imefajlaSlike = "RAY - Copy.bmp";
		//imefajlaSlike = "C:\\Users\\Valja\\source\\repos\\poopprojekat\\poopprojekatGITHUB\\poopprojekat\\RAY - Copy.BMP";
		//imefajlaOperacija = "svekrva.fun";
		
		CMDinput cmd;
		slika->getOperacije().clear();
		slika=cmd.ucitaj(imefajlaSlike, imefajlaOperacija);
		
		if (SeZavrsavaSa(imefajlaSlike, ".BMP") || SeZavrsavaSa(imefajlaSlike, ".bmp")) {
			BMPwriter BMP;
		//	aktivni asd; asd.push_back(0);
			if (slika->getAkt().size() == 0) slika->getAkt().push_back(0);
			BMP.ucitajAtributeCMD(slika->getAkt());
			BMP.upisi(slika, imefajlaSlike);
		}
		else if (SeZavrsavaSa(imefajlaSlike, ".pam")|| SeZavrsavaSa(imefajlaSlike, ".PAM")){
			PAMwriter PAM;
		//	aktivni asd; asd.push_back(0);
		//	std::cout << "PAM";
			if (slika->getAkt().size() == 0) slika->getAkt().push_back(0);
			PAM.ucitajAtributeCMD(slika->getAkt());
			PAM.upisi(slika, imefajlaSlike);
		}
		else if (SeZavrsavaSa(imefajlaSlike, ".xml")|| SeZavrsavaSa(imefajlaSlike, ".XML")) {
			XMLIMAGEwriter xml;
			if (slika->getAkt().size() == 0) slika->getAkt().push_back(0);
			xml.ucitajAtribute(slika->getAkt());
			xml.ispisiXML(imefajlaSlike, slika);
		}
		//std::cout << "Kraj kraja" << std::endl;
		return;
	}
	MainMeni mm = MainMeni();
	MeniZaSelekcije ms;
	int Radi = 1;
	
		while (1) {
			try {
				mm.IspisiMainMeni();
				int opcija = mm.UcitajOpciju();

				if (opcija == 1) {

					UcitavanjeSlikeMeni um = UcitavanjeSlikeMeni();

					um.UcitajFormat();
					if (um.getFormat() == 0) {
						continue;
					}
					slika = um.UcitajSliku(slika);
					continue;
				}
				else if (opcija == 2) {
					ms.UcitajSelekciju(slika);

					continue;
				}
				else if (opcija == 3) {
					MeniZaOperacije mo;
					mo.printujOperacije(slika);
					continue;
				}
				else if (opcija == 4) {
					EksportXMLmeni e;
					slika = e.ucitajImeFajla(slika);
					continue;
				}
				else if (opcija == 5) {
					EksportXMLmeni e;
					slika = e.ucitajImeFajlaZaOperacije(slika);
					continue;
				}
				else if (opcija == 6) {
					int poz;
					std::cout << "Unesite redni broj sloja koji brisete: " << std::endl;
					std::cin >> poz;
					slika->ObrisiLejer(poz);
					continue;
				}
				else if (opcija == 7) {
					//	BMPwriter bmp = BMPwriter();
						//bmp.upisi(slika);
					IspisSlikeMeni im = IspisSlikeMeni();
					im.IspisiSliku(slika);
					continue;

				}
				else if (opcija == 0) {
					std::cout << "Da li ste sigurni da zelite da napustite program? " << std::endl;
					bool da;
					std::cin >> da;
					if (da)break;
					else continue;

				}
				else {
					throw GreskaMeni();

				}


			}
			catch (std::exception& g) {
				std::cout<<g.what()<<std::endl;
				std::cout << "Da li zelite da nastavite sa izvrsavanjem programa?" << std::endl;
				std::cout << "1. DA" << std::endl;
				std::cout << "0. NE" << std::endl;
				bool da;
				std::cin >> da;
				if (da) continue;
				else break;
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