#pragma once


#include<map>
#include<iostream>
#include <vector>
#include"korisno.h"
#pragma pack(push, 1)

struct DIBzaglavlje1 {
	int brBajtovaDib;
	int sirinaSlike;
	int visinaSlike;
	short KolorPlanes;
	short brBitaPoPixelu;
	int BI_BITFIELDS;
	int rawbitmapdata;
	int horizontal;
	int vertical;
	int kolorpalete;
	int important;
	int redmask;
	int greenmask;
	int bluemask;
	int alphamask;
	int LCS_WINDOWS;
	char array[36];
	int redgamma;
	int greengamma;
	int bluegamma;
	/*
	short karataBoja;
	short brBitaPoPixelu;
	int BI_RGB;
	int velicinaBitmape;
	int reserved1;
	int reserved2;
	int reserved3;
	int reserved4;*/
public:
	DIBzaglavlje1(int sir = 0, int vis = 0, int velicina = 0) {
		brBajtovaDib = 0x6C;
		//brBajtovaDib = zamenibitove32(brBajtovaDib);
		sirinaSlike = sir;
		visinaSlike = vis;
		 KolorPlanes=0x0100;
		 KolorPlanes = zamenibitove16(KolorPlanes);
		 brBitaPoPixelu=0x2000;
		 brBitaPoPixelu = zamenibitove16(brBitaPoPixelu);
		 BI_BITFIELDS=0x03000000;
		 BI_BITFIELDS = zamenibitove32(BI_BITFIELDS);
		 rawbitmapdata=0x20000000;
		 rawbitmapdata = zamenibitove32(rawbitmapdata);
		 horizontal=0x130B0000;
		 horizontal = zamenibitove32(horizontal);
		 vertical= 0x130B0000;
		 vertical = zamenibitove32(vertical);
		 kolorpalete=0;
		 important=0;
		 redmask=0x0000FF00;
		 redmask = zamenibitove32(redmask);
		 greenmask=0x00FF0000;
		 greenmask = zamenibitove32(greenmask);
		 bluemask=0xFF000000;
		 bluemask = zamenibitove32(bluemask);
		 alphamask=0x000000FF;
		 alphamask = zamenibitove32(alphamask);
		 LCS_WINDOWS=0x206E6957;
		 LCS_WINDOWS = zamenibitove32(LCS_WINDOWS);
		 for (int i = 0; i < 36;i++)array[i] = 0;
		 redgamma=0;
		 greengamma=0;
		 bluegamma=0;
	}
	/*void zamenibitove()
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

	}*/
};
#pragma pack(pop)