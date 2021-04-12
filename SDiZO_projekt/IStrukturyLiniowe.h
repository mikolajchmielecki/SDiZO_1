#pragma once
class IStrukturyLiniowe {
public:
	virtual void dodajPoczatek(int) = 0;
	virtual void dodajKoniec(int liczba) = 0;
	virtual void dodaj(int liczba, int pozycja) = 0;
	virtual void usunPoczatek() = 0;
	virtual void usunKoniec() = 0;
	virtual void usun(int pozycja) = 0;
	virtual int wyszukaj(int liczba) = 0;
	virtual void wyswietl() = 0;
};

