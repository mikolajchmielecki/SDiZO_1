#include <string>
#include "IStrukturyDrzewiaste.h"
#include "MenuStrukturyLiniowe.h"
#pragma once
using namespace std;

/*
Klasa wyœwietla menu kontekstowe do struktur drzewiastych (kopiec, BST, RB, AVL)
*/
class MenuStrukturyDrzewiaste{
public:
	MenuStrukturyDrzewiaste(IStrukturyDrzewiaste*, string);
	void menu();

private:
	void dodajMenu();
	void usunMenu();
	void wyszukajMenu();
	IStrukturyDrzewiaste* struktura;
	string nazwa;
};

