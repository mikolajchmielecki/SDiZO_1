# Struktury Danych i Złożoność Obliczeniowa
## Spis treści
* [Ogólne informacje](#Ogólne informacje)
* [Opis](#Opis)

## Ogólne informacje
w nastepujacych strukturach danych:
• tablica dynamiczna,
• lista dwukierunkowa,
• kopiec (implementacja za pomoca tablicy),
• drzewo czerwono-czarne,
Nalezało zbadac czas wymienionych operacji dla kazdej struktury oraz dla róznych rozmiarów. Dodatkowo
zbadałem czasy poszczególnych operacji dla implementacji tablicy dynamicznej (vector) oraz listy
dwukierunkowej (list) z biblioteki STL. Ponadto zaimplementowałem poszczególne operacje dla drzewa
AVL oraz zbadałem czasy ich wykonywania.
	
## Opis
Implementacja projektu spełnia nastepujace załozenia:
• do implementacji został uzyty jezyk programowania C++ oraz srodowisko IDE Visual Studio 2019,
• program wyeksportowany do pliku wykonywalnego SDiZO_projekt.exe zwanego dalej programem,
• elementem kazdej ze struktur jest liczba całkowita 4-bajtowa ze znakiem (int),
• kazda ze struktur danych to osobna klasa,
• kazda ze struktur danych posiada swoje menu, które pozwala dokonywac poszczególnych operacji,
• istnieje mozliwosc wczytania danych do programu z pliku tekstowego,
• program domyslnie sprawdza plik "dane.txt", który znajduje sie w katalogu uruchomieniowym
programu, jednak istnieje mozliwosc zmiany sciezki pliku z danymi,
• liczby w pliku z danymi moga byc rozdzielone dowolna liczba znaków białych,
• pierwsza wartosc zawarta w pliku z danymi oznacza liczbe wczytywanych danych,
• program jest odporny na wszelkiego rodzaju błedy danych wejsciowych, tych wczytywanych z pliku
oraz tych wprowadzanych przez uzytkownika o czym informuje stosownymi komunikatami,
• program posiada opcje właczenia testów, jednak trwa to łacznie kilkadziesiat minut i w tym czasie
nie ma mozliwosci korzystania z pozostałych funkcji programu,
• program oddany do oceny został zbudowany w trybie Release i w takiej postaci wykonywano na
nim eksperymenty z pomiarem czasu,
• kazda ze struktur danych zwalnia zarezerwowane miejsce, gdy uzytkownik zamyka menu dotyczace
danej struktury,
• kazdorazowo po zmianie danych w strukturze wyswietlana jest je aktualna zwartosc,
• po wczytaniu danych z pliku dane sa pamietane przez tablice dynamiczna,
• kazda ze struktur danych podczas tworzenia korzysta z tablicy dynamicznej.
