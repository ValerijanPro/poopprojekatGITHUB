#pragma once

#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
class Sub :public ioperation {
	int broj;
public:

	Sub(int b) :broj(b) {}
	void run(stek& s, argumenti arg) {
		NoviPiksel p1 = s.top();
		s.pop();
		int r = p1.getR();
		int g = p1.getG();
		int b = p1.getB();
		int op = p1.getOpacity();
		r = (r - broj);
		g = (g - broj);
		b = (b - broj);
	
		r = (uint8_t)r;
		g = (uint8_t)g;
		b = (uint8_t)b;
		NoviPiksel p2 = NoviPiksel(r, g, b,  op);
		s.push(p2);
	}
	int getValue()const { return broj; }
};