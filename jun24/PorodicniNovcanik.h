#pragma once
#include "Novcanica.h"
#include "NovcanicaDinar.h"
#include "NovcanicaStrana.h"

class PorodicniNovcanik {
	Novcanica** kolekcija;
	int top;
	int max;
	void AlocirajMem(int _max);
	void DealocirajMem();
	double UkupnaSvota();
public:
	PorodicniNovcanik(int _max);
	~PorodicniNovcanik();

	void Dodaj(Novcanica* n);
	void Izdvoji(Novcanica& n, int i);
	void Rasitni(Novcanica& veca, Novcanica& manja);
	bool MozePlatiti(int svota);
	void VratiNaj(Novcanica** prva, Novcanica** druga);
	friend ostream& operator<<(ostream& izlaz, const PorodicniNovcanik& p);
};