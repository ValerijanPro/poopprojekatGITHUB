#pragma once


#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
class Min :public ioperation {
	int broj;
public:

	Min(int b) :broj(b) {}
	void run(stek& s, argumenti arg) {
		NoviPiksel p1 = s.top();
		s.pop();
		int r = p1.getR();
		int g = p1.getG();
		int b = p1.getB();
		int op = p1.getOpacity();
		if (r > broj)r = broj;
		if (g > broj) g = broj;
		if (b > broj) b = broj;
		NoviPiksel p2 = NoviPiksel(r, g, b,  op);
		s.push(p2);
	}
	int getValue()const { return broj; }
};