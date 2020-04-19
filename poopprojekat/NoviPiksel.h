#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"Piksel.h"
class NoviPiksel {

	int r, g, b;
	int opacity;

public:
	NoviPiksel(Piksel p1) :r(p1.getR()), g(p1.getG()), b(p1.getB()), opacity(p1.getOpacity()) {}
	NoviPiksel(int rr,int gg,int bb,int op=0):r(rr),g(gg),b(bb),opacity(op){}
	int getR()const { return r; }
	int getG()const { return g; }
	int getB() const { return b; }
	int getOpacity() const { return opacity; }
	
	Piksel getPiksel() {
		return Piksel(r, g, b, 0, opacity);
	}

};