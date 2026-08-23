#include "Manifestacija.h"
#include <string.h>

void Manifestacija::AlocirajMem(int _kapacitet)
{
	kapacitet = _kapacitet;
	top = 0;
	kolekcija = new OsnovnaKarta * [kapacitet];
	for (int i = 0; i < kapacitet; i++) {
		kolekcija[i] = nullptr;
	}

}

void Manifestacija::OslobodiMem()
{
	for (int i = 0; i < kapacitet; i++) {
		delete kolekcija[i];
	}
	delete[] kolekcija;
}

Manifestacija::Manifestacija(int _kapacitet, int bs, const char* sektori,
	int dt, const float* pr)
{
	AlocirajMem(_kapacitet);
	brojSektora = bs;
	nizOznakaSektora = new char[brojSektora];
	for (int i = 0; i < brojSektora; i++) {
		nizOznakaSektora[i] = sektori[i];
	}

	DaniTrajanja = dt;
	ProcentualneVrednosti = new float[DaniTrajanja];

	for (int i = 0; i < DaniTrajanja; i++) {
		ProcentualneVrednosti[i] = pr[i];
	}
}

Manifestacija::Manifestacija(const Manifestacija& m)
{
	AlocirajMem(m.kapacitet);
	top = m.top;
	for (int i = 0; i < m.top; i++) {
		kolekcija[i] = m.kolekcija[i]->Kloniraj();
	}
	brojSektora = m.brojSektora;
	nizOznakaSektora = new char[brojSektora];
	for (int i = 0; i < brojSektora; i++) {
		nizOznakaSektora[i] = m.nizOznakaSektora[i];
	}

	DaniTrajanja = m.DaniTrajanja;
	ProcentualneVrednosti = new float[DaniTrajanja];

	for (int i = 0; i < DaniTrajanja; i++) {
		ProcentualneVrednosti[i] = m.ProcentualneVrednosti[i];
	}
	
}

Manifestacija::~Manifestacija()
{
	for (int i = 0; i < top; i++) {
		delete kolekcija[i];
	}
	delete[] kolekcija;
}

void Manifestacija::Dodaj(OsnovnaKarta* karta)
{
	if (karta != nullptr) {
		if (top < kapacitet) {
			kolekcija[top++] = karta;
		}
	}
}

void Manifestacija::VratiKarte(int index, int broj)
{
	if (index < 0 || index >= top || broj <= 0)
		return;
	int kraj = index + broj;
	if (kraj > top)
		kraj = top;
	int stvarniBroj = kraj - index;

	for (int i = index; i < kraj; i++) {
		delete kolekcija[i];
	}
	for (int i = kraj; i < top; i++) {
		kolekcija[i - stvarniBroj] = kolekcija[i];
	}
	top -= stvarniBroj;
	for (int i = top; i < top + stvarniBroj; i++) {
		kolekcija[i] = nullptr;
	}
	
}

float Manifestacija::UkupnaZarada() const
{
	float suma = 0;
	for (int i = 0; i < top; i++) {
		suma += kolekcija[i]->ProdajnaCena();
	}
	return suma;
}

char Manifestacija::SektorSaNajviseKarata() const
{
	char SektorSaNajvise = '\0';
	int brojKarata = -1;
	for (int i = 0; i < brojSektora; i++) {
		int broj = 0;
		for (int j = 0; j < top; j++) {
			if (nizOznakaSektora[i] == kolekcija[j]->getSektor()) {
				broj++;
			}
		}
		if (broj > brojKarata) {
			brojKarata = broj;
			SektorSaNajvise = nizOznakaSektora[i];
		}
	}
	return SektorSaNajvise;
}

int Manifestacija::DanSaNajvecomZaradom(int& zarada) const
{
	int Dan = 0;
	int NajvecaZarada = -1;
	for (int dan = 1; dan <= DaniTrajanja; dan++) {
		int UkupnaZaradaZaDan = 0;
		for (int i = 0; i < top; i++) {
			UkupnaZaradaZaDan += kolekcija[i]->ZaradaZaDan(dan, ProcentualneVrednosti[dan - 1]);
		}
		if (NajvecaZarada < UkupnaZaradaZaDan){
				NajvecaZarada = UkupnaZaradaZaDan;
				Dan = dan;
			}
	}
	zarada = NajvecaZarada;
	return Dan;
}

void Manifestacija::NajskupljeKarte(OsnovnaKarta** prva, OsnovnaKarta** druga)
{
	*prva = nullptr;
	*druga = nullptr;
	for (int i = 0; i < top; i++) {
		OsnovnaKarta* trenutna = kolekcija[i];
		if (*prva == nullptr ||
			trenutna->ProdajnaCena()
	        > (*prva)->ProdajnaCena())
		{
			*druga = *prva;
			*prva = trenutna;
		}
		else if (*druga==nullptr||trenutna->ProdajnaCena()
		> (*druga)->ProdajnaCena()) {
			*druga = trenutna;
		}
	}
}

void Manifestacija::prikazi(ostream& izlaz)const {
	izlaz << "Ukupno karata: " << kapacitet << endl
		<< "Prodatih karata: " << top << endl
		<< "Broj sektora: " << brojSektora << endl;
	for (int i = 0; i < top; i++) {
		izlaz << "karta broj: " << i + 1 << endl;
		izlaz << *kolekcija[i] << endl;
	}
	izlaz << endl;
}

ostream& operator<<(ostream& izlaz, const Manifestacija& m)
{
	m.prikazi(izlaz);
	return izlaz;
}
