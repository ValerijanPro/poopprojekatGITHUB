//#pragma once
#include<iostream>

#include <vector>
#include<string>
//#include"Piksel.h"
//#include"Layer.h"
//#include"Image.h"
//#include"BMPcitac.h"
#include <map>

class Pravougaonik {

	int x, y; // x levodesno, y goredole
	int sirina, visina;
public:
	Pravougaonik(int xx,int yy, int sir, int vis):x(xx),y(yy),sirina(sir),visina(vis){}
	bool UPravougaoniku(int xkoordinata, int ykoordinata) {
		if (xkoordinata >= x && xkoordinata <= (x + sirina)) {
			if (ykoordinata >=y && ykoordinata <= (y + visina)) {
				return 1;
			}
			return 0;
		}
		return 0;
	}
};