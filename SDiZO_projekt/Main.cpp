#include<iostream>
#include<locale.h>
#include<string>
#include "TablicaDynamiczna.h"
#include "Dane.h"
#include "Menu.h"
#include "MenuStrukturyLiniowe.h"
#include "MenuStrukturyDrzewiaste.h"
#include "Lista.h"
#include "Kopiec.h"

using namespace std;


int liczbaOpcji = 6;
string opcje[] = { "tablica dynamiczna", "lista", "kopiec", "drzewo BST", "drzewo czerwono-czarne", "dane" };

TablicaDynamiczna* daneTablica;


int main() {
	setlocale(LC_ALL, "polish");
	
	cout << "SDiZO projekt\n";
	Menu menu = Menu(liczbaOpcji, opcje, "Menu g³ówne");
	while (menu.czyUruchomione()) {
		switch (menu.wyswietl()) {
		case 0:
		{
			TablicaDynamiczna* tablica = new TablicaDynamiczna(*daneTablica);
			IStrukturyLiniowe * iTablica = tablica;
			MenuStrukturyLiniowe menuTablica = MenuStrukturyLiniowe(iTablica, "Tablica dynamiczna");
			menuTablica.menu();
			delete tablica;
		}
			break;
		case 1:
		{
			Lista* lista = new Lista(daneTablica);
			IStrukturyLiniowe* iLista = lista;
			MenuStrukturyLiniowe menuLista = MenuStrukturyLiniowe(iLista, "Lista dwukierunkowa");
			menuLista.menu();
			delete lista;

		}
			break;
		
		case 2:
		{
			Kopiec* kopiec = new Kopiec(daneTablica);
			IStrukturyDrzewiaste* iKopiec = kopiec;
			MenuStrukturyDrzewiaste menuKopiec = MenuStrukturyDrzewiaste(iKopiec, "Kopiec");
			menuKopiec.menu();
			delete kopiec;
		}
			break;
		
		
		case 5:
			Dane dane = Dane();
			dane.menu();
			daneTablica = dane.getTablica();
			break;
		}
	}
	delete daneTablica;
}

