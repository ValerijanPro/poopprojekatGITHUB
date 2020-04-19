#pragma once


#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
class Siva :public ioperation {
	int x;
public:
	
	Siva() = default;
	void run(stek& s, argumenti arg) {
		Piksel p1 = s.top();
		s.pop();
		char r = p1.getR();
		char g = p1.getG();
		char b = p1.getB();
		char op = p1.getOpacity();
		int x = ((int)r + (int)g + (int)b) / 3;
		x = x % 256;
		r = x;
		g = x;
		b = x;

		Piksel p2 = Piksel(r, g, b, 0, op);
		s.push(p2);
	}
};