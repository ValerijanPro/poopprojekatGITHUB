#pragma once

#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
class Div :public ioperation {
	int broj;
public:

	Div(int b) :broj(b) {}
	void run(stek& s, argumenti arg) {
		if (broj == 0) throw GreskaPostojiKljuc("Nije dozvoljeno deljenje nulom!");
		NoviPiksel p1 = s.top();
		s.pop();
		int r = p1.getR();
		int g = p1.getG();
		int b = p1.getB();
		int op = p1.getOpacity();
		r = (r / broj) ;
		g = (g / broj);
		b = (b / broj) ;
		NoviPiksel p2 = NoviPiksel(r, g, b, op);
		s.push(p2);
	}
};