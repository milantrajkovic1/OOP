#include "Teretni.h"

Teretni::Teretni()
{
	maxDolet = maxMasaTereta = trenutnaMasaTereta = 0;
}

Teretni::Teretni(const char* _kod, const char* _naziv, int _maxDolet,
	double _maxMasaTereta, double _trenutnaMasaTereta) :Avion(_kod, _naziv)
{
	maxDolet = _maxDolet;
	maxMasaTereta = _maxMasaTereta;
	trenutnaMasaTereta = _trenutnaMasaTereta;
}

Teretni::Teretni(const Teretni& t):Avion(t)
{
	maxDolet = t.maxDolet;
	maxMasaTereta = t.maxMasaTereta;
	trenutnaMasaTereta = t.trenutnaMasaTereta;
}

Avion* Teretni::Kloniraj()
{
	return new Teretni(*this);
}

void Teretni::Prikazi(ostream& izlaz) const
{
	izlaz << "Teretni " << endl;
	Avion::Prikazi(izlaz);
	izlaz << "Maxmimalni dolet: " << maxDolet << endl
		<< "Maximalna masa tereta: " << maxMasaTereta << endl
		<< "Trenunta masa tereta: " << trenutnaMasaTereta << endl;
}

bool Teretni::Preko90() const
{
	return StepenPopunjenosti() > 0.9;
}

double Teretni::StepenPopunjenosti() const
{
	return (double)trenutnaMasaTereta/maxMasaTereta;
}
