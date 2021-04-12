#include "TablicaDynamiczna.h"
#include <iostream>
#include "Menu.h"

using namespace std;


/*
Tworzy tablicê dynamiczn¹
*/
TablicaDynamiczna::TablicaDynamiczna(int rozmiar, int tablica[]) {
	this->rozmiar = rozmiar;
	this->tablica = tablica;
}

/*
Inicjuje pust¹ tablicê
*/
TablicaDynamiczna::TablicaDynamiczna() {
	this->rozmiar = 0;
	tablica = NULL;
}

/*
Tworzy tablicê ze wczytanych danych
*/
TablicaDynamiczna::TablicaDynamiczna(const TablicaDynamiczna& tablica) {
	if (&tablica == NULL) {
		TablicaDynamiczna();
		return;
	}
	this->rozmiar = tablica.rozmiar;
	this->tablica = tablica.tablica;
	this->tablica = getTablicaKopia();

}



TablicaDynamiczna::~TablicaDynamiczna() {
	delete[] tablica;
	cout << "\nDestruktor tablica dynamiczna\n";
}

/*
Dodaje element na pocz¹tek tablicy dynamicznej
Korzysta z funkcji dodawania na konkretn¹ pozycjê
*/
void TablicaDynamiczna::dodajPoczatek(int liczba) {
	dodaj(liczba, 0);
}

/*
Dodaje element na koniec tablicy dynamicznej
Korzysta z funkcji dodawanie na konkretn¹ pozycjê
*/
void TablicaDynamiczna::dodajKoniec(int liczba) {
	dodaj(liczba, rozmiar);
}

/*
Dodaje na konkretn¹ pozycjê, powiêksza zaalokowany obszar o 1
*/
void TablicaDynamiczna::dodaj(int liczba, int pozycja) {
	if (pozycja > rozmiar || pozycja < 0) {
		throw exception("Poza zakresem");
	}
	rozmiar++;

	//tworzenie nowej wiêkszej tablicy
	int* temp = new int[rozmiar];

	//kopiowanie starej tablicy do nowej
	// i - indeksuje now¹ tablica
	// indeks - indeksuje star¹ tablicê
	for (int i = 0, indeks = 0; i < rozmiar; i++) {
		
		if (i == pozycja) {
			//wstawianie nowego elementu
			temp[i] = liczba;
		}
		else {
			temp[i] = tablica[indeks];
			indeks++;
		}
	}
	delete[] tablica;
	tablica = temp;
}

void TablicaDynamiczna::usunPoczatek() {
	usun(0);
}

void TablicaDynamiczna::usunKoniec() {
	usun(rozmiar - 1);
}

/*
Usuwa element na zadanej pozycji
*/
void TablicaDynamiczna::usun(int pozycja) {
	//sprawdzanie zakresu
	if (pozycja >= rozmiar || pozycja < 0) {
		throw exception("Poza zakresem");
	}

	rozmiar--;
	int* temp = NULL;
	if (rozmiar > 0) {
		//tworzenie nowej wiêkszej tablicy
		temp = new int[rozmiar];
	}

	//kopiowanie starej tablicy do nowej
	// i - indeksuje now¹ tablica
	// indeks - indeksuje star¹ tablicê
	for (int i = 0, indeks = 0; i < rozmiar; indeks++) {

		if (indeks == pozycja) {
			continue;
		}
		else {
			temp[i] = tablica[indeks];
			i++;
		}
	}
	delete[] tablica;
	tablica = temp;
}

/*
Wyszukiwanie elementu o zadanej wartoœci
*/
int TablicaDynamiczna::wyszukaj(int liczba) {
	for (int i = 0; i < rozmiar; i++) {
		if (tablica[i] == liczba) {
			return i;
		}
	}
	throw exception("Brak szukanego elementu");
}

/*
Wyœwietla zawartoœæ tablicy
*/
void TablicaDynamiczna::wyswietl() {

	cout << "[ ";
	for (int i = 0; i < rozmiar - 1; i++) {
		cout << tablica[i] << " , ";
	}
	if (rozmiar > 0) {
		cout << tablica[rozmiar - 1];
	}
	cout << " ]\n";
}

int TablicaDynamiczna::getRozmiar() {
	return rozmiar;
}

int* TablicaDynamiczna::getTablica() {
	return tablica;
}


/*
Kopiuje tablicê i zwraca do niej referencjê
*/
int* TablicaDynamiczna::getTablicaKopia() {
	int* tablicaKopia = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		tablicaKopia[i] = tablica[i];
	}
	return tablicaKopia;
}


/*
Zamienia wartoœci o podanych indeksach miejscami w tablicy
*/
void TablicaDynamiczna::zamien(int indeks1, int indeks2) {
	if (indeks1 >= rozmiar || indeks2 >= rozmiar) {
		throw exception("Poza zakresem");
	}
	int bufor = tablica[indeks1];
	tablica[indeks1] = tablica[indeks2];
	tablica[indeks2] = bufor;
}



