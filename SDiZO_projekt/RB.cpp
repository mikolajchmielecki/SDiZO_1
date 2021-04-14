#include "RB.h"


RB::RB(TablicaDynamiczna* tablica) : BST(tablica) {
    utworzDrzewo(tablica);
}

void RB::dodaj(int liczba)
{
}

void RB::usun(int liczba)
{
}

int RB::wyszukaj(int liczba, bool wyswietlanie)
{
    return 0;
}

void RB::wyswietl() {
    BST::wyswietl();
}

void RB::utworzDrzewo(TablicaDynamiczna* tablica) {
    for (int i = 0; i < tablica->getRozmiar(); i++) {
        RBElement* nowy = utworzElement(tablica->getTablica()[i]);
        umiescElement(nowy);
    }
}

/*
Tworzy nowy element drzewa RB. Na pocz¹tku wg algorytmu dodawania powinien on byæ czerwony
*/
RBElement* RB::utworzElement(int liczba) {
    return new RBElement(liczba, NULL, this, czerwony);
}

void RB::umiescElement(RBElement* nowy) {
    
}
