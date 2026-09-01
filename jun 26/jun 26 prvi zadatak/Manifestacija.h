#pragma once
#include"OsnovnaKarta.h"
#include"JednodnevnaKarta.h"
#include"KompletKarata.h"

class Manifestacija
{
	OsnovnaKarta** kolekcija;
	int top;
	int kapacitet;

	int brojSektora;
	char* nizOznakaSektora;

	int DaniTrajanja;
	float* ProcentualneVrednosti;

	void AlocirajMem(int);
	void OslobodiMem();
public:
	Manifestacija(int _kapacitet = 0, int bs = 0, const char* sektori="",
		int dt=0, const float* pr = nullptr);
	Manifestacija(const Manifestacija&);
	~Manifestacija();

	void Dodaj(OsnovnaKarta* );
	void VratiKarte(int, int);
	float UkupnaZarada()const;
	char SektorSaNajviseKarata()const;
	int DanSaNajvecomZaradom(int& zarada) const;
	void NajskupljeKarte(OsnovnaKarta** prva, OsnovnaKarta** druga);

	void prikazi(ostream& izlaz)const;
	friend ostream& operator<<(ostream& izlaz, const Manifestacija& m);

};

