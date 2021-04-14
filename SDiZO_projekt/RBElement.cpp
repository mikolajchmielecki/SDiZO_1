#include "RBElement.h"

RBElement::RBElement(int liczba, BSTElement* rodzic, BST* bst, Kolor kolor) : BSTElement(liczba, rodzic, bst) {
	this->kolor = kolor;
}

/*
Szerokość elementu drzewa BST powiększona o 3 -> " :R" lub " :B"
*/
int RBElement::getMaksymalnaSzerokosc() {
	return BSTElement::getMaksymalnaSzerokosc()+3;
}

/*
String BSTElement rozszerzony o infromację o kolorze
*/
string RBElement::toString() {
	string kolorString = "";
	if (kolor == czarny) {
		kolorString += " :B";
	}
	else if (kolor == czerwony) {
		kolorString = " :R";
	}
	return BSTElement::toString()+kolorString;
}
