#pragma once

#include<iostream>

#include <vector>
#include<memory>
#include<string>
#include"Image.h"
#include"Timotije.h"
class MeniZaOperacije {

public:
	void printujOperacije(Image* i) {
		int input;
	//	std::shared_ptr<ioperation>p1 = std::make_shared<Push>(&Push(0));
		//ioperation* iop = new Push(0);
	//	i->getOperacije().push_back(iop);
		i->dodajPush();
		
		while (1) {


			std::cout << "Izaberite redom operacije koje zelite, a 0 za kraj unosa niza operacija" << std::endl;
			std::cout << "1. Apsolutna vrednost" << std::endl;
			std::cout << "2. add " << std::endl;
			std::cout << "3. CrnoBela" << std::endl;

			std::cout << "4. Div" << std::endl;
			std::cout << "5. DivInvert" << std::endl;
			std::cout << "6. Inverzija" << std::endl;
			std::cout << "7. log" << std::endl;
			std::cout << "8. max" << std::endl;
			std::cout << "9. min" << std::endl;
			std::cout << "10. mul" << std::endl;
			std::cout << "11. pow" << std::endl;
			std::cout << "12. siva" << std::endl;
			std::cout << "13. sub" << std::endl;
			std::cout << "14. subInvert" << std::endl;


			std::cout << "0. Kraj unosa operacija" << std::endl;
			std::cin >> input;
		
			if (!input) break;
			i->DodajOperaciju(input);
		}
	}
};