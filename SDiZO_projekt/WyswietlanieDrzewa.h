#pragma once
#include "IPotomkowie.h"
#include <iostream>

using namespace std;

struct TablicaString {
	int rozmiar;
	int indeksKorzenia;
	string* tablica;
};


/*
Klasa odpowiada za wyœwietlanie ró¿nego rodzaju drzew na podstawie korzenia
*/
class WyswietlanieDrzewa {
public:
	WyswietlanieDrzewa(IPotomkowie*);
	void wyswietl(bool zwalniajPamiec);
private:
	int maksymalnaSzerokosc;
	IPotomkowie* korzen;
	TablicaString* getDrzewoStrings(IPotomkowie*, bool);
	string linia;
	string wyrownajString(string);
	string powielZnak(char, int);
	void zwolnijTablicaString(TablicaString*);
};

