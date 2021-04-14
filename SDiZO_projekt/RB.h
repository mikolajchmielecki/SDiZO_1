#pragma once
#include "BST.h"
#include "RBElement.h"


/*
Klasa implementuj¹ca dzia³anie drzewa czerwono-czarnego
*/
class RB : public BST{
public:
	RB(TablicaDynamiczna* tablica);
	//~RB();
	virtual void dodaj(int liczba);

	virtual void usun(int liczba);
	virtual int wyszukaj(int liczba, bool wyswietlanie);
	virtual void wyswietl();

protected:
	void utworzDrzewo(TablicaDynamiczna* tablica);
	virtual RBElement* utworzElement(int liczba);
	virtual void umiescElement(RBElement*);

};

