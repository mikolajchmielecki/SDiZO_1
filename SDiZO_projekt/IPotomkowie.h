#pragma once
#include <string>

using namespace std;
/*
Interfejs dla klas b�d�cych elemantami jakiegokolwiek drzewa.
Pozwala na wy�uskiwanie potomk�w
*/
class IPotomkowie {
public:
	virtual IPotomkowie* getLewyPotomek() = 0;
	virtual IPotomkowie* getPrawyPotomek() = 0;
	virtual string toString() = 0;
};

