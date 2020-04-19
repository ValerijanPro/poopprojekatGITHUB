#pragma once
#include<iostream>
#include<functional>
#include <vector>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"Piksel.h"
#include<stack>
//typedef stack
//typedef operations
typedef std::stack <Piksel>stek;
typedef std::vector<Piksel> argumenti;
 class ioperation {
public:
	virtual void run(stek& s,argumenti arg)=0; // prosledim stack i ARGUMENTS
};