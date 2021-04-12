#include "KopiecElementWyszukiwanie.h"
#include <iostream>

using namespace std;


/*
Pierwsze u¿ycie, dla korzenia
*/
KopiecElementWyszukiwanie::KopiecElementWyszukiwanie(TablicaDynamiczna* tablica, int cel) {
	
	this->indeks = 0;
	this->tablica = tablica;
	utworzSciezke(cel);
}

/*
Kolejne u¿ycia, dla g³êbszych punktów, kiedy znana jest ju¿ œcie¿ka
*/
KopiecElementWyszukiwanie::KopiecElementWyszukiwanie(TablicaDynamiczna* tablica, int indeks,  int* sciezka, int dlugoscSciezki) {
	this->indeks = indeks;
	this->tablica = tablica;
	this->sciezka = sciezka;
	this->dlugoscSciezki = dlugoscSciezki;
}


KopiecElementWyszukiwanie* KopiecElementWyszukiwanie::getLewyPotomek() {
	int indeksPotomka = indeks * 2 + 1;
	for (int i = 0; i < dlugoscSciezki - 1; i++) {
		if (sciezka[i] == indeks && sciezka[i+1] == indeksPotomka) {
			return new KopiecElementWyszukiwanie(tablica, indeksPotomka, sciezka, dlugoscSciezki);
		}
	}
	return NULL;
}

KopiecElementWyszukiwanie* KopiecElementWyszukiwanie::getPrawyPotomek() {
	int indeksPotomka = indeks * 2 + 2;
	for (int i = 0; i < dlugoscSciezki - 1; i++) {
		if (sciezka[i] == indeks && sciezka[i + 1] == indeksPotomka) {
			return new KopiecElementWyszukiwanie(tablica, indeksPotomka, sciezka, dlugoscSciezki);
		}
	}
	return NULL;
}


/*
Tworzy œcie¿kê do celu w tablicy
W indeksie 0 jest korzeñ
*/
void KopiecElementWyszukiwanie::utworzSciezke(int cel) {
	dlugoscSciezki = ceil(log2(cel + 2));
	sciezka = new int[dlugoscSciezki];
	int indeks = cel;
	for (int i = dlugoscSciezki - 1 ; i >= 0; i--) {
		sciezka[i] = indeks;
		indeks = (indeks - 1) / 2;
	}
}
