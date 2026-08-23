#include "PorodicniNovcanik.h"
#include <iostream>

void PorodicniNovcanik::AlocirajMem(int _max)
{
	max = _max;
	top = 0;
	kolekcija = new Novcanica * [max];
	for (int i = 0; i < max; i++) {
		kolekcija[i] = nullptr;
	}
}

void PorodicniNovcanik::DealocirajMem()
{
	for (int i = 0; i < top; i++) {
		delete kolekcija[i];
	}
	delete[] kolekcija;
}

double PorodicniNovcanik::UkupnaSvota()
{
	double suma = 0.0;
	for (int i = 0; i < top; i++) {
		suma += kolekcija[i]->ukupnaVrednost();
	}
	return suma;
}

PorodicniNovcanik::PorodicniNovcanik(int _max)
{
	AlocirajMem(_max);
}

PorodicniNovcanik::~PorodicniNovcanik()
{
	DealocirajMem();
}

void PorodicniNovcanik::Dodaj(Novcanica* n)
{
	for (int i = 0; i < top; i++) {
		if (typeid(*kolekcija[i]) == typeid(*n) && (*kolekcija[i]) == (*n)) {
			kolekcija[i]->povecajBroj();
			delete n;
			return;
		}
	}
	if (top < max) {
		kolekcija[top++] = n;
	}
	else {
		cout << "Kolekcija je puna" << endl;
	}
}

void PorodicniNovcanik::Izdvoji(Novcanica& n, int Broj)
{
	for (int i = 0; i < top; i++) {
		if (typeid(*kolekcija[i]) == typeid(n) && *kolekcija[i] == n) {
			if (Broj > kolekcija[i]->getBroj()) {
				cout << "Nema dovoljno novcanica" << endl;
				return;
			}

			kolekcija[i]->smanjiBroj(Broj);

			if (kolekcija[i]->getBroj() == 0) {
				delete kolekcija[i];
				for (int j = i; j < top - 1; j++) {
					kolekcija[j] = kolekcija[j + 1];
				}
				kolekcija[top - 1] = nullptr;
				top--;
			}
			return;
		}
	}
}

void PorodicniNovcanik::Rasitni(Novcanica& veca, Novcanica& manja)
{
	if (typeid(veca) != typeid(manja)) {
		cout << "Novcanice nisu iste vlaute"<<endl;
		return;
	}
	if (veca.getVrednost() <= manja.getVrednost()) {
		cout << "Nije moguce rasitniti" << endl;
		return;
	}
	if (veca.getVrednost() % manja.getVrednost() != 0) {
		cout << "Nije moguce rasitniti" << endl;
		return;
	}
	int brojManjih = veca.getVrednost() / manja.getVrednost();
	Izdvoji(veca, 1);
	
	for (int i = 0; i < top; i++) {
		if (typeid(*kolekcija[i]) == typeid(manja) && *kolekcija[i] == manja) {
			kolekcija[i]->povecajBroj(brojManjih);
			return;
		}
	}
	for (int i = 0; i < brojManjih; i++) {
		Dodaj(manja.kloniraj());
	}
	return;
}

bool PorodicniNovcanik::MozePlatiti(int svota)
{
	return UkupnaSvota()>svota;
}

void PorodicniNovcanik::VratiNaj(Novcanica** min, Novcanica** max)
{
	*min = kolekcija[0];
	*max = kolekcija[0];
	for (int i = 1; i < top; i++) {
		if (kolekcija[i]->ukupnaVrednost() < (*min)->ukupnaVrednost()) {
			*min = kolekcija[i];
		}
		if (kolekcija[i]->ukupnaVrednost() > (*max)->ukupnaVrednost()) {
			*max = kolekcija[i];
		}
	}
}

ostream& operator<<(ostream& izlaz, const PorodicniNovcanik& p)
{
	izlaz << "Kapacitet: " << p.max << endl <<
		"Trenutno ima: " << p.top << " novcanica" << endl <<
		"---------SPISAK NOVCANICA---------" << endl;
	for (int i = 0; i < p.top; i++) {
		izlaz << *p.kolekcija[i];
	}
	izlaz << endl;
	return izlaz;
}
