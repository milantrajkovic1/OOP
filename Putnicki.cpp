#include "Putnicki.h"

Putnicki::Putnicki()
{
	brSedista = nepopunjeni = sedistaBiznis = 0;
	masaKofera = 0;
}

Putnicki::Putnicki(const char* _kod, const char* _naziv, int _brSedista, int _nepopunjeni, 
	int _sedistaBiznis, double _masaKofera):Avion(_kod, _naziv)
{
	brSedista = _brSedista;
	nepopunjeni = _nepopunjeni;
	sedistaBiznis = _sedistaBiznis;
	masaKofera = _masaKofera;
}

Putnicki::Putnicki(const Putnicki& p):Avion(p)
{
	brSedista = p.brSedista;
	nepopunjeni = p.nepopunjeni;
	sedistaBiznis = p.sedistaBiznis;
	masaKofera = p.masaKofera;
}

Avion* Putnicki::Kloniraj()
{
	return new Putnicki(*this);
}

void Putnicki::Prikazi(ostream& izlaz) const
{
	izlaz << "Putnicki: " << endl;
	Avion::Prikazi(izlaz);
	izlaz << "Broj Sedista: " << brSedista << endl
		<< "Nepopunjena sedista: " << nepopunjeni << endl
		<< "Masa kofera: " << masaKofera<<endl;
}

bool Putnicki::Preko90() const
{
	
	return StepenPopunjenosti() > 0.9;
}

double Putnicki::StepenPopunjenosti() const
{
	int popunjena = brSedista - nepopunjeni;

	return (double)popunjena/brSedista;
}

