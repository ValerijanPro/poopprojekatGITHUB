#pragma once

#include<map>
#include<iostream>
#include <vector>
#include"korisno.h"
#pragma pack(push, 1)


struct BMPzaglavlje {
		
	short idpolje;
	int VelicinaFajla;
	short rezervisano1;
	short rezervisano2;
	int PocetakPiksela;

public:
	BMPzaglavlje(int vel=0) {
		 idpolje= 16973;
		 idpolje = zamenibitove16(idpolje);
		 VelicinaFajla = vel;
		 //VelicinaFajla = 49206;

		 rezervisano1 = 0;
		 rezervisano2 = 0;
		// PocetakPiksela = 0x36040000;
		 PocetakPiksela = 0x36000000;
		 PocetakPiksela = zamenibitove32(PocetakPiksela);
	}
	void zamenibitove()
	{
		idpolje = zamenibitove16(idpolje);
		VelicinaFajla = zamenibitove32(VelicinaFajla);
		rezervisano1 = zamenibitove16(rezervisano1);
		rezervisano2 = zamenibitove16(rezervisano2);
		PocetakPiksela = zamenibitove32(PocetakPiksela);
	}
}; 

#pragma pack(pop)