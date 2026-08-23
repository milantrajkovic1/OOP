#pragma once
#include "Pice.h"
#include "Voda.h"
#include "Sok.h"
class Skladiste
{
	Pice** kolekcija;
	int top;
	int max;
public:
	Skladiste();
	Skladiste(int _max);
	~Skladiste();

	void Dodaj(Pice* p);
	void Izdvoji(Pice& p, int br);
	void Presipaj(Pice& prvo, Pice& drugo);
	bool DovoljnaKolicina(int kolicina);
	void VratiNaj(Pice** prvo, Pice** drugo);

	friend ostream& operator<<(ostream& izlaz, const Skladiste& s);

};

