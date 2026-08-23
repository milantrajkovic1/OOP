#pragma once
#include "Avion.h"
#include "Putnicki.h"
#include "Teretni.h"
#include <fstream>

class Pista
{
	Avion** pista;
	int broj;
	int max;
public:
	Pista();
	Pista(int _max);
	Pista(const Pista& p);
	~Pista();

	void Dodaj(Avion* a);
	void SacuvajUFajl(const char* filename)const;
	Pista PopunjeniPreko95(); //proveri da l je double
	void ReorganizujAvioneNaPisti();
	const char* AvioKompanijaSaNajvecimStepenomPopunjenostiKapaciteta(); // vidi pov tip

	friend ostream& operator<<(ostream& izlaz, const Pista& p);
};

