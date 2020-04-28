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
		NoviPiksel p1 = s.top();
		s.pop();
		int r = p1.getR();
		int g = p1.getG();
		int b = p1.getB();
		int op = p1.getOpacity();
		int x = ((int)r + (int)g + (int)b) / 3;
		
		r = x;
		g = x;
		b = x;

		NoviPiksel p2 = NoviPiksel(r, g, b, op);
		s.push(p2);
	}
	int getValue()const { return x; }
};