#pragma once


#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
class DivInvert :public ioperation {
	int broj;
public:

	DivInvert(int b) :broj(b) {}
	void run(stek& s, argumenti arg) {
		if (broj == 0) throw GreskaPostojiKljuc("Nije dozvoljeno deljenje nulom!");
		Piksel p1 = s.top();
		s.pop();
		char r = p1.getR();
		char g = p1.getG();
		char b = p1.getB();
		char op = p1.getOpacity();
		r = (broj / r) % 256;
		g = (broj / g) % 256;
		b = (broj / b) % 256;
		Piksel p2 = Piksel(r, g, b, 0, op);
		s.push(p2);
	}
};