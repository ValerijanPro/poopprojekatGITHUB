#pragma once

#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
class Pow :public ioperation {
	int broj;
public:

	Pow(int b) :broj(b) {}
	void run(stek& s, argumenti arg) {
		Piksel p1 = s.top();
		s.pop();
		char r = p1.getR();
		char g = p1.getG();
		char b = p1.getB();
		char op = p1.getOpacity();
		r = (char)(std::pow(r,broj)) % 256;
		g = (char)(std::pow(g, broj)) % 256;
		b = (char)(std::pow(b, broj)) % 256;
		Piksel p2 = Piksel(r, g, b, 0, op);
		s.push(p2);
	}
};