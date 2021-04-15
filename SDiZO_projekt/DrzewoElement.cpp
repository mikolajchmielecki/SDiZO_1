#include "DrzewoElement.h"




DrzewoElement::DrzewoElement(int liczba, DrzewoElement* rodzic, Typ typ) {
    this->liczba = liczba;
    this->prawyPotomek = NULL;
    this->lewyPotomek = NULL;
    this->rodzic = rodzic;
    this->typ = typ;
    //Kolor za ka¿dym razem inicjowany na kolo RED
    this->kolor = Kolor::RED;
}

/*
Konstruktor kopiuj¹cy wykorzystywany do tworzenia œcie¿ki od znalezionego elementu do korzenia
*/
DrzewoElement::DrzewoElement(const DrzewoElement& drzewoElement) {
    this->liczba = drzewoElement.liczba;
    this->prawyPotomek = NULL;
    this->lewyPotomek = NULL;
    this->rodzic = NULL;
    this->typ = drzewoElement.typ;
    this->kolor =drzewoElement.kolor;
}

void DrzewoElement::usunPodrzewo() {
    if (lewyPotomek != NULL) {
        delete lewyPotomek;
    }
    if (prawyPotomek != NULL) {
        delete prawyPotomek;
    }
}

DrzewoElement* DrzewoElement::getLewyPotomek() {
    return lewyPotomek;
}

DrzewoElement* DrzewoElement::getPrawyPotomek() {
    return prawyPotomek;
}

/*
Zwraca reprezentacjê tekstow¹ danego wierzcho³ka
*/
string DrzewoElement::toString() {
    string wynik = "";
    if (typ == Typ::RB) {
        if (kolor == Kolor::BLACK) {
            wynik += "B: ";
        }
        else if (kolor == Kolor::RED) {
            wynik += "R: ";
        }
    }
    wynik += to_string(liczba);
    
    return wynik;
}

/*
Zwraca maksymaln¹ szerokoœæ pojedycznego elementu drzewa
*/
int DrzewoElement::getMaksymalnaSzerokosc() {
    int szerokoscBST = 11;
    if (typ == Typ::BST) {
        return szerokoscBST;
    }
    else if (typ == Typ::RB) {
        return szerokoscBST + 3;
    }
    
}

DrzewoElement* DrzewoElement::getBrat() {
    //korzeñ nie ma brata
    if (rodzic == NULL) {
        return NULL;
    } 
    //prawy syn
    else if (this == rodzic->prawyPotomek) {
        return rodzic->lewyPotomek;
    }
    //lewy syn
    else if (this == rodzic->lewyPotomek) {
        return rodzic->prawyPotomek;
    }
}

