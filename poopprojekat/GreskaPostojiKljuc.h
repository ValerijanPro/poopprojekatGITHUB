#pragma once
#include<iostream>
#include"MojaGreska.h"
class GreskaPostojiKljuc :public  std::exception {
	std::string r = "Dodavanje nije moguce";
public:GreskaPostojiKljuc(std::string raz) :r(raz){}
	   GreskaPostojiKljuc() = default;
	   virtual const char* what()const noexcept
	   {
		   return r.c_str();
	   }

};