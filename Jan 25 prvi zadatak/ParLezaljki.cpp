#include "ParLezaljki.h"

ParLezaljki::ParLezaljki(int _redniBroj, int _red,
	int _cena, int _cenaPica)
{
	redniBroj = _redniBroj;
	red = _red;
	cena = _cena;
	cenaPica = _cenaPica;
}

double ParLezaljki::SvotaZaNaplatu() const
{
	return cena + (cenaPica *(1-(40-2*red)/100.0));
}

void ParLezaljki::Prikazi(ostream& izlaz) const
{
	izlaz << "Redni broj: " << redniBroj << endl
		<< "Red: " << red << endl
		<< "Cena: " << cena << endl
		<< "Cena Pica: " << cenaPica << endl;
}

ostream& operator<<(ostream& izlaz, const ParLezaljki& p)
{
	p.Prikazi(izlaz);
	return izlaz;
}
