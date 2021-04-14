#pragma once
#include "TablicaDynamiczna.h"
#include "IPotomkowie.h"

class KopiecElement : public IPotomkowie {
public:
	static const int szerokosc = 11;
	KopiecElement();
	KopiecElement(TablicaDynamiczna*, int);
	virtual KopiecElement* getLewyPotomek();
	virtual KopiecElement* getPrawyPotomek();
	virtual string toString();
	virtual int getMaksymalnaSzerokosc();
protected:
	TablicaDynamiczna* tablica;
	int indeks;
};



