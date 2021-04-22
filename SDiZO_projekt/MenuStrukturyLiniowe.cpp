#include "MenuStrukturyLiniowe.h"
#include "Menu.h"
#include <iostream>





MenuStrukturyLiniowe::MenuStrukturyLiniowe(IStrukturyLiniowe* struktura, string nazwa) {
	this->struktura = struktura;
	this->nazwa = nazwa;
}



/*
Wyœwietla menu i zarz¹dza przebiegiem sterowania
*/
void MenuStrukturyLiniowe::menu() {
	string opcje[] = { "wyœwietl", "dodaj", "usuñ", "wyszukaj" };
	int liczbaOpcji = 4;
	Menu menu = Menu(liczbaOpcji, opcje, nazwa);
	while (menu.czyUruchomione()) {
		int result = menu.wyswietl();
		switch (result) {
		case 0:
			(*struktura).wyswietl();
			break;
		case 1:
			try {
				dodajMenu();
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		case 2:
			try {
				usunMenu();
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		case 3:
			wyszukajMenu();

		}
		if (result != 0 && result != -1 && result != 3) {
			(*struktura).wyswietl();
		}
	}
}


/*
Menu wprowadzania nowej liczby do tablicy
*/
void MenuStrukturyLiniowe::dodajMenu() {

	string nazwy[] = { "WprowadŸ liczbê: ", "WprowadŸ pozycjê (0 - pocz¹tek, -1 - koniec): " };
	int* wejscie = wprowadzanie(2, nazwy);



	if (wejscie[1] == -1) {
		(*struktura).dodajKoniec(wejscie[0]);
	}
	else if (wejscie[1] == 0) {
		(*struktura).dodajPoczatek(wejscie[0]);
	} else {
		(*struktura).dodaj(wejscie[0], wejscie[1]);
	}
	delete[] wejscie;
}


/*
Ob³uguje usuwanie elementu z tablicy
*/
void MenuStrukturyLiniowe::usunMenu() {
	string nazwy[] = { "WprowadŸ pozycjê (0 - pocz¹tek, -1 - koniec): " };
	int* wejscie = wprowadzanie(1, nazwy);



	if (wejscie[0] == -1) {
		(*struktura).usunKoniec();
	}
	else if (wejscie[0] == 0) {
		(*struktura).usunPoczatek();
	}
	else {
		(*struktura).usun(wejscie[0]);
	}
	delete[] wejscie;
}

void MenuStrukturyLiniowe::wyszukajMenu() {
	string nazwy[] = { "WprowadŸ wyszukiwan¹ liczbê: " };
	int* wejscie = wprowadzanie(1, nazwy);


	try {
		int result = (*struktura).wyszukaj(wejscie[0]);
		cout << "Indeks wyszukiwanej liczby to: " << result << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	delete[] wejscie;
}


/*
Os³uguje wprowadzanie wielu wartoœci liczbowych
Wyœwietla nag³owki podane jako argument w tablicy
Przekazuje dalej wprowadzone wartoœci w tablicy
*/
int* MenuStrukturyLiniowe::wprowadzanie(int liczbaWartosci, string* nazwy) {
	int* tablica = new int[liczbaWartosci];
	for (int i = 0; i < liczbaWartosci; i++) {
		cout << nazwy[i];
		int liczba = 0;

		string temp;
		bool valid = false;
		while (!valid) {
			cin >> temp;
			try {
				tablica[i] = stoi(temp);
				valid = true;
			}
			catch (exception) {
				cout << nazwy[i];
			}
		}

	}
	return tablica;

}