#pragma once
#include "IStrukturyDrzewiaste.h"
#include "DrzewoElement.h"
#include "TablicaDynamiczna.h"



/*
Klasa implementuj¹ca operacje na drzewie BST
*/
class Drzewo : public IStrukturyDrzewiaste {
public:
	Drzewo(TablicaDynamiczna* tablica, Typ typ);
	~Drzewo();
	virtual void dodaj(int liczba);
	
	virtual void usun(int liczba);
	virtual int wyszukaj(int liczba, bool wyswietlanie);
	
	virtual void wyswietl();
	
private:
	DrzewoElement* utworzSciezkeDoKorzenia(DrzewoElement* element);
	DrzewoElement* korzen;
	Typ typ;
	void utworzDrzewo(TablicaDynamiczna* tablica);
	void umiescElement(int liczba);
	DrzewoElement* utworzElement(int liczba);
	DrzewoElement* wyszukajDrzewo(int liczba);
	void usunRB(DrzewoElement* usuwanyElement);
	void usunBST(DrzewoElement* element);
	void umiescElement(DrzewoElement*);
	void naprawRB(DrzewoElement*);
	void rotacjaPrawa(DrzewoElement*);
	void rotacjaLewa(DrzewoElement*);
	DrzewoElement* getNastepnik(DrzewoElement*);
};


