#include <string>
#include "IStrukturyLiniowe.h"
#pragma once
using namespace std;

/*
Klasa wyœwietla menu kontekstowe do struktur liniowych (tablica i lista)
*/
class MenuStrukturyLiniowe {
public:
	MenuStrukturyLiniowe(IStrukturyLiniowe*, string);
	void menu();
	static int* wprowadzanie(int, string*);


private:
	void dodajMenu();
	void usunMenu();
	void wyszukajMenu();
	
	IStrukturyLiniowe* struktura;
	string nazwa;
};

