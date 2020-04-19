#pragma once



#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
class Crnobela :public ioperation {
	int broj;
public:

	Crnobela(int b) :broj(b) {}
	void run(stek& s, argumenti arg) {
		Piksel p1 = s.top();
		s.pop();
		char r = p1.getR();
		char g = p1.getG();
		char b = p1.getB();
		char op = p1.getOpacity();
		uint32_t x = ((uint32_t)r + (uint32_t)g + (uint32_t)b) / 3;
		x = x % 256;


		if (x < 127) {
			r = 0;
			g = 0;
			b = 0;
		}
		else {
			r = 255;
			b = 255;
			g = 255;
		}

		Piksel p2 = Piksel(r, g, b, 0, op);
		s.push(p2);
	}
};