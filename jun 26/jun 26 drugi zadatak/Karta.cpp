#include "Karta.h"

Karta::Karta(int _oznaka, int _cena, float _popust)
{
	oznaka = _oznaka;
	cena = _cena;
	popust = _popust;
}

int Karta::cenaSaPopustom()const
{
	return int(cena * (1 - popust/100));
}

bool Karta::operator>(int cena) const
{
	return this->cenaSaPopustom() > cena;
}

bool Karta::operator>(Karta& k) const
{
	return cenaSaPopustom() > k.cenaSaPopustom();
}

bool Karta::operator<(Karta& k) const
{
	return cenaSaPopustom() < k.cenaSaPopustom();
}

Karta Karta::operator-(int za)
{
	Karta pom(*this);
	pom.cena -= za;
	return pom;
}

int Karta::operator-(Karta& k)
{
	return cenaSaPopustom() - k.cenaSaPopustom();
}

int Karta::operator+(int za)
{
	return cenaSaPopustom()+za;
}

ostream& operator<<(ostream& izlaz, const Karta& k)
{
	izlaz << k.oznaka << endl
		<< k.cena << endl
		<< k.popust << endl;
	return izlaz;
}

istream& operator>>(istream& ulaz, Karta& k)
{
	ulaz >> k.oznaka >> k.cena >> k.popust;
	return ulaz;
}
