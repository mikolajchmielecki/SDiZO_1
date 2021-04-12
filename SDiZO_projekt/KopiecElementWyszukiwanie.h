#pragma once
#include "KopiecElement.h"
#include "TablicaDynamiczna.h"

class KopiecElementWyszukiwanie : public KopiecElement {
public:
	KopiecElementWyszukiwanie(TablicaDynamiczna*, int);
	KopiecElementWyszukiwanie(TablicaDynamiczna*, int, int*, int);
	virtual KopiecElementWyszukiwanie* getLewyPotomek();
	virtual KopiecElementWyszukiwanie* getPrawyPotomek();
	int* sciezka;
private:
	int dlugoscSciezki;
	void utworzSciezke(int);
};
