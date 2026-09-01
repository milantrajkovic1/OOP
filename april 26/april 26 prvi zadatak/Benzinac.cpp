#include "Benzinac.h"

Benzinac::Benzinac() :Automobil()
{
}

Benzinac::Benzinac(const char* r, int k, float zr,
	float pp, float zpg):Automobil(r, k, zr, pp, zpg)
{
}

Benzinac::Benzinac(const Benzinac& b): Automobil(b)
{
}

float Benzinac::MaximalnaKilometraza() const
{
	return zapreminaRezervoara* prosecnaPotrosnja;
}

void Benzinac::ObavljenaVoznja(int duzina)
{
	Kilometraza += duzina;
	zapreminaPotrosenogGoriva += duzina / prosecnaPotrosnja;
}

Automobil* Benzinac::kloniraj() const
{
	return new Benzinac(*this);
}

void Benzinac::prikazi(ostream& izlaz) const {
	Automobil::prikazi(izlaz);
	izlaz << endl;
}