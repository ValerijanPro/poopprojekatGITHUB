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
		NoviPiksel p1 = s.top();
		s.pop();
		int r = p1.getR();
		int g = p1.getG();
		int b = p1.getB();
		int op = p1.getOpacity();
		r = abs(r);
		g = abs(g);
		b = abs(b);
		NoviPiksel p2 = NoviPiksel(r, g, b,  op);
		s.push(p2);
	}
	int getValue()const { return broj; }
};