#pragma once


#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
class SubInvert :public ioperation {
	int broj;
public:

	SubInvert(int b) :broj(b) {}
	void run(stek& s, argumenti arg) {
		Piksel p1 = s.top();
		s.pop();
		char r = p1.getR();
		char g = p1.getG();
		char b = p1.getB();
		char op = p1.getOpacity();
		r = (broj - r);
		g = (broj - g);
		b = (broj - b);
		
		r = (uint8_t)r;
		g = (uint8_t)g;
		b = (uint8_t)b;
		Piksel p2 = Piksel(r, g, b, 0, op);
		s.push(p2);
	}
};