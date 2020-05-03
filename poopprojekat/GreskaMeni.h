#pragma once
#include<iostream>
#include"MojaGreska.h"
class GreskaMeni :public  std::exception {
	std::string r = "Izabrali ste nepostojecu opciju u meniju";
public:GreskaMeni(std::string raz) :r(raz){}
	   GreskaMeni() = default;
	   virtual const char* what()const noexcept
	   {
		   return r.c_str();
	   }

};