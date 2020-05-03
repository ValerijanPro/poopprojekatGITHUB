#pragma once
#include<iostream>
class MojaGreska :public  std::exception {
	std::string r = "Greska";
public:MojaGreska(std::string raz) :r(raz) {}
	  // MojaGreska() = default;
	   virtual const char* what()const override
	   {
		   return r.c_str();
	   }

};