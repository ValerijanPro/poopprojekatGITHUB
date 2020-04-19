#pragma once
#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
class Add :public ioperation{
	int broj;
public:
	
	Add(int b):broj(b){}
	void run(stek& s, argumenti arg) {
		Piksel p1 = s.top();
		s.pop();
		char r = p1.getR();		
		char g = p1.getG();
		char b = p1.getB();
		char op = p1.getOpacity();
		r = (r + broj) % 256;
		g = (g + broj) % 256;
		b = (b + broj) % 256;
		Piksel p2 = Piksel(r, g, b,0,op);
		s.push(p2);
	}
};