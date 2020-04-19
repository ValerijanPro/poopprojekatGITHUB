#pragma once
#include<iostream>
class GreskaPostojiKljuc :public  std::exception{
	std::string r = "Dodavanje nije moguce";
public:GreskaPostojiKljuc(std::string raz) :r(raz) {}
	   GreskaPostojiKljuc() = default;
	   const char* what()const override
	   {		   return r.c_str();	   }

};