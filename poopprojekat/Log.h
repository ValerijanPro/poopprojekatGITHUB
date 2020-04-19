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
		NoviPiksel p1 = s.top();
		s.pop();
		int r = p1.getR();
		int g = p1.getG();
		int b = p1.getB();
		int op = p1.getOpacity();
		r = ((int)std::log(r)) ;
		g = ((int)std::log(g)) ;
		b = ((int)std::log(b));
		NoviPiksel p2 = NoviPiksel(r, g, b,  op);
		s.push(p2);
	}
};