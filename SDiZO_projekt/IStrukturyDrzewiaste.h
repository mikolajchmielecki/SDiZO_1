#pragma once
class IStrukturyDrzewiaste{
public:
	virtual void dodaj(int liczba) = 0;
	virtual void usun() = 0;
	virtual int wyszukaj(int liczba, bool wyswietlanie) = 0;
	virtual void wyswietl() = 0;
};
