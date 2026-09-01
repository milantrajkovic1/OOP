#include "KompletKarata.h"


KompletKarata::KompletKarata(const char* _oznaka, char _sektor,int _cena,
	float Procenat) : OsnovnaKarta(_oznaka, _sektor, _cena)
{
	ProcenatPopusta = Procenat;
}

KompletKarata::KompletKarata(const KompletKarata& k):OsnovnaKarta(k)
{
	ProcenatPopusta = k.ProcenatPopusta;
}

OsnovnaKarta* KompletKarata::Kloniraj()
{
	return new KompletKarata(*this);
}

float KompletKarata::ProdajnaCena() const
{
	return cena * (1 - ProcenatPopusta / 100.0f);
}

float KompletKarata::ZaradaZaDan(int dan, float procenat) const
{

	return ProdajnaCena() * procenat / 100;
}

void KompletKarata::prikazi(ostream& izlaz) const
{
	OsnovnaKarta::prikazi(izlaz);
	izlaz << "Procenat popusta: " << ProcenatPopusta << endl;
}
