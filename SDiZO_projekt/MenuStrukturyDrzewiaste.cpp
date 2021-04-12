#include "MenuStrukturyDrzewiaste.h"
#include "Menu.h"
#include <iostream>




MenuStrukturyDrzewiaste::MenuStrukturyDrzewiaste(IStrukturyDrzewiaste* struktura, string nazwa) {
	this->struktura = struktura;
	this->nazwa = nazwa;
}


/*
Wy�wietla menu i zarz�dza przebiegiem sterowania
*/
void MenuStrukturyDrzewiaste::menu() {
	string opcje[] = { "wy�wietl", "dodaj", "usu�", "wyszukaj" };
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
Menu wprowadzania nowej liczby do struktury
*/
void MenuStrukturyDrzewiaste::dodajMenu() {

	string nazwy[] = { "Wprowad� liczb�: "};
	int* wejscie = MenuStrukturyLiniowe::wprowadzanie(1, nazwy);
	struktura->dodaj(wejscie[0]);
	delete[] wejscie;
}


/*
Ob�uguje usuwanie elementu z struktury
*/
void MenuStrukturyDrzewiaste::usunMenu() {
	struktura->usun();
}

void MenuStrukturyDrzewiaste::wyszukajMenu() {
	string nazwy[] = { "Wprowad� wyszukiwan� liczb�: " };
	int* wejscie = MenuStrukturyLiniowe::wprowadzanie(1, nazwy);


	try {
		int result = (*struktura).wyszukaj(wejscie[0], true);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	delete[] wejscie;
}

