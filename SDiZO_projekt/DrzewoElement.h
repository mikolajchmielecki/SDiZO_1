#pragma once
#include "IPotomkowie.h"
#include "Typy.h"


class DrzewoElement : public IPotomkowie {
public:
	DrzewoElement(int, DrzewoElement*, Typ);
	DrzewoElement(const DrzewoElement& drzewoElement);
	~DrzewoElement();
	virtual DrzewoElement* getLewyPotomek();
	virtual DrzewoElement* getPrawyPotomek();
	virtual string toString();
	virtual int getMaksymalnaSzerokosc();
	DrzewoElement* getBrat();
	int liczba;
	DrzewoElement* rodzic;
	DrzewoElement* lewyPotomek;
	DrzewoElement* prawyPotomek;
	Typ typ;
	Kolor kolor;
};

