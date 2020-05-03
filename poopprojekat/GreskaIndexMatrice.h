#pragma once
#include<iostream>
#include"MojaGreska.h"
class GreskaIndexMatrice :public  std::exception {
	std::string r = "Indeksi matrice su izvan dozvoljenog opsega!";
public:GreskaIndexMatrice(std::string raz) :r(raz) {}
	   GreskaIndexMatrice() = default;
	   virtual const char* what()const noexcept
	   {
		   return r.c_str();
	   }

};