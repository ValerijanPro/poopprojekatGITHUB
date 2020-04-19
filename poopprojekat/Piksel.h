#include<iostream>
#include<vector>
#include<functional>
#include<cmath>
#include<algorithm>
#include"GreskaPostojiKljuc.h"
#include"korisno.h"
using namespace std::placeholders;

#pragma once


class Piksel {
	
	char r, g, b;
	char opacity;
	short offset;
public:
	Piksel(char rr = 0, char gg = 0, char bb = 0, short off =0, char op = 0) :r(rr), g(gg), b(bb), opacity(op),offset(off) {}

	char getR()const { return r; }
	char getG()const { return g; }
	char getB() const { return b; }
	char getOpacity() const { return opacity; }
	short getOffset() const { return offset; }
	/*Piksel& Pocrni() {
		r = 0;
		g = 0;
		b = 0;
	}*/
	
	bool operator==(const Piksel& p) {
		return (r == p.r && g == p.g && b == p.b);
	}
	Piksel& operator+(const int x) {
		r = (r + x) % 256;
		g = (g + x) % 256;
		b = (b + x) % 256;
		return (*this);
	}
	Piksel& operator-(const int x) {
		r = (r - x);
		g = (g - x) ;
		b = (b - x);
		absolute();
		r = r % 256;
		g = g % 256;
		b = b % 256;
		return (*this);
	}
	Piksel& operator*(const int x) {
		r = (r * x) % 256;
		g = (g * x) % 256;
		b = (b * x) % 256;
		return (*this);
	}
	Piksel& operator/(const int x) {
		if (x == 0) throw GreskaPostojiKljuc("Nije dozvoljeno deljenje nulom!");
		else {
			r = (r / x) % 256;
			g = (g / x) % 256;
			b = (b / x) % 256;
			return (*this);
		}
		
		
	}
	Piksel& div_invert (const int x) {
		if (r == 0 || g==0 || b==0) throw GreskaPostojiKljuc("Nije dozvoljeno deljenje nulom!");
		else {
			r = (x / r) % 256;
			g = (x / g) % 256;
			b = (x / b) % 256;
			return (*this);
		}
	}
	
	// WTF
	Piksel& sub_invert(const int x) {
		r = (x - r) ;
		g = (x - g);
		b = (x - b);
		absolute();
		r = r % 256;
		g = g % 256;
		b = b % 256;
		return (*this);
	}
	Piksel& absolute() {
		r = abs(r);
		g = abs(g);
		b = abs(b);
		return (*this);
	}

	
	Piksel& operator^(const int x) {
		r = (char)(std::pow(r,x)) % 256;
		g = (char)(std::pow(g, x)) % 256;
		b = (char)(std::pow(b, x)) % 256;
		return (*this);
	}
	/*Piksel& logaritam(const int x) { 
		r = ((int)log(x) )% 256;
		g = ((int)log(x)) % 256;
		b = ((int)log(x)) % 256;
		
		return (*this);
	}*/
	Piksel& log() {
		r = ((int)std::log(r)) % 256;
		g = ((int)std::log(g)) % 256;
		b = ((int)std::log(b)) % 256;

		return (*this);
	}
	Piksel& min(const int x) {
		if (r > x)r = x;
		if (g > x) g = x;
		if (b > x) b = x;
		return(*this);
	}
	// wtf
	Piksel& max(const int x) {
		//std::unary_negate<Piksel> maxx((*this));
		if (r < x)r = x;
		if (g < x) g = x;
		if (b < x) b = x;
		return(*this);
	}
	Piksel& inverzija() {
		int x = maximum(r, g, b);
		(*this) = (*this) - x;

		return(*this);
	}
	Piksel& siva() {
		int x = ((int)r +(int) g +(int) b) / 3;
		x = x % 256;
		r = x;
		g = x;
		b = x;

		return (*this);
	}
	Piksel& crnobela() {
		uint32_t x = ((uint32_t)r + (uint32_t)g + (uint32_t)b) / 3;
		x = x % 256;
		

		if (x < 127) {
			r = 0;
			g = 0;
			b = 0;
		}
		else {
			r = 255;
			b = 255;
			g = 255;
		}
		return(*this);
	}
	void oboji(char rr, char gg, char bb) { 
		r = rr; g = gg; b = bb; opacity = 0xFF;
	}
	
	
	friend std::ostream& operator<<(std::ostream& os, const Piksel& p) {
		os << (int)p.r << " " << (int)p.g << " " << (int)p.b << " ";

		return os;
	}

};