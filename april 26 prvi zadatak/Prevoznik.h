#pragma once
#include "Automobil.h"
#include "Benzinac.h"
#include "Hibrid.h"

class Prevoznik {
	Automobil** kolekcija;
	int top;
	int max;

	void AlocirajMem(int _max);
	void OslobodiMem();
public:
	Prevoznik();
	Prevoznik(int _max);
	Prevoznik(const Prevoznik&);
	~Prevoznik();

	void ObavljenaVoznja(const char*, int);
	Automobil* NajpovoljnijiAutomobil(int);
	void VratiNajDuzinuGorivo(Automobil**, Automobil**)const;
	float UkupnaKilometraza() const;

	void Dodaj(Automobil*);
	void IzbaciPoKm(int);
	friend ostream& operator<<(ostream&, const Prevoznik&);
	void prikazi(ostream&)const;
};