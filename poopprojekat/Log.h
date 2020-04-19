#pragma once


#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
class Log :public ioperation {
	int broj;
public:

	Log(int b) :broj(b) {}
	void run(stek& s, argumenti arg) {
		Piksel p1 = s.top();
		s.pop();
		char r = p1.getR();
		char g = p1.getG();
		char b = p1.getB();
		char op = p1.getOpacity();
		r = ((int)std::log(r)) % 256;
		g = ((int)std::log(g)) % 256;
		b = ((int)std::log(b)) % 256;
		Piksel p2 = Piksel(r, g, b, 0, op);
		s.push(p2);
	}
};