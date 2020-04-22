#pragma once




#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
#include"Sub.h"
class Inverzija :public ioperation {
	int broj;
public:

	Inverzija(int b=0) :broj(b) {}
	void run(stek& s, argumenti arg) {
		NoviPiksel p1 = s.top();
		
		int r = p1.getR();
		int g = p1.getG();
		int b = p1.getB();
		//int x = maximum(r, g, b);
		r = r % 256;
		g = g % 256;
		b = b % 256;
		int r2 = 255 - r;
		int g2 = 255 - g;
		int b2 = 255 - b;
		//Sub ss = Sub(x);
		//ss.run(s, arg);
		s.push(NoviPiksel(r2, g2, b2, 255));
	}
};