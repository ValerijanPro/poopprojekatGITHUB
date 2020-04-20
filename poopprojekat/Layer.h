#pragma once
#include<iostream>
#include <vector>
#include"Piksel.h"
#include"GreskaPostojiKljuc.h"


#pragma endregion
typedef std::vector<Piksel> nizpiksela;
typedef std::vector<nizpiksela> matrica;

class Layer {

private:
	matrica m;
	
	int sirina, visina;
public:
	int getSirina()const { return sirina; }
	int getvisina()const { return visina; }
	Layer( int sir, int vis){
//	Layer( Image otac){
		sirina = sir;
		visina = vis;
		
		
		for (int i = 0; i < sirina; i++) {
			nizpiksela pikseli;
			for (int j = 0; j < visina; j++) {
					Piksel p = Piksel();
					pikseli.push_back(p);
				
			}
			m.push_back(pikseli);
		}
	}
	void overwritepixel(int i, int j,Piksel p) {
		m[i][j] = p;
	}
	Piksel& getPixel(int i,int j) {
		if (i > sirina || j > visina) throw GreskaPostojiKljuc();
		return m[i][j];
	}

	friend std::ostream& operator<<(std::ostream& os, const Layer& l) {

		
			for (int j = 0; j < l.visina; j++) {
				for (int i = 0; i < l.sirina; i++) {
					os << l.m[i][j] << " ";
				}	os << std::endl;
			}
		
		
		/*for (std::iterator<nizpiksela> i = l.m.begin(); i != l.m.end();++i) {
			
				os << *i;
			
		}*/
		
		return os;
	}
private:
	void kopiraj(const Layer& s) {
		visina = s.visina;
		sirina = s.sirina;
		
		for (int i = 0; i < sirina; i++) {
			nizpiksela pikseli;
			for (int j = 0; j < visina; j++) {
				Piksel p = s.m[i][j];
				pikseli.push_back(p);

			}
			m.push_back(pikseli);
		}
		
	}
	void premesti(Layer& s) {
		m = s.m;
		for (auto i = s.m.begin(); i !=s. m.end(); i++) {
			i =s. m.erase(i);

		}
		visina = s.visina;
		sirina = s.sirina;
		s.visina = 0;
		s.sirina = 0;

	}
	void brisi() { 
		m.clear();
		//PROBLEM S BRISANJEM ILI OK?
		/*for (auto i = m.begin(); i !=m.end(); i++) {
			m.erase(i);
			

		}*/
		
		sirina = 0;
		visina = 0;
	}

public:
	
	void realocirajPovecaj(int sir, int vis) { //a= sirina , b=visina
	
		//dodam samo na postojece
		//auto kr = m.end();
		
		for (int j = 0; j < sirina; j++) {
			
				auto kraj = m[j].end();

				m[j].insert(kraj, vis - visina, Piksel());
			
		}
		std::cout << std::endl;
		std::cout << *this;
		nizpiksela niz;
		//dodam koliko fali uspravnih stangli
		for (int j = 0; j < sir - sirina; j++) {
			//napravim jednu novu uspravnu stanglu
			
			niz.clear();
			for (int i = 0; i < vis; i++) {

				niz.push_back(Piksel());
			}
			auto kraj = m.end();
			m.insert(kraj, niz);
		}
		

	
		//nove vrednosti sirine i visine
		sirina = sir;
		visina = vis;
		std::cout << std::endl;
		std::cout << *this;
	}

