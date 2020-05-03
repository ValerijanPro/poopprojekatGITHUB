#pragma once
#include<iostream>

#include <vector>
#include<string>

#include <map>

class Pravougaonik {

	int x, y; // x levodesno, y goredole
	int sirina, visina;
public:
	Pravougaonik(int xx,int yy, int sir, int vis):x(xx),y(yy),sirina(sir),visina(vis){}
	bool UPravougaoniku(int xkoordinata, int ykoordinata) {
		if (xkoordinata < 0 || ykoordinata < 0) throw GreskaIndexMatrice("Koordinate pravougaonika nisu validne");
		if (xkoordinata >= x && xkoordinata <= (x + sirina)) {
			if (ykoordinata >=y && ykoordinata <= (y + visina)) {
				return 1;
			}
			return 0;
		}
		return 0;
	}
	int getX()const { return x; }
	int getY()const { return y; }
	int getSirina()const { return sirina; }
	int getVisina()const { return visina; }
};