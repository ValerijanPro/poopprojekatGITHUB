#pragma once
#include<iostream>

#include <vector>
#include<string>
#include"UcitavanjeSlikeMeni.h"
#include"IspisSlikeMeni.h"
#include"MeniZaSelekcije.h"
#include"MeniZaOperacije.h"
class MainMeni {
public:
	void IspisiMainMeni() {
		std::cout << "Izaberite opciju za rad: " << std::endl;
		std::cout << "1. Ucitavanje slike" << std::endl;
		std::cout << "2. Rad sa selekcijama " << std::endl;
		std::cout << "3. Operacije nad slikom" << std::endl;
		std::cout << "4. Eksportovanje slike" << std::endl;
		
		std::cout << "5. Ispis slike u zeljenom formatu" << std::endl;
		std::cout << "0. Kraj rada" << std::endl;
	}
	int UcitajOpciju() {
		int s;
		std::cin >> s;
		return s; 
	}
};