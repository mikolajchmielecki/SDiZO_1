#pragma once
#include "IPotomkowie.h"
#include "Typy.h"


class DrzewoElement : public IPotomkowie {
public:
	DrzewoElement(int, DrzewoElement*, Typ);
	DrzewoElement(const DrzewoElement& drzewoElement);
	void usunPodrzewo();
	virtual DrzewoElement* getLewyPotomek();
	virtual DrzewoElement* getPrawyPotomek();
	virtual string toString();
	virtual int getMaksymalnaSzerokosc();
	void aktualizujWysokosc();
	DrzewoElement* getBrat();
	int getWywazenie();
	int liczba;
	DrzewoElement* rodzic;
	DrzewoElement* lewyPotomek;
	DrzewoElement* prawyPotomek;
	Typ typ;
	Kolor kolor;
	int wysokosc;
	int getMax(int, int);
};

