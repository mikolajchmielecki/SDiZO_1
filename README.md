# Struktury Danych i Złożoność Obliczeniowa


## Ogólne informacje
w nastepujacych strukturach danych:<br/>
• tablica dynamiczna,<br/>
• lista dwukierunkowa,<br/>
• kopiec (implementacja za pomoca tablicy),<br/>
• drzewo czerwono-czarne,<br/>
Nalezało zbadac czas wymienionych operacji dla kazdej struktury oraz dla róznych rozmiarów. Dodatkowo
zbadałem czasy poszczególnych operacji dla implementacji tablicy dynamicznej (vector) oraz listy
dwukierunkowej (list) z biblioteki STL. Ponadto zaimplementowałem poszczególne operacje dla drzewa
AVL oraz zbadałem czasy ich wykonywania.
	
## Opis
Implementacja projektu spełnia nastepujace załozenia:<br/>
• do implementacji został uzyty jezyk programowania C++ oraz srodowisko IDE Visual Studio 2019,<br/>
• program wyeksportowany do pliku wykonywalnego SDiZO_projekt.exe zwanego dalej programem,<br/>
• elementem kazdej ze struktur jest liczba całkowita 4-bajtowa ze znakiem (int),<br/>
• kazda ze struktur danych to osobna klasa,<br/>
• kazda ze struktur danych posiada swoje menu, które pozwala dokonywac poszczególnych operacji,<br/>
• istnieje mozliwosc wczytania danych do programu z pliku tekstowego,<br/>
• program domyslnie sprawdza plik "dane.txt", który znajduje sie w katalogu uruchomieniowym<br/>
programu, jednak istnieje mozliwosc zmiany sciezki pliku z danymi,<br/>
• liczby w pliku z danymi moga byc rozdzielone dowolna liczba znaków białych,<br/>
• pierwsza wartosc zawarta w pliku z danymi oznacza liczbe wczytywanych danych,<br/>
• program jest odporny na wszelkiego rodzaju błedy danych wejsciowych, tych wczytywanych z pliku<br/>
oraz tych wprowadzanych przez uzytkownika o czym informuje stosownymi komunikatami,<br/>
• program posiada opcje właczenia testów, jednak trwa to łacznie kilkadziesiat minut i w tym czasie<br/>
nie ma mozliwosci korzystania z pozostałych funkcji programu,<br/>
• program oddany do oceny został zbudowany w trybie Release i w takiej postaci wykonywano na
nim eksperymenty z pomiarem czasu,<br/>
• kazda ze struktur danych zwalnia zarezerwowane miejsce, gdy uzytkownik zamyka menu dotyczace
danej struktury,<br/>
• kazdorazowo po zmianie danych w strukturze wyswietlana jest je aktualna zwartosc,<br/>
• po wczytaniu danych z pliku dane sa pamietane przez tablice dynamiczna,<br/>
• kazda ze struktur danych podczas tworzenia korzysta z tablicy dynamicznej.<br/>

##Technologie
> Microsoft Visual Studio Community 2019
> C++
> STL lib
