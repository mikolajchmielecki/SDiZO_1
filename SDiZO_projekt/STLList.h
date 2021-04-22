#pragma once
#include<list>
#include"TablicaDynamiczna.h"
#include"IStrukturyLiniowe.h"

using namespace std;
class STLList : public IStrukturyLiniowe {
public:
	STLList(TablicaDynamiczna*);
	virtual void dodajPoczatek(int liczba);
	virtual void dodajKoniec(int liczba);
	virtual void dodaj(int liczba, int pozycja);
	virtual void usunPoczatek();
	virtual void usunKoniec();
	virtual void usun(int pozycja);
	virtual int wyszukaj(int liczba);
	virtual void wyswietl();
private:
	list<int> lista;

};

