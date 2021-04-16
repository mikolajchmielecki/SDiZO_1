#include "DrzewoElement.h"




DrzewoElement::DrzewoElement(int liczba, DrzewoElement* rodzic, Typ typ) {
    this->liczba = liczba;
    this->prawyPotomek = NULL;
    this->lewyPotomek = NULL;
    this->rodzic = rodzic;
    this->typ = typ;

    //pocz¹tkowo jest równa 1
    this->wysokosc = 1;
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

    if (typ == Typ::AVL) {
        int wywazenie = getWywazenie();
        if (wywazenie >= 0) {
            wynik += " ";
        }
        wynik += to_string(wywazenie);
        wynik += ": ";
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
    else if (typ == Typ::AVL) {
        return szerokoscBST + 4;
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

/*
*Oblicza wywa¿enie danego elementu
*Potrzebne do drzewa AVL
*/
int DrzewoElement::getWywazenie() {
    //lewe poddrzewo
    int wysokoscL = 0;
    if (lewyPotomek != NULL) {
        wysokoscL = lewyPotomek->wysokosc;
    }

    //prawego poddrzewa
    int wysokoscP = 0;
    if (prawyPotomek != NULL) {
        wysokoscP = prawyPotomek->wysokosc;
    }

    //wywazenie to roznica wysokosc lewego i prawego poddrzewa
    return wysokoscL - wysokoscP;
}

/*
Aktualizuje wartosc wysokosci danego poddrzewa
*/
void DrzewoElement::aktualizujWysokosc() {
    //lewe poddrzewo
    int wysokoscL = 0;
    if (lewyPotomek != NULL) {
        wysokoscL = lewyPotomek->wysokosc;
    }

    //prawego poddrzewa
    int wysokoscP = 0;
    if (prawyPotomek != NULL) {
        wysokoscP = prawyPotomek->wysokosc;
    }
    wysokosc = getMax(wysokoscL, wysokoscP) + 1;
}



//obliczanie maksymalnej wartosci
int DrzewoElement::getMax(int x, int y) {
    return (x > y) ? x : y;
}

