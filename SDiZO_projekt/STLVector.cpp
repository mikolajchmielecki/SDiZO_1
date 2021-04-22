#include "STLList.h"
#include <iostream>
//wyszukiwanie w liscie
#include <algorithm>
using namespace std;

/*
Inicjowanie listy
*/
STLList::STLList(TablicaDynamiczna* dane) {
	int rozmiar = dane->getRozmiar();
	//dodawanie do listy
	for (int i = rozmiar - 1; i >= 0; i--) {
		lista.push_back(dane->getTablica()[i]);
	}
}

void STLList::dodajPoczatek(int liczba) {
	lista.push_front(liczba);
}

void STLList::dodajKoniec(int liczba) {
	lista.push_back(liczba);
}

void STLList::dodaj(int liczba, int pozycja) {
	list<int>::iterator it = lista.begin();
	advance(it, pozycja);
	lista.insert(it, liczba);

}


int STLList::wyszukaj(int liczba) {
	list<int>::iterator it;
	it = find(lista.begin(), lista.end(), liczba);
	if (it != lista.end())
	{

		return distance(lista.begin(), it);
	}
	else
	{
		throw exception("Brak szukanego elementu");
	}
}

void STLList::usunPoczatek() {
	lista.pop_front();
}
void STLList::usunKoniec() {
	lista.pop_back();
}
void STLList::usun(int pozycja) {
	list<int>::iterator it = lista.begin();
	advance(it, pozycja);
	lista.erase(it);
}

void STLList::wyswietl() {
	cout << "[ ";
	for (list<int>::iterator i = lista.begin(); i != lista.end(); i++) {
		cout << *i << " ";
	}
	cout << "]";
}