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
#include "Drzewo.h"
#include "Testy.h"
#include "STLList.h"
#include "STLVector.h"


using namespace std;


int liczbaOpcji = 10;
string opcje[] = { "tablica dynamiczna", "lista", "kopiec", "BST", "drzewo czerwono-czarne", "drzewo AVL", "dane", "przeprowadü testy (kilka godzin)", "STL list", "STL vector" };

TablicaDynamiczna* daneTablica = new TablicaDynamiczna();


int main() {
	setlocale(LC_ALL, "polish");
	cout << "+--------------------------------------------------------------------------+" << endl;
	cout << "| SDiZO - zadanie projektowe nr 1                                          |" << endl;
	cout << "| Autor: Miko≥aj Chmielecki                                                |" << endl;
	cout << "| Data realizacji projektu: 2021-04-26                                     |" << endl;
	cout << "| W menu Dane wczytujemy dane, menu Tablica dynamiczna oraz Kopiec         |" << endl;
	cout << "| zmieniajπ dane wczytane do programu i przekazujπ je do Menu g≥Ûwnego     |" << endl;
	cout << "+--------------------------------------------------------------------------+" << endl;

	Menu menu = Menu(liczbaOpcji, opcje, "Menu g≥Ûwne");
	while (menu.czyUruchomione()) {
		switch (menu.wyswietl()) {
		case 0:
		{
			//tablica zmienia daneTablica
			TablicaDynamiczna* tablica = daneTablica;
			IStrukturyLiniowe * iTablica = tablica;
			MenuStrukturyLiniowe menuTablica = MenuStrukturyLiniowe(iTablica, "Tablica dynamiczna");
			menuTablica.menu();
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
			//kopiec zmienia daneTablica
			Kopiec* kopiec = new Kopiec(daneTablica);
			IStrukturyDrzewiaste* iKopiec = kopiec;
			MenuStrukturyDrzewiaste menuKopiec = MenuStrukturyDrzewiaste(iKopiec, "Kopiec");
			menuKopiec.menu();
			delete kopiec;
		}
			break;
		case 3:
		{
			Drzewo* bst = new Drzewo(daneTablica, Typ::BST);
			IStrukturyDrzewiaste* iBST = bst;
			MenuStrukturyDrzewiaste menuBST = MenuStrukturyDrzewiaste(iBST, "BST");
			menuBST.menu();
			delete bst;
		}
		break;
		case 4:
		{
			Drzewo* rb = new Drzewo(daneTablica, Typ::RB);
			IStrukturyDrzewiaste* iRB = rb;
			MenuStrukturyDrzewiaste menuRB = MenuStrukturyDrzewiaste(iRB, "RB");
			menuRB.menu();
			delete rb;
		}
		break;
		case 5:
		{
			Drzewo* avl = new Drzewo(daneTablica, Typ::AVL);
			IStrukturyDrzewiaste* iAVL = avl;
			MenuStrukturyDrzewiaste menuAVL = MenuStrukturyDrzewiaste(iAVL, "AVL");
			menuAVL.menu();
			delete avl;
		}
		break;
		
		
		case 6:
		{
			Dane dane = Dane(daneTablica);
			dane.menu();
			daneTablica = dane.getTablica();
			
		}
		break;
		case 7:
		{
			Testy* testy = new Testy();
			testy->wykonajTesty();
			delete testy;
		}
		break;
		case 8:
		{
			STLList* list = new STLList(daneTablica);
			IStrukturyLiniowe* iList = list;
			MenuStrukturyLiniowe menuList = MenuStrukturyLiniowe(iList, "STL List");
			menuList.menu();
			delete list;
		}
		break;
		case 9:
		{
			STLVector* vector = new STLVector(daneTablica);
			IStrukturyLiniowe* iVector = vector;
			MenuStrukturyLiniowe menuVector = MenuStrukturyLiniowe(iVector, "STL Vector");
			menuVector.menu();
			delete vector;
		}
		break;
		}
	}
	delete daneTablica;
}

