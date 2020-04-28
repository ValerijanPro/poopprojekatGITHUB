#pragma once
#include<iostream>
#include<functional>
#include <vector>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
#include"NoviPiksel.h"
#include<stack>
//typedef stack
//typedef operations
typedef std::stack <NoviPiksel>stek; //NoviPiksel
typedef std::vector<NoviPiksel> argumenti;//NoviPiksel
 class ioperation {
	 
public:
	virtual void run(stek& s,argumenti arg)=0; // prosledim stack i ARGUMENTS
	virtual int getValue()const = 0;
};