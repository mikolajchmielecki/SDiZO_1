#include "MenuStrukturyDrzewiaste.h"
#include "Menu.h"
#include <iostream>
#include "Kopiec.h"




MenuStrukturyDrzewiaste::MenuStrukturyDrzewiaste(IStrukturyDrzewiaste* struktura, string nazwa) {
	this->struktura = struktura;
	this->nazwa = nazwa;
}


/*
Wyœwietla menu i zarz¹dza przebiegiem sterowania
*/
void MenuStrukturyDrzewiaste::menu() {
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
Menu wprowadzania nowej liczby do struktury
*/
void MenuStrukturyDrzewiaste::dodajMenu() {

	string nazwy[] = { "WprowadŸ liczbê: "};
	int* wejscie = MenuStrukturyLiniowe::wprowadzanie(1, nazwy);
	struktura->dodaj(wejscie[0]);
	delete[] wejscie;
}


/*
Sprawdzanie czy dany obiekt jest klasy T 
*/
template<typename Base, typename T>
inline bool instanceof(const T* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}

/*
Ob³uguje usuwanie elementu z struktury
*/
void MenuStrukturyDrzewiaste::usunMenu() {
	if (instanceof<Kopiec>(struktura)) {
		struktura->usun();
	}
	else {
		string nazwy[] = { "WprowadŸ liczbê do usuniêcia: " };
		int* wejscie = MenuStrukturyLiniowe::wprowadzanie(1, nazwy);
		try {
			struktura->usun(wejscie[0]);
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
		delete[] wejscie;
	}

}

void MenuStrukturyDrzewiaste::wyszukajMenu() {
	string nazwy[] = { "WprowadŸ wyszukiwan¹ liczbê: " };
	int* wejscie = MenuStrukturyLiniowe::wprowadzanie(1, nazwy);


	try {
		int result = (*struktura).wyszukaj(wejscie[0], true);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	delete[] wejscie;
}

