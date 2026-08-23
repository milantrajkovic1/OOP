#include "Automobil.h"
Automobil::Automobil()
{
	RegistarskaOznaka = nullptr;
	Kilometraza = 0;
	zapreminaRezervoara = 0;
	prosecnaPotrosnja = 0;
	zapreminaPotrosenogGoriva = 0;
}

Automobil::Automobil(const char* r, int k, float zr, float pp, float zpg)
{
	RegistarskaOznaka = new char[strlen(r) + 1];
	strcpy(RegistarskaOznaka, r);
	Kilometraza = k;
	zapreminaRezervoara = zr;
	prosecnaPotrosnja = pp;
	zapreminaPotrosenogGoriva = zpg;
}

Automobil::Automobil(const Automobil& a)
{
	RegistarskaOznaka = new char[strlen(a.RegistarskaOznaka) + 1];
	strcpy(RegistarskaOznaka, a.RegistarskaOznaka);
	Kilometraza = a.Kilometraza;
	zapreminaRezervoara = a.zapreminaRezervoara;
	prosecnaPotrosnja = a.prosecnaPotrosnja;
	zapreminaPotrosenogGoriva = a.zapreminaPotrosenogGoriva;
}

Automobil::~Automobil()
{
	delete[] RegistarskaOznaka;
	RegistarskaOznaka = nullptr;
}

void Automobil::prikazi(ostream& izlaz) const
{
	izlaz << "Registarske Tablice: " << RegistarskaOznaka << endl
		<< "Kilometraza: " << Kilometraza << endl
		<< "Zapremina Rezervoara: " << zapreminaPotrosenogGoriva << endl
		<< "Prosecna potrosnja: " << prosecnaPotrosnja << endl
		<< "Zapremina Potrosenog Goriva: " << zapreminaPotrosenogGoriva << endl;
}


ostream& operator<<(ostream& izlaz, const Automobil& a)
{
	a.prikazi(izlaz);
	return(izlaz);
}
