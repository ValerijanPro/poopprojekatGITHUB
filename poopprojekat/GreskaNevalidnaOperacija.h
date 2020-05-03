#pragma once
#include<iostream>
#include"MojaGreska.h"
class GreskaNevalidnaOperacija :public  std::exception {
	std::string r = "Izabrali ste nepostojecu operaciju. Moguce operacije su navedene u listi";
public:GreskaNevalidnaOperacija(std::string raz) :r(raz) {}
	   GreskaNevalidnaOperacija() = default;
	   virtual const char* what()const noexcept
	   {
		   return r.c_str();
	   }

};