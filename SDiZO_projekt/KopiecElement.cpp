#include "KopiecElement.h"
#include "KopiecElementWyszukiwanie.h"

KopiecElement::KopiecElement() {
	this->tablica = new TablicaDynamiczna();
	this->indeks = 0;
}

KopiecElement::KopiecElement(TablicaDynamiczna* tablica, int indeks) {
	this->tablica = tablica;
	this->indeks = indeks;
}

KopiecElement* KopiecElement::getLewyPotomek() {
	if (indeks * 2 + 1 < tablica->getRozmiar()) {
		return new KopiecElement(tablica, indeks * 2 + 1);
	}
	return NULL;
}

KopiecElement* KopiecElement::getPrawyPotomek() {
	if (indeks * 2 + 2 < tablica->getRozmiar()) {
		return new KopiecElement(tablica, indeks * 2 + 2);
	}
	return NULL;
}

/*
Zwraca wartoœæ jako string
*/
string KopiecElement::toString() {
	return to_string(tablica->getTablica()[indeks]);
}

int KopiecElement::getMaksymalnaSzerokosc() {
	return 11;
}

