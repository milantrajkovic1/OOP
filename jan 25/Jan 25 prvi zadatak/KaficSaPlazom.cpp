#include "KaficSaPlazom.h"

void KaficSaPlazom::ZauzmiMem(int _kapacitet)
{
	kapacitet = _kapacitet;
	trenutnoIzdatih = 0;
	zarada = 0;
	kolekcija = new ParLezaljki * [kapacitet];
	for (int i = 0; i < kapacitet; i++)
		kolekcija[i] = nullptr;
}

void KaficSaPlazom::OslobodiMem()
{
	if (kolekcija != nullptr) {
		for (int i = 0; i < kapacitet; i++) {
			if (kolekcija[i] != nullptr) {
				delete kolekcija[i];
			}
		}
		delete[] kolekcija;
	}
}

KaficSaPlazom::KaficSaPlazom()
{
	kolekcija = nullptr;
	kapacitet = 0;
	trenutnoIzdatih = 0;
	zarada = 0;
}

KaficSaPlazom::KaficSaPlazom(int _kapacitet)
{
	ZauzmiMem(_kapacitet);
}

KaficSaPlazom::~KaficSaPlazom() 
{
	OslobodiMem();
}

int KaficSaPlazom::UkupnoLezaljki() const
{
	int suma=0;
	for (int i = 0; i < trenutnoIzdatih; i++) {
		suma += kolekcija[i]->BrojLezaljki();
	}
	return suma;
}

double KaficSaPlazom::UkupnaSvotaNovca() const
{
	return zarada;
}

bool KaficSaPlazom::PostojiGdeTrebaPlatiti(double svota) const
{
	for (int i = 0; i < trenutnoIzdatih; i++) {
		if (kolekcija[i]->SvotaZaNaplatu() > svota)
		{
			return true;
		}
	}
	return false;
}

void KaficSaPlazom::VratiNajskuplje(ParLezaljki** prva, ParLezaljki** druga)
{
	*prva = kolekcija[0];
	*druga = kolekcija[0];
	for (int i = 1; i < trenutnoIzdatih; i++) {
		if (kolekcija[i]->SvotaZaNaplatu() > (*prva)->SvotaZaNaplatu()) {
			*prva = kolekcija[i];
		}
		if (kolekcija[i]->getCenaPica() > (*druga)->getCenaPica()) {
			*druga = kolekcija[i];
		}
	}
}

void KaficSaPlazom::Dodaj(ParLezaljki* noveLezaljke)
{
	if (trenutnoIzdatih < kapacitet)
		kolekcija[trenutnoIzdatih++] = noveLezaljke;
}

void KaficSaPlazom::Oslobodi(int _redniBroj)
{
	int izbaceni = -1;
	for (int i = 0; i < trenutnoIzdatih; i++) {
		if (kolekcija[i]->getRedniBroj() == _redniBroj) {
			
			izbaceni = i;
			break;
		}
	}

	if (izbaceni == -1)
		return;

	zarada += kolekcija[izbaceni]->SvotaZaNaplatu();

	delete kolekcija[izbaceni];

	for (int i = izbaceni; i < trenutnoIzdatih -1 ; i++) {
		kolekcija[i] = kolekcija[i + 1];
	}
	trenutnoIzdatih--;
	kolekcija[trenutnoIzdatih] = nullptr;
}

ostream& operator<<(ostream& izlaz, const KaficSaPlazom& p)
{
	p.PrikaziSpisak(izlaz);
	return izlaz;
}

void KaficSaPlazom::PrikaziSpisak(ostream& izlaz) const
{
	izlaz << "======KAFIC SA PLAZOM======" << endl
		<< "Broj Izdatih parova: " << trenutnoIzdatih << endl
		<< "Naplaceni Novac: " << zarada << endl;
	izlaz << endl;

	for (int i = 0; i < trenutnoIzdatih; i++) {
		izlaz << "lezaljke na poziciji: " << i + 1 << ":" << endl;
		izlaz << *kolekcija[i];
		izlaz << "--------------------------"<<endl;
	}
}
	

