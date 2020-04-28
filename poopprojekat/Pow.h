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
		NoviPiksel p1 = s.top();
		s.pop();
		int r = p1.getR();
		int g = p1.getG();
		int b = p1.getB();
		int op = p1.getOpacity();
		r = (std::pow(r, broj));
		g = (std::pow(g, broj));
		b = (std::pow(b, broj));
		NoviPiksel p2 = NoviPiksel(r, g, b,op);
		s.push(p2);
	}
	int getValue()const { return broj; }
};