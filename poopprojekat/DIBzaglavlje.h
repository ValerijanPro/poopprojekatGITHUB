#pragma once

#include<map>
#include<iostream>
#include <vector>
#include"korisno.h"
#pragma pack(push, 1)

struct DIBzaglavlje {
	int brBajtovaDib;
	
	int sirinaSlike;

	int visinaSlike;
	
	short karataBoja;
	short brBitaPoPixelu;
	int BI_RGB;
	int velicinaBitmape;
	int reserved1;
	int reserved2;
	int reserved3;
	int reserved4;
public:
	DIBzaglavlje(int sir=0, int vis=0,int velicina=0) {
		brBajtovaDib = 671088640;
		brBajtovaDib = zamenibitove32(brBajtovaDib);
		sirinaSlike = sir;
		visinaSlike = vis;
		karataBoja = 256;
		karataBoja = zamenibitove16(karataBoja);
		brBitaPoPixelu = 32;
		//brBitaPoPixelu = 6144;
		//brBitaPoPixelu = 2048;
		//brBitaPoPixelu = 4;
		//brBitaPoPixelu= zamenibitove16(brBitaPoPixelu);
		BI_RGB = 0;
		velicinaBitmape = velicina;
		//velicinaBitmape = 49152;
		reserved1 = 319488000;
	//	reserved1 = 3943432192;
		//reserved1 = 0;
		reserved1 = zamenibitove32(reserved1);
		reserved2 = 319488000;
	//	reserved2 = 3943432192;
		//reserved2 = 0;
		reserved2 = zamenibitove32(reserved2);
		reserved3 = 0;
		reserved4 = 0;
	}
	void zamenibitove()
	{
		brBajtovaDib = zamenibitove32(brBajtovaDib);
		sirinaSlike = zamenibitove32(sirinaSlike);
		visinaSlike = zamenibitove32(visinaSlike);
		karataBoja = zamenibitove16(karataBoja);
		brBitaPoPixelu = zamenibitove16(brBitaPoPixelu);

		BI_RGB = zamenibitove32(BI_RGB);
		velicinaBitmape = zamenibitove32(velicinaBitmape);
		reserved1 = zamenibitove32(reserved1);
		reserved2 = zamenibitove32(reserved2);
		reserved3 = zamenibitove32(reserved3);

		reserved4 = zamenibitove32(reserved4);
		
	}
}; 
#pragma pack(pop)