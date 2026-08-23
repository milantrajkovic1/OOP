#include "Skladiste.h"

Skladiste::Skladiste()
{
	max = 0;
	top = 0;
	kolekcija = nullptr;
}

Skladiste::Skladiste(int _max)
{
	max = _max;
	top = 0;
	kolekcija = new Pice*[max];
}

Skladiste::~Skladiste()
{
	for (int i = 0; i < top; i++) {
		delete kolekcija[i];
	}
	delete[] kolekcija;
}

void Skladiste::Dodaj(Pice* p)
{
	if (p == nullptr)
		return;

	for (int i = 0; i < top; i++) {
		if (kolekcija[i] != nullptr &&
			typeid(*p) == typeid(*kolekcija[i]) &&
			*p == *kolekcija[i]) {

			kolekcija[i]->PovecajBroj();
			delete p;
			return;
		}
	}

	if (top == max) {
		cout << "Kolekcija je puna" << endl;
		delete p;
		return;
	}

	kolekcija[top++] = p;
}

void Skladiste::Izdvoji(Pice& p, int br)
{
	for (int i = 0; i < top; i++) {
		if (typeid(p) == typeid(*kolekcija[i]) && p == *kolekcija[i]) {
			if (br > kolekcija[i]->getBrojAmbalaza()) {
				cout << "Nema tolko ambalaza";
				return;
			}
			kolekcija[i]->SmanjiBroj(br);
			if (kolekcija[i]->getBrojAmbalaza() == 0) {
				delete kolekcija[i];
				for (int j = i; j < top - 1;j++) {
					kolekcija[j] = kolekcija[j + 1];
				}
				kolekcija[top - 1] = nullptr;
				top--;
			}
		}
	}
}

void Skladiste::Presipaj(Pice& vece, Pice& manje)
{
	if (vece.getZapremina() < manje.getZapremina()) {
		cout << "Nije moguce presipati" << endl;
		return;
	}

	float vecaZapremina = vece.getZapremina();
	float manjaZapremina = manje.getZapremina();

	float zaDodati = vecaZapremina / manjaZapremina;
	float ukupnaZapremina = 0.0f;
	for (int i = 0; i < top; i++) {
		if (typeid(vece) == typeid(*kolekcija[i]) && vece == *kolekcija[i])
		{
			kolekcija[i]->SmanjiBroj(1);
		}
	}
	
	for (int i = 0; i < zaDodati; i++) {
		Dodaj(manje.kloniraj());
	}
	return;
}

bool Skladiste::DovoljnaKolicina(int kolicina)
{
	float ukupnaKolicina = 0.0f;
	for (int i = 0; i < top; i++) {
		ukupnaKolicina += kolekcija[i]->ukupnaZapremina();
	}
	return ukupnaKolicina>=kolicina;
}

void Skladiste::VratiNaj(Pice** prvo, Pice** drugo)
{
	*prvo = kolekcija[0];
	*drugo = kolekcija[0];
	for (int i = 1; i < top; i++) {
		if ((*prvo)->cena() > kolekcija[i]->cena()) {
			*prvo = kolekcija[i];
		}
		if ((*drugo)->cena() < kolekcija[i]->cena()) {
			*drugo = kolekcija[i];
		}
	}
	return;

}

ostream& operator<<(ostream& izlaz, const Skladiste& s)
{
	izlaz << "Kapacitet: " << s.max << endl
		<< "Trenutno ima: " << s.top << endl;
	izlaz << "-------SPISAK FLASA---------" << endl;
	for (int i = 0; i < s.top; i++) {
		s.kolekcija[i]->Prikazi(izlaz);
		izlaz << endl;
	}
	izlaz << endl;
	return izlaz;
}
