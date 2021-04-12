#include "Dane.h"
#include <fstream>
#include <iostream>
#include "Menu.h"

using namespace std;

/*
Klasa odpowiada za wczytywanie danych z pliku tekstowego.
Dane s� wczytywane do tablicy dynamicznej
*/

Dane::Dane() {
	liczbaOpcji = 2;
	
	this->sciezka = "c:/dane.txt";
	

}

void Dane::menu() {
	string tablica[] = { "wczytaj dane", "ustaw �cie�k�" };
	Menu menu = Menu(liczbaOpcji, tablica, "Dane");
	while (menu.czyUruchomione()) {
		switch (menu.wyswietl()) {
		case 0:
			try {
				wczytaj();
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		case 1:
			ustawSciezke();
			break;
		} 
	}
}


void Dane::ustawSciezke() {
	cout << "Wprowad� �cie�k�: ";
	cin >> sciezka;
}

/*
Wczytywanie danych z pliku
Zwraca dane w tablicy dynamicznej
*/
void Dane::wczytaj() {
	ifstream plik;
	plik.open(sciezka);
	int rozmiar = 0;
	int* tablica;
	int liczba;
	if (plik.is_open()) {
		//wczytywanie rozmiaru
		plik >> rozmiar;
		if (plik.fail())
			throw exception("B��d wczytania rozmiaru danych z pliku");
		else {
			//alokacja pami�ci na dane
			tablica = new int[rozmiar];

			//wczytywanie kolejnych warto�ci
			for (int i = 0; i < rozmiar; i++) {
				plik >> liczba;
				if (plik.fail()) {
					throw exception("B��d wczytania warto�ci z pliku");
				}
				else {
					tablica[i] = liczba;
				}
			}
		}
		this->tablica = new TablicaDynamiczna(rozmiar, tablica);
		plik.close();
	}
	else
		throw exception("B��d otwartcia pliku");
	
}


TablicaDynamiczna* Dane::getTablica() {
	return tablica;
}