	Layer(const Layer& s) { kopiraj(s); }
	Layer(Layer&& s) { premesti(s); }
	Layer& operator=(const Layer& s) {
		if (this != &s) {
			brisi();
			kopiraj(s);
		}
		return (*this);
	}
	Layer& operator=(Layer&& s) {
		if (this != &s) {
			brisi();
			premesti(s);
		}
		return (*this);
	}
	virtual ~Layer() { brisi(); }
	Piksel Medijana(int x,int y) {
		
		int sumaR = 0,sumaG=0,sumaB=0;
		sumaR = getPixel(x - 1, y - 1).getR()+ getPixel(x , y - 1).getR()+ getPixel(x + 1, y - 1).getR()+ getPixel(x - 1, y ).getR()+
			getPixel(x , y ).getR()+
			getPixel(x + 1, y ).getR()+ getPixel(x - 1, y + 1).getR()+ getPixel(x , y+ 1).getR()+ getPixel(x+ 1, y + 1).getR();
		sumaG = getPixel(x - 1, y - 1).getG() + getPixel(x, y - 1).getG() + getPixel(x + 1, y - 1).getG() + getPixel(x - 1, y).getG() +
			getPixel(x, y).getG() +
			getPixel(x + 1, y).getG() + getPixel(x - 1, y + 1).getG() + getPixel(x, y + 1).getG() + getPixel(x + 1, y + 1).getG();
		sumaB = getPixel(x - 1, y - 1).getB() + getPixel(x, y - 1).getB() + getPixel(x + 1, y - 1).getB() + getPixel(x - 1, y).getB() +
			getPixel(x, y).getB() +
			getPixel(x + 1, y).getB() + getPixel(x - 1, y + 1).getB() + getPixel(x, y + 1).getB() + getPixel(x + 1, y + 1).getB();
		sumaR = sumaR / 9;
		sumaG = sumaG / 9;
		sumaB = sumaB / 9;
		return Piksel(sumaR, sumaG, sumaB);
		//getPixel(x, y).oboji(sumaR, sumaG, sumaB);
	}
	Piksel IvicaMedijana(int x, int y) {
		//slucaj kad je x == 0
		
		int sumaR = 0,sumaG=0, sumaB=0;
		if (x == 0) {
			if (y == 0) {
				//samo 4
				sumaR = getPixel(0, 0).getR() + getPixel(0, 1).getR() + getPixel(1, 0).getR()+ getPixel(1, 1).getR() ;
				sumaG = getPixel(0, 0).getG() + getPixel(0, 1).getG() + getPixel(1, 0).getG() + getPixel(1, 1).getG();
				sumaB = getPixel(0, 0).getB() + getPixel(0, 1).getB() + getPixel(1, 0).getB() + getPixel(1, 1).getB();
				sumaR = sumaR / 4;
				sumaG = sumaG / 4;
				sumaB = sumaB / 4;
				//getPixel(0, 0).oboji(sumaR, sumaG, sumaB);
				return Piksel(sumaR,sumaG,sumaB);
			}
			else if (y==visina-1){
				//samo 4 dole levo
				sumaR = getPixel(0, visina - 1).getR() + getPixel(0, visina - 2).getR() + getPixel(1, visina - 1).getR() + getPixel(1, visina - 2).getR();
				sumaG = getPixel(0, visina - 1).getG() + getPixel(0, visina - 2).getG() + getPixel(1, visina - 1).getG() + getPixel(1, visina - 2).getG();
				sumaB = getPixel(0, visina - 1).getB() + getPixel(0, visina - 2).getB() + getPixel(1, visina - 1).getB() + getPixel(1, visina - 2).getB();
				sumaR = sumaR / 4;
				sumaG = sumaG / 4;
				sumaB = sumaB / 4;
				//getPixel(x, y).oboji(sumaR, sumaG, sumaB);
				return Piksel(sumaR, sumaG, sumaB);
				
			}
			else {
				//normalnih 6
				sumaR = getPixel(0, y - 1).getR() + getPixel(0, y).getR() + getPixel(0, y + 1).getR() + 
					    getPixel(1, y - 1).getR() + getPixel(1, y).getR() + getPixel(1, y + 1).getR();
				sumaG = getPixel(0, y - 1).getG() + getPixel(0, y).getG() + getPixel(0, y + 1).getG() +
					    getPixel(1, y - 1).getG() + getPixel(1, y).getG() + getPixel(1, y + 1).getG();
				sumaB = getPixel(0, y - 1).getB() + getPixel(0, y).getB() + getPixel(0, y + 1).getB() +
					    getPixel(1, y - 1).getB() + getPixel(1, y).getB() + getPixel(1, y + 1).getB();
				sumaR = sumaR / 6;
				sumaG = sumaG / 6;
				sumaB = sumaB / 6;
				//getPixel(x, y).oboji(sumaR, sumaG, sumaB);
				return Piksel(sumaR, sumaG, sumaB);
			}
			 // da ne ide dalje u else
		}
		if (y == 0) {
			//samo 4
			if (x == sirina - 1) { //gore desno
				sumaR = getPixel(x, 0).getR() + getPixel(x, 1).getR() + getPixel(x-1, 0).getR() + getPixel(x-1, 1).getR();
				sumaG = getPixel(x, 0).getG() + getPixel(x, 1).getG() + getPixel(x-1, 0).getG() + getPixel(x-1, 1).getG();
				sumaB = getPixel(x, 0).getB() + getPixel(x, 1).getB() + getPixel(x-1, 0).getB() + getPixel(x-1, 1).getB();
				sumaR = sumaR / 4;
				sumaG = sumaG / 4;
				sumaB = sumaB / 4;
				//getPixel(x, y).oboji(sumaR, sumaG, sumaB);
				return Piksel(sumaR, sumaG, sumaB);
			}
			else {//6 normalnih
				sumaR = getPixel(x-1, 0).getR() + getPixel(x, 0).getR() + getPixel(x+1, 0).getR() +
					getPixel(x-1, 1).getR() + getPixel(x, 1).getR() + getPixel(x+1, 1).getR();
				sumaG = getPixel(x - 1, 0).getG() + getPixel(x, 0).getG() + getPixel(x + 1, 0).getG() +
					getPixel(x - 1, 1).getG() + getPixel(x, 1).getG() + getPixel(x + 1, 1).getG();
				sumaB = getPixel(x - 1, 0).getB() + getPixel(x, 0).getB() + getPixel(x + 1, 0).getB() +
					getPixel(x - 1, 1).getB() + getPixel(x, 1).getB() + getPixel(x + 1, 1).getB();
				sumaR = sumaR / 6;
				sumaG = sumaG / 6;
				sumaB = sumaB / 6;
				//getPixel(x, y).oboji(sumaR, sumaG, sumaB);
				return Piksel(sumaR, sumaG, sumaB);
			}
		}
		if (y == visina - 1) {
			if (x == sirina - 1) {
				//samo 4
				sumaR = getPixel(x, y).getR() + getPixel(x-1, y).getR() + getPixel(x - 1, y-1).getR() + getPixel(x , y-1).getR();
				sumaG = getPixel(x, y).getG() + getPixel(x - 1, y).getG() + getPixel(x - 1, y - 1).getG() + getPixel(x, y - 1).getG();
				sumaB = getPixel(x, y).getB() + getPixel(x - 1, y).getB() + getPixel(x - 1, y - 1).getB() + getPixel(x, y - 1).getB();
				sumaR = sumaR / 4;
				sumaG = sumaG / 4;
				sumaB = sumaB / 4;
			//	getPixel(x, y).oboji(sumaR, sumaG, sumaB);
				return Piksel(sumaR, sumaG, sumaB);
			}
			else {
				//normalnih 6
				sumaR = getPixel(x - 1, y).getR() + getPixel(x, y).getR() + getPixel(x + 1, y).getR() +
					getPixel(x - 1, y-1).getR() + getPixel(x, y-1).getR() + getPixel(x + 1, y-1).getR();
				sumaG = getPixel(x - 1, y).getG() + getPixel(x, y).getG() + getPixel(x + 1, y).getG() +
					getPixel(x - 1, y - 1).getG() + getPixel(x, y - 1).getG() + getPixel(x + 1, y - 1).getG();
				sumaB = getPixel(x - 1, y).getB() + getPixel(x, y).getB() + getPixel(x + 1, y).getB() +
					getPixel(x - 1, y - 1).getB() + getPixel(x, y - 1).getB() + getPixel(x + 1, y - 1).getB();
				sumaR = sumaR / 6;
				sumaG = sumaG / 6;
				sumaB = sumaB / 6;
			//	getPixel(x, y).oboji(sumaR, sumaG, sumaB);
				return Piksel(sumaR, sumaG, sumaB);
			}
		}
		 // desni deo
			//normalnih 6
		sumaR = getPixel(x ,y + 1).getR() + getPixel(x, y).getR() + getPixel(x ,y - 1).getR() +
			getPixel(x - 1, y + 1).getR() + getPixel(x - 1, y).getR() + getPixel(x - 1, y - 1).getR();
		sumaG = getPixel(x, y + 1).getG() + getPixel(x, y).getG() + getPixel(x, y - 1).getG() +
			getPixel(x - 1, y + 1).getG() + getPixel(x - 1, y).getG() + getPixel(x - 1, y - 1).getG();
		sumaB = getPixel(x, y + 1).getB() + getPixel(x, y).getB() + getPixel(x, y - 1).getB() +
			getPixel(x - 1, y + 1).getB() + getPixel(x - 1, y).getB() + getPixel(x - 1, y - 1).getB();
		sumaR = sumaR / 6;
		sumaG = sumaG / 6;
		sumaB = sumaB / 6;
		//getPixel(x, y).oboji(sumaR, sumaG, sumaB);
		return Piksel(sumaR, sumaG, sumaB);
		
	

	}
	bool normalnaMedijana(int x,int y) {
		return (x != 0 && y != 0 && x!=sirina-1 && y!=visina-1);
	}
	Layer* IzvrsiMedijanu() {
		Layer* nova = new Layer(*this);
		
		for (int i = 0; i < sirina; i++) {
			for (int j = 0; j < visina; j++) {
				Piksel p;
				if (nova->normalnaMedijana(i, j)) {
					//nova->Medijana(i, j);
					p=Medijana(i, j);
				}
				else {
					//nova->IvicaMedijana(i, j);
					p=IvicaMedijana(i, j);
				}
				nova->getPixel(i, j).oboji(p.getR(), p.getG(), p.getB());
			}
		}

		return nova;
	}


};
