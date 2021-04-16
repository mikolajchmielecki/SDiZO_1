#include "Drzewo.h"
#include "WyswietlanieDrzewa.h"
#include "Typy.h"

Drzewo::Drzewo(TablicaDynamiczna* tablica, Typ typ) {
	
	this->korzen = NULL;
	this->typ = typ;
	utworzDrzewo(tablica);
	
	
	/*
	//ex 6
	this->typ = typ;
	this->korzen = new DrzewoElement(5, NULL, typ);
	korzen->kolor = Kolor::BLACK;
	korzen->lewyPotomek = new DrzewoElement(2, korzen, typ);
	korzen->prawyPotomek = new DrzewoElement(8, korzen, typ);
	korzen->prawyPotomek->kolor = Kolor::BLACK;

	korzen->lewyPotomek->lewyPotomek = new DrzewoElement(1, korzen->lewyPotomek, typ);
	korzen->lewyPotomek->lewyPotomek->kolor = Kolor::BLACK;

	korzen->lewyPotomek->prawyPotomek = new DrzewoElement(4, korzen->lewyPotomek, typ);
	korzen->lewyPotomek->prawyPotomek->kolor = Kolor::BLACK;

	korzen->prawyPotomek->prawyPotomek = new DrzewoElement(9, korzen->prawyPotomek, typ);
	korzen->prawyPotomek->lewyPotomek = new DrzewoElement(7, korzen->prawyPotomek, typ);
	*/
	

	/*
	//ex5 ex9
	this->typ = typ;
	this->korzen = new DrzewoElement(7, NULL, typ);
	korzen->kolor = Kolor::BLACK;
	korzen->lewyPotomek = new DrzewoElement(3, korzen, typ);
	korzen->lewyPotomek->kolor = Kolor::BLACK;
	korzen->prawyPotomek = new DrzewoElement(18, korzen, typ);


	korzen->prawyPotomek->prawyPotomek = new DrzewoElement(22, korzen->prawyPotomek, typ);
	korzen->prawyPotomek->prawyPotomek->kolor = Kolor::BLACK;

	korzen->prawyPotomek->lewyPotomek = new DrzewoElement(10, korzen->prawyPotomek, typ);
	korzen->prawyPotomek->lewyPotomek->kolor = Kolor::BLACK;

	korzen->prawyPotomek->lewyPotomek->lewyPotomek = new DrzewoElement(8, korzen->prawyPotomek->lewyPotomek, typ);
	korzen->prawyPotomek->lewyPotomek->prawyPotomek = new DrzewoElement(11, korzen->prawyPotomek->lewyPotomek, typ);

	korzen->prawyPotomek->prawyPotomek->prawyPotomek = new DrzewoElement(26, korzen->prawyPotomek->prawyPotomek, typ);
	*/
	}

Drzewo::~Drzewo() {
	if (korzen != NULL) {
		korzen->usunPodrzewo();
		delete korzen;
	}
}

void Drzewo::dodaj(int liczba) {
	umiescElement(liczba);
}

