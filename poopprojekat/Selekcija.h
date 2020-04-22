#pragma once
#include<iostream>

#include <vector>
#include<string>


#include"Pravougaonik.h"
#include <map>
typedef std::vector<Pravougaonik> pravougaonici;
class Selekcija {
	std::string ime;
	pravougaonici niz;
	bool aktivna;
public:
	Selekcija(std::string s, pravougaonici p) :ime(s){

		for ( auto i :p) {
			niz.push_back(i);
		}
	}
	bool USelekciji(int x, int y) {
		//bool temp = 0;
		for (auto i : niz) {
			if (i.UPravougaoniku(x, y)) return 1;
		}
		 return 0;
		
	}
	void setStanje(bool a) { aktivna = a; }
	bool getStanje()const { return aktivna; }
};