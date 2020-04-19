#pragma once
#include<regex>
#include<cmath>



#include<iostream>
#include<fstream>
#include <vector>

int maximum(int a, int b, int c) {
	if (a > b)
	{
		if (a > c)
		{
			return a;
		}
	}
	else 
	{
		if (b > c)
		{
			return b; 
		}
		else 
		{
			if (c > a)
			{
				return c;
			}
		}
	}
	
}
int GetBroj(std::string& s) {

	int i = s.length()-1 ;
	while (i != 0 && s[i] != ' ')
	{
		i--;
	}
	int broj=0;
	int cifara = s.length() - i-1;
	int stepen = 0;
	while (stepen!=cifara) {
		broj = broj + std::pow(10, cifara-stepen-1)*(s[++i]-48);
		stepen++;
	}
	return broj;
	
}
int SkalirajNa(uint8_t v, int n,int m) {
	return (v *(1.0)/ n) * m;
}
void ispisiString(std::fstream* file, std::string s) {
	for (int i = 0; i < s.length(); i++) {
		file->write((char*)& s[i], sizeof(char));
	}
}
int BrBajtova(int x) { // x je maxval
	int y = std::log2(x+1);
	while ((y % 8) != 0) y++;
	return y / 8;
}
inline short zamenibitove16(const short broj)
{
	
	return (broj >> 8) | (broj << 8);
}
inline short zamenitempbitove16(const uint16_t broj) {
	return (broj >> 8) | (broj << 8);
}

inline  int zamenibitove32(const int num)
{

	int b0, b1, b2, b3;
	int res;

	b0 = (num & 0x000000ff) << 24u;
	b1 = (num & 0x0000ff00) << 8u;
	b2 = (num & 0x00ff0000) >> 8u;
	b3 = (num & 0xff000000) >> 24u;

	res = b0 | b1 | b2 | b3;
	return res;
	//return (((broj >> 24) & 0xFF) | ((broj << 8) & 0xFF0000) |
	//	((broj >> 8) & 0xFF00) | ((broj << 24) & 0xFF000000));

}


