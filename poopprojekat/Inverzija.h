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

	Inverzija(int b) :broj(b) {}
	void run(stek& s, argumenti arg) {
		Piksel p1 = s.top();
		
		char r = p1.getR();
		char g = p1.getG();
		char b = p1.getB();
		int x = maximum(r, g, b);
		Sub ss = Sub(x);
		ss.run(s, arg);
	}
};