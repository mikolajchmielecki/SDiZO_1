#pragma once
/*
Okreœla typ drzewa i elementu drzewa
*/
enum class Typ { BST, RB, AVL };


/*
Okreœla kolor drzewa czerwono-czarnego
*/
enum class Kolor { RED, BLACK };

/*
Typ operacji w przeprowadzanych testach
*/
enum class Operacja {
	TablicaUsunPoczatek, TablicaUsunKoniec, TablicaUsunSrodek, TablicaDodajPoczatek, TablicaDodajKoniec, TablicaDodajSrodek, TablicaWyszukaj,
	ListaUsunPoczatek, ListaUsunKoniec, ListaUsunSrodek, ListaDodajPoczatek, ListaDodajKoniec, ListaDodajSrodek, ListaWyszukaj,
	KopiecUsun, KopiecDodaj, KopiecWyszukaj,
	RBUsun, RBDodaj, RBWyszukaj,
	AVLUsun, AVLDodaj, AVLWyszukaj,
	STLListUsunPoczatek, STLListUsunKoniec, STLListUsunSrodek, STLListDodajPoczatek, STLListDodajKoniec, STLListDodajSrodek, STLListWyszukaj,
	STLVectorUsunPoczatek, STLVectorUsunKoniec, STLVectorUsunSrodek, STLVectorDodajPoczatek, STLVectorDodajKoniec, STLVectorDodajSrodek, STLVectorWyszukaj

};