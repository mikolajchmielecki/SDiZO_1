#pragma once
#include "TablicaDynamiczna.h"
#include "IPotomkowie.h"

class KopiecElement : public IPotomkowie {
public:
	KopiecElement();
	KopiecElement(TablicaDynamiczna*, int);
	virtual KopiecElement* getLewyPotomek();
	virtual KopiecElement* getPrawyPotomek();
	virtual string toString();
protected:
	TablicaDynamiczna* tablica;
	int indeks;
};



