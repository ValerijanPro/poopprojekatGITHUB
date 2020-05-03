#pragma once
#include<iostream>
class GreskaMeni :public  std::exception {
	std::string r = "Izabrali ste nepostojecu opciju u meniju";
public:GreskaMeni(std::string raz) :r(raz) {}
	   GreskaMeni() = default;
	   const char* what()const override
	   {
		   return r.c_str();
	   }

};