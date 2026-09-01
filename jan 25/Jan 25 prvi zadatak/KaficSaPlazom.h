#pragma once
#include "ParLezaljkiSaDodatkom.h"
#include"ParLezaljki.h"
#include <iostream>
class KaficSaPlazom {

	ParLezaljki** kolekcija;
	int kapacitet;
	int trenutnoIzdatih;

	double zarada;
	void ZauzmiMem(int _kapacitet);
	void OslobodiMem();
public:
	KaficSaPlazom();
	KaficSaPlazom(int _kapacitet);
	~KaficSaPlazom();

	int UkupnoLezaljki() const;
	double UkupnaSvotaNovca() const;
	bool PostojiGdeTrebaPlatiti(double svota) const;
	void VratiNajskuplje(ParLezaljki**, ParLezaljki**);

	void Dodaj(ParLezaljki* );
	void Oslobodi(int _redniBroj);
	void PrikaziSpisak(ostream& izlaz)const;
	friend ostream& operator<<(ostream&, const KaficSaPlazom&);
};