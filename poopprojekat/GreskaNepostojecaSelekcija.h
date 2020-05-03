#pragma once
#include<iostream>
#include"MojaGreska.h"
class GreskaNepostojecaSelekcija :public std::exception {
	std::string r = "Data selekcija ne postoji u slici";
public:GreskaNepostojecaSelekcija(std::string raz) :r(raz) {}
	   GreskaNepostojecaSelekcija() = default;
	   virtual const char* what()const noexcept
	   {
		   return r.c_str();
	   }

};