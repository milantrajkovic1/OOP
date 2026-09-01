#include "Hibrid.h"

Hibrid::Hibrid() :Automobil()
{
	maxKilometrazaNaElPogon = 0;
}

Hibrid::Hibrid(const char* r, int k, float zr,
	float pp, float zpg, int mk):Automobil(r, k, zr, pp, zpg)
{
	maxKilometrazaNaElPogon = mk;
}

Hibrid::Hibrid(const Hibrid& h):Automobil(h)
{
	maxKilometrazaNaElPogon = h.maxKilometrazaNaElPogon;
}

Automobil* Hibrid::kloniraj() const
{
	return new Hibrid(*this);
}

float Hibrid::MaximalnaKilometraza() const
{
	return zapreminaRezervoara*prosecnaPotrosnja+maxKilometrazaNaElPogon;
}

void Hibrid::prikazi(ostream& izlaz) const
{
	Automobil::prikazi(izlaz);
	izlaz << "Maxmimalna Kilometraza: " << maxKilometrazaNaElPogon << endl;
	izlaz << endl;
}

void Hibrid::ObavljenaVoznja(int duzina)
{
	Kilometraza += duzina;
	int DuzinaPredjenaGorivom = duzina - maxKilometrazaNaElPogon;
	if (DuzinaPredjenaGorivom > 0) {
		zapreminaPotrosenogGoriva += DuzinaPredjenaGorivom / prosecnaPotrosnja;
	}
}