void Drzewo::usun(int liczba) {
	DrzewoElement* znaleziony = wyszukajDrzewo(liczba);
	if (znaleziony == NULL) {
		throw exception("Nie ma takiego elementu");
	}
	else {
		if (typ == Typ::RB) {
			usunRB(znaleziony);
		}
		else if (typ == Typ::BST) {
			usunBST(znaleziony);
		}
		else if (typ == Typ::AVL) {
			usunAVL(znaleziony);
		}
	}

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
			nowyKorzen->usunPodrzewo();
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
W miejsce usuwanego wierzcho³ka wstawia zastêpcê i zwalnia pamiêæ usuwanego wierzhco³ka
*/
void Drzewo::usunBST(DrzewoElement* usuwany) {
	//zastepca usuwanego elementu lub usuwany element
	DrzewoElement* zastepca; //y
	//jeœli jeden z potomków jest NULLEM
	if (usuwany->lewyPotomek == NULL || usuwany->prawyPotomek == NULL) {
		//zastepca jest usuwanym elementem
		zastepca = usuwany;
	}
	else {
		//zastepca jest nastêpnikiem usuwanego elementu
		zastepca = getNastepnik(usuwany);
	}
	DrzewoElement* zastepcaPotomek; //x
	if (zastepca->lewyPotomek != NULL) {
		zastepcaPotomek = zastepca->lewyPotomek;
	}
	else {
		zastepcaPotomek = zastepca->prawyPotomek;
	}

	if (zastepcaPotomek != NULL) {
		zastepcaPotomek->rodzic = zastepca->rodzic;
	}

	//zastepca jest korzeniem
	if (zastepca->rodzic == NULL) {
		korzen = zastepcaPotomek;
	}
	else {
		//zastepca jest lewym potomkiem
		if (zastepca == zastepca->rodzic->lewyPotomek) {
			zastepca->rodzic->lewyPotomek = zastepcaPotomek;
		}
		//zastepca jest prawym potomkiem
		else {
			zastepca->rodzic->prawyPotomek = zastepcaPotomek;
		}
	}

	//je¿eli zastepca jest nastepnikiem
	if (zastepca != usuwany) {
		if (usuwany->rodzic != NULL) {
			if (usuwany->rodzic->prawyPotomek == usuwany) {
				usuwany->rodzic->prawyPotomek = zastepca;
			}
			else {
				usuwany->rodzic->lewyPotomek = zastepca;
			}
		}
		else {
			korzen = zastepca;
		}
		zastepca->rodzic = usuwany->rodzic;
		zastepca->prawyPotomek = usuwany->prawyPotomek;
		zastepca->lewyPotomek = usuwany->lewyPotomek;
		if (zastepca->prawyPotomek != NULL) {
			zastepca->prawyPotomek->rodzic = zastepca;
		}
		if (zastepca->lewyPotomek != NULL) {
			zastepca->lewyPotomek->rodzic = zastepca;
		}
	}

	delete usuwany;
}

/*
Usuwa element w drzewie RB
Korzysta z algorytmu usuwania dla drzewo BST
*/
void Drzewo::usunRB(DrzewoElement* usuwany) {
	DrzewoElement* x = NULL;
	DrzewoElement* zastepca = NULL;

	//czy x jest NULLEM
	bool ifXNULL = false;


	//na poczatku przypisujemy pod x odpowiedni element

	//je¿eli obaj potomkowie s¹ NULLAMI
	if (usuwany->prawyPotomek == NULL && usuwany->lewyPotomek == NULL) {
		if (usuwany == korzen) {
			delete korzen;
			korzen = NULL;
			return;
		}
		ifXNULL = true;
		x = new DrzewoElement(0, usuwany, typ);
		x->kolor = Kolor::BLACK;
		usuwany->prawyPotomek = x;
	}
	//je¿eli jeden z potomków jest NULLEM
	//lewy
	else if (usuwany->prawyPotomek != NULL && usuwany->lewyPotomek == NULL) {
		x = usuwany->prawyPotomek;
		zastepca = x;
	}
	//prawy
	else if (usuwany->lewyPotomek != NULL && usuwany->prawyPotomek == NULL) {
		x = usuwany->lewyPotomek;
		zastepca = x;
	}
	//obaj potomkowie nie sa NULLAMI
	else {
		zastepca = getNastepnik(usuwany);
		x = zastepca->prawyPotomek;
		if (x == NULL) {
			ifXNULL = true;
			x = new DrzewoElement(0, zastepca, typ);
			x->kolor = Kolor::BLACK;
			zastepca->prawyPotomek = x;
		}
	}
	DrzewoElement* xKopia = x;
	// tworzenie kopii przed usuniêciem
	DrzewoElement* usuwanyKopia = new DrzewoElement(*usuwany);

	//algorytm usuwania dla BST bez zwalniania pamieci
	usunBST(usuwany);




	//je¿eli usuniety wierzcho³ek jest czerowny a zastepca jest czerwony lub jest NULLEM
	//koñczymy
	if (usuwanyKopia->kolor == Kolor::RED && (zastepca == NULL || zastepca->kolor == Kolor::RED)) {

	}
	else
		//je¿eli wierzcho³ek usuwany jest czarny, a zastepca jest czerwony
		//to zmieniamy kolor zastepcy na czarny i koñczymy
		if (usuwanyKopia->kolor == Kolor::BLACK && (zastepca != NULL && zastepca->kolor == Kolor::RED)) {
			zastepca->kolor = Kolor::BLACK;
		}
		else {

			//je¿eli wierzcho³ek usuwany jest czerwony, a zastêpca czarny
			//to zmieniamy kolor zastepcy na czerwony i rozpatrujemy przypadki
			if (usuwanyKopia->kolor == Kolor::RED && zastepca->kolor == Kolor::BLACK) {
				zastepca->kolor = Kolor::RED;
			}

			//je¿eli wierzcho³ek usuwany jest czarny, a zastêpca jest NULLEM lub jest czarny
			//rozpatrujmey przypadki


			//mamy 5 przypadków

			//x jest koloru czarownego
			//zmieniamy na kolor czarny
			if (x->kolor == Kolor::RED) {
				x->kolor = Kolor::BLACK;
			}
			else {

				while (true) {
					//nowy brat X po przeniesieniu
					DrzewoElement* brat = x->getBrat();

					//1 - x jest czarny a brat jest czerwony
					if (x->kolor == Kolor::BLACK && brat->kolor == Kolor::RED) {
						brat->kolor = Kolor::BLACK;
						x->rodzic->kolor = Kolor::RED;
						if (x->rodzic->lewyPotomek == x) {
							rotacjaLewa(x->rodzic);
							brat = x->rodzic->prawyPotomek;
						}
						else {
							rotacjaPrawa(x->rodzic);
							brat = x->rodzic->lewyPotomek;
						}
					}


					//2 - x jest czarny i jego brat te¿ jest czarny i obaj synowie brata s¹ czarni (brat not NULL)
					if (x->kolor == Kolor::BLACK &&
						brat->kolor == Kolor::BLACK &&
						(brat->lewyPotomek == NULL || brat->lewyPotomek->kolor == Kolor::BLACK) &&
						(brat->prawyPotomek == NULL || brat->prawyPotomek->kolor == Kolor::BLACK)) {
						brat->kolor = Kolor::RED;
						x = x->rodzic;

						//????
						if (x->kolor == Kolor::RED || x == korzen) {
							x->kolor = Kolor::BLACK;
							break;
						}
						else {
							continue;
						}
					}

					//3 - - x ma kolor czarny i jego brat te¿
					if (x->kolor == Kolor::BLACK && brat->kolor == Kolor::BLACK) {
						//nastepnikSyn jest lewym potomkiem, lewy potomek brata jest czerwony, a prawy jest czarny
						if (x->rodzic->lewyPotomek == x &&
							(brat->lewyPotomek != NULL && brat->lewyPotomek->kolor == Kolor::RED) &&
							(brat->prawyPotomek == NULL || brat->prawyPotomek->kolor == Kolor::BLACK)) {

							brat->lewyPotomek->kolor = Kolor::BLACK;//
							brat->kolor = Kolor::RED;
							rotacjaPrawa(brat);//
							brat = x->rodzic->prawyPotomek;//

						}

						//nastepnikSyn jest prawym potomkiem, prawy potomek brata jest czerwony, a lewy jest czarny
						if (x->rodzic->prawyPotomek == x &&
							(brat->prawyPotomek != NULL && brat->prawyPotomek->kolor == Kolor::RED) &&
							(brat->lewyPotomek == NULL || brat->lewyPotomek->kolor == Kolor::BLACK)) {

							brat->prawyPotomek->kolor = Kolor::BLACK;//
							brat->kolor = Kolor::RED;
							rotacjaLewa(brat);//
							brat = x->rodzic->lewyPotomek;//
						}
					}

					//4 - x ma kolor czarny i jego brat te¿
					if (x->kolor == Kolor::BLACK && brat->kolor == Kolor::BLACK) {
						//x jest lewym dzieckiem, a prawe dziecko brata jest czerwone
						if (x->rodzic->lewyPotomek == x && (brat->prawyPotomek != NULL && brat->prawyPotomek->kolor == Kolor::RED)) {
							brat->kolor = x->rodzic->kolor;
							x->rodzic->kolor = Kolor::BLACK;

							brat->prawyPotomek->kolor = Kolor::BLACK;
							rotacjaLewa(x->rodzic);

						}
						//x jest prawym dzieckiem, a lewe dziecko brata jest czerwone
						if (x->rodzic->prawyPotomek == x && (brat->lewyPotomek != NULL && brat->lewyPotomek->kolor == Kolor::RED)) {
							brat->kolor = x->rodzic->kolor;
							x->rodzic->kolor = Kolor::BLACK;

							brat->lewyPotomek->kolor = Kolor::BLACK;
							rotacjaPrawa(x->rodzic);

						}
						break;
					}


				}
			}
		}

	//kasowanie jeœli pocz¹tkowo x by³o nullem
	if (ifXNULL) {
		if (xKopia == xKopia->rodzic->lewyPotomek) {
			xKopia->rodzic->lewyPotomek = NULL;
		}
		else {
			xKopia->rodzic->prawyPotomek = NULL;
		}
		delete xKopia;
	}

	//kasowanie kopii usuwanego elementu
	delete usuwanyKopia;

}

/*
Usuwa element z drzewa AVL
Korzysta z usuwawnia dla drzewa BST
Altualizuje i ewentualnie naprawia wspó³czynniki wywa¿enia od rodzica usuwanego elementu do korzenia
*/
void Drzewo::usunAVL(DrzewoElement* usuwany) {
	//szukam rodzica od którego nale¿y naprawiaæ drzewo AVL
	
	//zastepca usuwanego elementu lub usuwany element
	DrzewoElement* zastepca; //y
	//jeœli jeden z potomków jest NULLEM
	if (usuwany->lewyPotomek == NULL || usuwany->prawyPotomek == NULL) {
		//zastepca jest usuwanym elementem
		zastepca = usuwany;
	}
	else {
		//zastepca jest nastêpnikiem usuwanego elementu
		zastepca = getNastepnik(usuwany);
	}
	DrzewoElement* pierwszyNaprawiany;

	//nastepnik jest prawym potomkiem
	if (zastepca->rodzic == usuwany) {
		pierwszyNaprawiany = zastepca;
	}
	else {
		pierwszyNaprawiany = zastepca->rodzic;
	}
	//zwyk³e usuwanie
	usunBST(usuwany);

	//naprawianie od rodzica usunietego do korzenia
	if (pierwszyNaprawiany != NULL) {
		aktualizujWywazenia(pierwszyNaprawiany);
	}
	
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
	if (tablica != NULL) {
		for (int i = 0; i < tablica->getRozmiar(); i++) {
			umiescElement(tablica->getTablica()[i]);
		}
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
	else if (typ == Typ::AVL) {
		naprawAVL(nowy);
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
Naprawia drzewo AVL po wstawieniu nowego elementu
Aktualizuje i ewentualnie poprawia wspó³czynniki wywa¿enia od wstawioenego elementu do korzenia
*/
void Drzewo::naprawAVL(DrzewoElement* nowy) {
	//jesli wstawiany element jest korzeniem
	if (nowy == korzen) {
		return;
	}

	aktualizujWywazenia(nowy->rodzic);
	
}


/*
Aktualizuje wywa¿enia od wskazanego elementu do korzenia
*/
void Drzewo::aktualizujWywazenia(DrzewoElement* element) {
	//aktualizujemy wysokosci od wskazanego elementu do korzenia
	//jesli wywazanie ma wartoœæ -2 lub 2 to naprawiamy
	while (element != NULL) {
		
		int wywazenie = element->getWywazenie();

		//przypadki wymagaj¹ce naprawy
		if (wywazenie == -2) {
			//LR
			if (element->prawyPotomek->getWywazenie() == 1) {
				rotacjaPrawa(element->prawyPotomek);
				element->prawyPotomek->prawyPotomek->aktualizujWysokosc();
				element->prawyPotomek->aktualizujWysokosc();
			}
			
			//L
			rotacjaLewa(element);
			element->aktualizujWysokosc();
			element->rodzic->aktualizujWysokosc();
			element = element->rodzic->rodzic;
			continue;

			
		}
		else if (wywazenie == 2) {
			//LR
			if (element->lewyPotomek->getWywazenie() == -1) {
				rotacjaLewa(element->lewyPotomek);
				element->lewyPotomek->lewyPotomek->aktualizujWysokosc();
				element->lewyPotomek->aktualizujWysokosc();
			}
			rotacjaPrawa(element);
			element->aktualizujWysokosc();
			element->rodzic->aktualizujWysokosc();
			element = element->rodzic->rodzic;
			continue;


		}


		//konæowe operacje pêtli
		element->aktualizujWysokosc();
		element = element->rodzic;
	}
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
		if (rodzic->prawyPotomek == element) {
			rodzic->prawyPotomek = lewyPotomek;
		}
		else {
			rodzic->lewyPotomek = lewyPotomek;
		}
		
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
		if (rodzic->prawyPotomek == element) {
			rodzic->prawyPotomek = prawyPotomek;
		}
		else {
			rodzic->lewyPotomek = prawyPotomek;
		}
	}
	
}


/*
Wyszukiwanie nastepnika w drzewie BST
*/
DrzewoElement* Drzewo::getNastepnik(DrzewoElement* element) {
	//je¿eli element posiada prawego syna
	if (element->prawyPotomek != NULL) {
		DrzewoElement* minimum = element->prawyPotomek;
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


