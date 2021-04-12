#include "WyswietlanieDrzewa.h"


/*
Drzewo jest definiowane przez wskaŸnik na korzeñ
ponadto do wyœwietlania jest pottrzebna wartoœæ maksymalnej szerokoœci elementu
*/
WyswietlanieDrzewa::WyswietlanieDrzewa(IPotomkowie* korzen, int maksymalnaSzerokosc) {
	this->korzen = korzen;
	this->maksymalnaSzerokosc = maksymalnaSzerokosc;
	linia = "+" + powielZnak('-', maksymalnaSzerokosc) + "+";
}

void WyswietlanieDrzewa::wyswietl() {
	if (korzen == NULL) {
		cout << "Drzewo jest puste\n";
		return;
	}
	TablicaString* drzewoStrings = getDrzewoStrings(korzen);
	for (int i = 0; i < drzewoStrings->rozmiar; i++) {
		cout << drzewoStrings->tablica[i] << endl;
	}
	zwolnijTablicaString(drzewoStrings);
}

TablicaString* WyswietlanieDrzewa::getDrzewoStrings(IPotomkowie* korzen) {
	//w tym przypadku jest to maksymalna liczba cyfr plus znak dla liczby int
	int szerokoscElementu = maksymalnaSzerokosc;
	TablicaString* wynik = new TablicaString;
	IPotomkowie* lewyPotomek = korzen->getLewyPotomek();
	IPotomkowie* prawyPotomek = korzen->getPrawyPotomek();
	
	if (lewyPotomek == NULL && prawyPotomek == NULL) {

		wynik->rozmiar = 3;
		wynik->indeksKorzenia = 1;
		wynik->tablica = new string[wynik->rozmiar];
		wynik->tablica[0] = linia;
		wynik->tablica[2] = linia;

		wynik->tablica[1] = wyrownajString(korzen->toString());
	}
	//pozosta³e poziomy
	else {
		TablicaString* prawePoddrzewo = NULL;
		TablicaString* lewePoddrzewo = NULL;
		wynik->rozmiar = 1;
		if (prawyPotomek != NULL) {
			prawePoddrzewo = getDrzewoStrings(prawyPotomek);
			wynik->rozmiar += prawePoddrzewo->rozmiar;
		}
		else {
			wynik->rozmiar++;
		}
		if (lewyPotomek != NULL) {
			lewePoddrzewo = getDrzewoStrings(lewyPotomek);
			wynik->rozmiar += lewePoddrzewo->rozmiar;
		}
		else {
			wynik->rozmiar++;
		}

		wynik->tablica = new string[wynik->rozmiar];

		int wynikIndeks = 0;
		if (prawyPotomek != NULL) {

			for (int i = 0; i < prawePoddrzewo->rozmiar; i++, wynikIndeks++) {

				//œrodek
				if (i == prawePoddrzewo->indeksKorzenia) {
					wynik->tablica[wynikIndeks] = powielZnak(' ', szerokoscElementu + 1) + "+-" + prawePoddrzewo->tablica[i];
				}
				//dolna czêœæ
				else if (i == prawePoddrzewo->rozmiar - 1) {
					wynik->tablica[wynikIndeks] = linia + " " + prawePoddrzewo->tablica[i];
				}
				//górna czêœæ
				else if (i < prawePoddrzewo->indeksKorzenia) {
					wynik->tablica[wynikIndeks] = powielZnak(' ', szerokoscElementu + 3) + prawePoddrzewo->tablica[i];
				}
				//pozosta³e
				else {
					wynik->tablica[wynikIndeks] = powielZnak(' ', szerokoscElementu + 1) + "| " + prawePoddrzewo->tablica[i];
				}
			}
			zwolnijTablicaString(prawePoddrzewo);
		}
		else {
			wynik->tablica[wynikIndeks] = linia + " ";
			wynikIndeks++;
		}

		//wprowadzanie nowej liczby
		wynik->tablica[wynikIndeks] = wyrownajString(korzen->toString());
		wynik->indeksKorzenia = wynikIndeks;
		wynikIndeks++;

		if (lewyPotomek != NULL) {

			for (int i = 0; i < lewePoddrzewo->rozmiar; i++, wynikIndeks++) {

				//œrodek
				if (i == lewePoddrzewo->indeksKorzenia) {
					wynik->tablica[wynikIndeks] = powielZnak(' ', szerokoscElementu + 1) + "+-" + lewePoddrzewo->tablica[i];
				}
				//górna czêœæ
				else if (i == 0) {
					wynik->tablica[wynikIndeks] = linia + " " + lewePoddrzewo->tablica[i];
				}
				//dolna czêœæ
				else if (i > lewePoddrzewo->indeksKorzenia) {
					wynik->tablica[wynikIndeks] = powielZnak(' ', szerokoscElementu + 3) + lewePoddrzewo->tablica[i];
				}
				//pozosta³e
				else {
					wynik->tablica[wynikIndeks] = powielZnak(' ', szerokoscElementu + 1) + "| " + lewePoddrzewo->tablica[i];
				}
			}
			zwolnijTablicaString(lewePoddrzewo);
		}
		else {
			wynik->tablica[wynikIndeks] = linia + " ";
			wynikIndeks++;
		}
	}
	delete korzen;
	return wynik;
}

/*
Tworzy stringa z liczby o sta³ej szerokoœci i dodaje zakoñczenia |
*/
string WyswietlanieDrzewa::wyrownajString(string liczbaString) {
	int rozmiarWypelnienia = maksymalnaSzerokosc - liczbaString.length();
	string wypelnienie = powielZnak(' ', rozmiarWypelnienia);
	return "|" + liczbaString + wypelnienie + "|";
}

string WyswietlanieDrzewa::powielZnak(char znak, int powtorzenia) {
	string wynik = "";
	for (int i = 0; i < powtorzenia; i++) {
		wynik += znak;
	}
	return wynik;
}

/*
Zwalnia pamiêæ zarezerwowan¹ przez instancjê TablicaString podaje w argumencie
*/
void WyswietlanieDrzewa::zwolnijTablicaString(TablicaString* tablica) {
	delete [] tablica->tablica;
	delete tablica;
}