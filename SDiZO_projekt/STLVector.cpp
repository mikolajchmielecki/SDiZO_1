#include "STLVector.h"
#include <iostream>
//wyszukiwanie w liscie
#include <algorithm>
#include <cassert>
using namespace std;

/*
Inicjowanie listy
*/
STLVector::STLVector(TablicaDynamiczna* dane) {
	int rozmiar = dane->getRozmiar();
	//dodawanie do listy
	for (int i = rozmiar - 1; i >= 0; i--) {
		tablica.push_back(dane->getTablica()[i]);
	}
}

void STLVector::dodajPoczatek(int liczba) {
	tablica.insert(tablica.begin(), 1, liczba);
}

void STLVector::dodajKoniec(int liczba) {
	tablica.push_back(liczba);
}

void STLVector::dodaj(int liczba, int pozycja) {
	vector<int>::iterator it = tablica.begin();
	advance(it, pozycja);
	tablica.insert(it, liczba);

}


int STLVector::wyszukaj(int liczba) {
	vector<int>::iterator it;
	it = find(tablica.begin(), tablica.end(), liczba);
	if (it != tablica.end())
	{

		return distance(tablica.begin(), it);
	}
	else
	{
		throw exception("Brak szukanego elementu");
	}
}

void STLVector::usunPoczatek() {
	assert(!tablica.empty());
	tablica.erase(tablica.begin());
}
void STLVector::usunKoniec() {
	tablica.pop_back();
}
void STLVector::usun(int pozycja) {
	vector<int>::iterator it = tablica.begin();
	advance(it, pozycja);
	tablica.erase(it);
}

void STLVector::wyswietl() {
	cout << "[ ";
	for (vector<int>::iterator i = tablica.begin(); i != tablica.end(); i++) {
		cout << *i << " ";
	}
	cout << "]";
}