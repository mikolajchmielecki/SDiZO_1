#include "Drzewo.h"
#include "WyswietlanieDrzewa.h"
#include "Typy.h"

Drzewo::Drzewo(TablicaDynamiczna* tablica, Typ typ) {
	this->korzen = NULL;
	this->typ = typ;
	utworzDrzewo(tablica);
}

Drzewo::~Drzewo() {
	if (korzen != NULL) {
		delete korzen;
	}
}

void Drzewo::dodaj(int liczba) {
	umiescElement(liczba);
}

void Drzewo::usun(int liczba) {

}

/*
Zwraca -1 jeœli nie znaleziono
Zwraca 1 jeœli znaleziono
Jeœli podano w paramatrze, ¿e metoda ma wyœwietliæ œcie¿ke do elementu to wyœwietla œwie¿kê
*/
int Drzewo::wyszukaj(int liczba, bool wyswietlanie) {
	DrzewoElement* element = wyszukajDrzewo(liczba);
	if (element == NULL) {
		return -1;
	}
	else {
		if (wyswietlanie) {
			DrzewoElement* nowyKorzen = utworzSciezkeDoKorzenia(element);
			WyswietlanieDrzewa wyswietlanieDrzewa = WyswietlanieDrzewa(nowyKorzen);
			wyswietlanieDrzewa.wyswietl(false);
			delete nowyKorzen;
		}
		return 1;
	}
}

/*
Tworzy podrzewo ilustruj¹ce œcie¿kê do wyszukanego elementu
*/
DrzewoElement* Drzewo::utworzSciezkeDoKorzenia(DrzewoElement* element) {
	DrzewoElement* nowyKorzen = new DrzewoElement(*element);
	while (element->rodzic != NULL) {
		nowyKorzen->rodzic = new DrzewoElement(*element->rodzic);
		if (element->rodzic->prawyPotomek == element) {
			nowyKorzen->rodzic->prawyPotomek = nowyKorzen;
		}
		else {
			nowyKorzen->rodzic->lewyPotomek = nowyKorzen;
		}
		nowyKorzen = nowyKorzen->rodzic;
		element = element->rodzic;
	}
	return nowyKorzen;
}

/*
Wyszukuje element o zadanej wartoœci w drzewie
Zwraca NULL jeœli nie znaleziono
*/
DrzewoElement* Drzewo::wyszukajDrzewo(int liczba) {
	DrzewoElement* element = korzen;
	while (element != NULL) {
		if (element->liczba == liczba) {
			return element;
		}
		else {
			if (element->liczba > liczba) {
				element = element->lewyPotomek;
				continue;
			}
			else {
				element = element->prawyPotomek;
				continue;
			}
		}
	}
	return element;
}

/*
Algorytm usuwania elementu z drzewa RB
*/
void Drzewo::usunRB(DrzewoElement* usuwanyElement) {

}

void Drzewo::wyswietl() {
	if (korzen != NULL) {
		WyswietlanieDrzewa wyswietlanieDrzewa = WyswietlanieDrzewa(korzen);
		wyswietlanieDrzewa.wyswietl(false);
	}
	else {
		cout << "\nBrak elementów do wyœwietlenia\n";
	}
}



/*
Tworzy drzewo z tablicy BST
*/
void Drzewo::utworzDrzewo(TablicaDynamiczna* tablica) {
	for (int i = 0; i < tablica->getRozmiar(); i++) {
		umiescElement(tablica->getTablica()[i]);
	}
}


/*
Umieszcza element zadany jako liczba
*/
void Drzewo::umiescElement(int liczba) {
	DrzewoElement* nowy = utworzElement(liczba);
	umiescElement(nowy);
	if (typ == Typ::RB) {
		naprawRB(nowy);
	}

}


DrzewoElement* Drzewo::utworzElement(int liczba) {
	return new DrzewoElement(liczba, NULL, typ);
}

/*
Umieszcza nowy element w odpowiednim miejscu w drzewie
Elementy o tej samej wartoœci s¹ umieszczane w lewym podrzewie
*/
void Drzewo::umiescElement(DrzewoElement* nowy) {
	if (korzen == NULL) {
		korzen = nowy;
		return;
	}
	else {
		DrzewoElement* element = korzen;
		while (element != NULL) {
			if (nowy->liczba <= element->liczba) {
				if (element->lewyPotomek == NULL) {
					nowy->rodzic = element;
					element->lewyPotomek = nowy;
					return;
				}
				else {
					element = element->lewyPotomek;
				}
			}
			else {
				if (element->prawyPotomek == NULL) {
					nowy->rodzic = element;
					element->prawyPotomek = nowy;
					return;
				}
				else {
					element = element->prawyPotomek;
				}
			}
		}
		return;
	}
}


