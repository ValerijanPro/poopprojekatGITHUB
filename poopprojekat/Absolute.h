#pragma once

#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
class Absolute :public ioperation {
	int broj;
public:

	Absolute(int b) :broj(b) {}
	void run(stek& s, argumenti arg) {
		Piksel p1 = s.top();
		s.pop();
		char r = p1.getR();
		char g = p1.getG();
		char b = p1.getB();
		char op = p1.getOpacity();
		r = abs(r);
		g = abs(g);
		b = abs(b);
		Piksel p2 = Piksel(r, g, b, 0, op);
		s.push(p2);
	}
};