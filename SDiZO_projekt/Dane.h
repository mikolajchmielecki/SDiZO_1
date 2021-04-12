#include<string>
#include "TablicaDynamiczna.h"

using namespace std;
#pragma once
class Dane {
public:
	Dane();
	TablicaDynamiczna* getTablica();
	void menu();
	
private:
	void ustawSciezke();
	void wczytaj();
	string * menuString;
	int liczbaOpcji;
	TablicaDynamiczna* tablica;
	string sciezka;
};

