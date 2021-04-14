#pragma once
#include "BSTElement.h"

enum Kolor {czarny, czerwony};

class RBElement : public DrzewoElement {
public:
	RBElement(int, DrzewoElement*, BST*, Kolor = czerwony);
	Kolor kolor;
	virtual int getMaksymalnaSzerokosc();
	virtual string toString();
};

