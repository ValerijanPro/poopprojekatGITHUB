#pragma once

#include<iostream>
#include"MojaGreska.h"
class GreskaFormatFajla :public  std::exception {
	std::string r = "Uneli ste nepostojeci format. Dozvoljeni su samo BMP,PAM i IMAGE";
public:GreskaFormatFajla(std::string raz) :r(raz){}
	   GreskaFormatFajla() = default;
	   virtual const char* what()const noexcept
	   {
		   return r.c_str();
	   }

};