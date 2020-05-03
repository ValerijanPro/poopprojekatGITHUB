#pragma once


#include<iostream>
#include"MojaGreska.h"
class GreskaNemaFajla :public std::exception {
	std::string r = "Fajl koji zelite da otvorite, ne postoji";
public:GreskaNemaFajla(std::string raz) : r(raz) {}
	   GreskaNemaFajla() = default;
	   virtual const char* what()const noexcept
	   {
		   return r.c_str();
	   }

};