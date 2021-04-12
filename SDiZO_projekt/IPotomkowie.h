#pragma once
#include <string>

using namespace std;
/*
Interfejs dla klas b¹d¹cych elemantami jakiegokolwiek drzewa.
Pozwala na wy³uskiwanie potomków
*/
class IPotomkowie {
public:
	virtual IPotomkowie* getLewyPotomek() = 0;
	virtual IPotomkowie* getPrawyPotomek() = 0;
	virtual string toString() = 0;
};

