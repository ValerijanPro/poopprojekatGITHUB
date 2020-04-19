#pragma once
#pragma once


#include<iostream>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"ioperation.h"
class Push :public ioperation {
	int index;
public:

	Push(int b) :index(b) {}
	void run(stek& s, argumenti arg) {
		s.push(arg.at(index));
	}
};