#include "Pista.h"
#include <iostream>

Pista::Pista()
{
	pista = nullptr;
	broj = max = 0;

}

Pista::Pista(int _max)
{
	max = _max;
	broj = 0;
	pista = new Avion*[max];
	for (int i = 0; i < max; i++) {
		pista[i] = nullptr;
	}
}

Pista::Pista(const Pista& p)
{
	broj = 0;
	max = p.max;
	pista = new Avion * [max];
	for (int i = 0; i < p.broj; i++) {
		pista[broj++] = p.pista[i]->Kloniraj();
	}
}

Pista::~Pista()
{
	for (int i = 0; i < broj; ++i) {
		delete pista[i];
	}
	delete[] pista;
}

void Pista::Dodaj(Avion* a)
{
	if (broj < max) {
		pista[broj++] = a;
	}
}

void Pista::SacuvajUFajl(const char* filename)const
{
	ofstream izlaz(filename);

	if (!izlaz.good()) {
		cout << "fajl nije uspeno ucitan!";
		return;
	}

	izlaz << *this;
	izlaz.close();
}

Pista Pista::PopunjeniPreko95()
{
	Pista p(broj);
	for (int i = 0; i < broj; i++) {
		if (pista[i]->Preko90()) {
			p.Dodaj(pista[i]->Kloniraj());
		}
	}
	return p;
}

void Pista::ReorganizujAvioneNaPisti()
{
	Avion* pom;
	for (int i = 0; i < broj - 1; ++i) {
		for (int j = i + 1; j < broj; j++) {
			if (pista[i]->StepenPopunjenosti() < pista[j]->StepenPopunjenosti()) {
				pom = pista[i];
				pista[i] = pista[j];
				pista[j] = pom;
			}
		}
	}
}

const char* Pista::AvioKompanijaSaNajvecimStepenomPopunjenostiKapaciteta()
{
	const char* NAZIV = nullptr;
	const char** nizKompanija = new const char* [broj];
	int trIma = 0;

	for (int i = 0; i < broj; i++) {
		const char* naziv = pista[i]->getNazivKompanije();
		bool postoji = false;

		for (int j = 0; j < trIma; j++) {
			if (strcmp(naziv, nizKompanija[j]) == 0) {
				postoji = true;
				break;
			}
		}

		if (!postoji)
			nizKompanija[trIma++] = naziv;
	}
	double stepen = 0;
	for (int i = 0; i < trIma; i++) {
		int broj = 0;
		double stepenNovi = 0;
		for (int j = 0; j < trIma; j++) {
			if (strcmp(nizKompanija[i], pista[j]->getNazivKompanije()) == 0)
			{
				stepenNovi += pista[j]->StepenPopunjenosti();
				++broj;
			}
			
		}
		stepenNovi /= broj;
		if (stepenNovi > stepen) {
			NAZIV = nizKompanija[i];
			stepen = stepenNovi;
		}
				
	}
	delete[] nizKompanija;
	return NAZIV;
}

ostream& operator<<(ostream& izlaz, const Pista& p)
{
	izlaz << "-------STANJE PISTE-------"<<endl;
	izlaz << "Kapacitet: " << p.max << endl
		<< "Trenutno aviona na pisti: " << p.broj << endl
		<< "--------SPISAK AVIONA----------" << endl;
	for (int i = 0; i < p.broj; ++i) {
		izlaz << *p.pista[i]<<p.pista[i]->StepenPopunjenosti()<<endl;
	}
	izlaz << endl;
	return izlaz;
}