/*
Algorytm wstawiania element do drzewa RB po wstêpnym umieszczeniu przez algorytm dla drzewa BST
*/
void Drzewo::naprawRB(DrzewoElement* nowy) {
	
	//wstawiany element jest korzeniem -> czarny
	if (nowy == korzen) {
		nowy->kolor = Kolor::BLACK;
		return;
	}

	//sprawdzanie czy jest ok
	if (nowy->rodzic->kolor == Kolor::BLACK) {
		return;
	}

	DrzewoElement* stryj = nowy->rodzic->getBrat();
	//stryj wstawianego wêz³a jest czerwony i nie jest NULLEM
	//kolorujemy stryja i ojca na czarno a dziadka na czerwono i rekurencyjnie naprawiamy drzewo od dziadka
	if (stryj != NULL && stryj->kolor == Kolor::RED) {
		stryj->kolor = Kolor::BLACK;
		nowy->rodzic->kolor = Kolor::BLACK;
		nowy->rodzic->rodzic->kolor = Kolor::RED;
		naprawRB(nowy->rodzic->rodzic);
		return;
	}

	//stryj jest czarny lub jest NULLEM


	bool rodzicLewymPotomkiem = true;
	// sprawdzanie którym potomkiem jest rodzic
	if (nowy->rodzic == nowy->rodzic->rodzic->prawyPotomek) {
		rodzicLewymPotomkiem = false;
	}

	//wstawiany wêze³ jest prawym potomkiem
	//rotacja wzglêdem rodzica po to aby wstawiany wêze³ by³ lewym potomkiem
	if (nowy->rodzic->prawyPotomek == nowy && rodzicLewymPotomkiem) {
		rotacjaLewa(nowy->rodzic);;
		nowy = nowy->lewyPotomek;
	}
	//sytuacja symetryczna
	if (nowy->rodzic->lewyPotomek == nowy && !rodzicLewymPotomkiem) {
		rotacjaPrawa(nowy->rodzic);
		nowy = nowy->prawyPotomek;
	}
	
	//wstawiany wêze³ jest lewym potomkiem
	//zmiana koloru dziadka na czerwony a rodzica na czarny oraz prawa rotacja wzgledem dziadka 
	nowy->rodzic->rodzic->kolor = Kolor::RED;
	nowy->rodzic->kolor = Kolor::BLACK;

	if (rodzicLewymPotomkiem) {
		rotacjaPrawa(nowy->rodzic->rodzic);
	}
	//sytuacja symetryczna
	else {
		rotacjaLewa(nowy->rodzic->rodzic);
	}
	return;
}

/*
Przeprowadza praw¹ rotacjê wzglêdem danego wierzcho³ka
*/
void Drzewo::rotacjaPrawa(DrzewoElement* element) {
	DrzewoElement* lewyPotomek = element->lewyPotomek;
	if (lewyPotomek == NULL) {
		throw exception("Rotacja niemo¿liwa");
	}
	if (element == korzen) {
		korzen = lewyPotomek;
	}

	DrzewoElement* rodzic = element->rodzic;
	element->lewyPotomek = lewyPotomek->prawyPotomek;
	if (lewyPotomek->prawyPotomek != NULL) {
		lewyPotomek->prawyPotomek->rodzic = element;
	}
	lewyPotomek->prawyPotomek = element;
	element->rodzic = lewyPotomek;
	lewyPotomek->rodzic = rodzic;
	if (rodzic != NULL) {
		rodzic->lewyPotomek = lewyPotomek;
	}
}


/*
Przeprowadza lew¹ rotacjê wzglêdem danego wierzcho³ka
*/
void Drzewo::rotacjaLewa(DrzewoElement* element) {
	DrzewoElement* prawyPotomek = element->prawyPotomek;
	if (prawyPotomek == NULL) {
		throw exception("Rotacja niemo¿liwa");
	}

	//jesli rotacja jest wzgledem korzenia
	if (element == korzen) {
		korzen = prawyPotomek;
	}
	
	DrzewoElement* rodzic = element->rodzic;
	element->prawyPotomek = prawyPotomek->lewyPotomek;
	if (prawyPotomek->lewyPotomek != NULL) {
		prawyPotomek->lewyPotomek->rodzic = element;
	}
	prawyPotomek->lewyPotomek = element;
	element->rodzic = prawyPotomek;
	prawyPotomek->rodzic = rodzic;
	if (rodzic != NULL) {
		rodzic->prawyPotomek = prawyPotomek;
	}
	
}


/*
Wyszukiwanie nastepnika w drzewie BST
*/
DrzewoElement* Drzewo::getNastepnik(DrzewoElement* element) {
	//je¿eli element posiada prawego syna
	if (element->prawyPotomek != NULL) {
		DrzewoElement* minimum = element;
		while (minimum->lewyPotomek != NULL) {
			minimum = minimum->lewyPotomek;
		}
		return minimum;
	}
	DrzewoElement* temp = element->rodzic;
	//przechodz do momentu a¿ element nie jest lewym potomkiem 
	while (temp != NULL && temp->lewyPotomek != element) {
		element = temp;
		temp = temp->rodzic;
	}
	return temp;
}


