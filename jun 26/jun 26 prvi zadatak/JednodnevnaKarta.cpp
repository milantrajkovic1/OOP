#include "JednodnevnaKarta.h"

JednodnevnaKarta::JednodnevnaKarta(const char* _oznaka, char _sektor,int _cena,
	int rbd):OsnovnaKarta(_oznaka, _sektor, _cena)
{
	RedniBrojDana = rbd;
}

JednodnevnaKarta::JednodnevnaKarta(const JednodnevnaKarta& o)
	:OsnovnaKarta(o)
{
	RedniBrojDana = o.RedniBrojDana;
}

OsnovnaKarta* JednodnevnaKarta::Kloniraj()
{
	return new JednodnevnaKarta(*this);
}

float JednodnevnaKarta::ProdajnaCena() const
{
	return getCena();
}

float JednodnevnaKarta::ZaradaZaDan(int dan, float procenat) const
{
	if(RedniBrojDana== dan)
	return ProdajnaCena();

	return 0;
}



void JednodnevnaKarta::prikazi(ostream& izlaz) const
{
	OsnovnaKarta::prikazi(izlaz);
	izlaz << "Redni Broj dana: " << RedniBrojDana << endl;
}
