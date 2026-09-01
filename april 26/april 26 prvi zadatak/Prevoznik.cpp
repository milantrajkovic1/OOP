#include "Prevoznik.h"

void Prevoznik::AlocirajMem(int _max)
{
	max = _max;
	top = 0;
	kolekcija = new Automobil * [max];
	for (int i = 0; i < max; i++) {
		kolekcija[i] = nullptr;
	}
}

void Prevoznik::OslobodiMem()
{
	for (int i = 0; i < max; i++) {
		delete kolekcija[i];
	}
	delete[] kolekcija;
}

Prevoznik::Prevoznik()
{
	kolekcija = nullptr;
	top = max = 0;
}

Prevoznik::Prevoznik(int _max)
{
	AlocirajMem(_max);
}

Prevoznik::Prevoznik(const Prevoznik& p)
{
	AlocirajMem(p.max);
	for (int i = 0; i < p.top; i++) {
		kolekcija[i] = p.kolekcija[i]->kloniraj();
	}
}

Prevoznik::~Prevoznik()
{
	OslobodiMem();
}

void Prevoznik::ObavljenaVoznja(const char* reg, int duz)
{
	for (int i = 0; i < top; i++) {
		if (strcmp(kolekcija[i]->getRegistarska(), reg)==0) {
			kolekcija[i]->ObavljenaVoznja(duz);
			return;
		}
	}
}

Automobil* Prevoznik::NajpovoljnijiAutomobil(int Duzina)
{
	int index=-1;
	float najmanjaRazlika = 0;
	for (int i = 0; i < top; i++) {
		float razlika = kolekcija[i]->MaximalnaKilometraza() - Duzina;
		if (razlika >= 0) {
			if (index == -1 || razlika < najmanjaRazlika) {
				najmanjaRazlika = razlika;
				index = i;
			}
		}
		
	}
	if (index == -1) {
		return nullptr;
	}
	return kolekcija[index];
}

void Prevoznik::VratiNajDuzinuGorivo(Automobil** prvi, Automobil** drugi ) const
{
	if (top == 0)
	{
		*prvi = nullptr;
		*drugi = nullptr;
		return;
	}

	*prvi = kolekcija[0];
	*drugi = kolekcija[0];
	for (int i = 1; i < top; i++) {
		if (kolekcija[i]->getKilometraza() < (*prvi)->getKilometraza()) {
			(*prvi) = kolekcija[i];
		}
		if (kolekcija[i]->getPotrosenoGorivo()<(*drugi)->getPotrosenoGorivo()) {
			*drugi = kolekcija[i];
		}
	}
}

void Prevoznik::Dodaj(Automobil* a)
{
	if (top < max)
		kolekcija[top++] = a;
}

void Prevoznik::IzbaciPoKm(int km)
{
	for (int i = 0; i < top; i++)
	{
		if (kolekcija[i] != nullptr) {


			if (kolekcija[i]->getKilometraza() > km) {
				delete kolekcija[i];
				for (int j = i; j < top - 1; j++) {
					kolekcija[j] = kolekcija[j + 1];
				}
				i--;
				top--;
				kolekcija[top] = nullptr;

			}
		}
	}
}

void Prevoznik::prikazi(ostream&izlaz)const {
	izlaz << "=====SPISAK VOZILA U PREDUZECU=====" << endl
		<< "Trenutni Broj Vozila: " << top << endl
		<< "Kapacitet: " << max << endl;
	for (int i = 0; i < top; i++) {
		izlaz << "Vozilo broj: " << i + 1 << endl;
		kolekcija[i]->prikazi(izlaz);
	}
	izlaz << "------------------------------------" << endl;
}
ostream& operator<<(ostream& izlaz, const Prevoznik& p)
{
	p.prikazi(izlaz);
	return izlaz;
}

float Prevoznik::UkupnaKilometraza() const{
	float sum=0;
	for (int i = 0; i < top; i++) {
		sum += kolekcija[i]->getKilometraza();
	}
	return sum;
}