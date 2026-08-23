#include "OsnovnaKarta.h"
#include <string.h>

OsnovnaKarta::OsnovnaKarta(const char* _oznaka, char _sektor, int _cena)
{
	oznaka = new char[strlen(_oznaka) + 1];
	strcpy(oznaka, _oznaka);
	sektor = _sektor;
	cena = _cena;
}

OsnovnaKarta::OsnovnaKarta(const OsnovnaKarta& o)
{
	oznaka = new char[strlen(o.oznaka) + 1];
	strcpy(oznaka, o.oznaka);
	sektor = o.sektor;
}

OsnovnaKarta::~OsnovnaKarta()
{
	delete[] oznaka;
}

void OsnovnaKarta::prikazi(ostream& izlaz) const
{
	izlaz << "Oznaka: " << oznaka << endl;
	izlaz << "Sektor: " << sektor << endl;

}

ostream& operator<<(ostream& izlaz, OsnovnaKarta& o)
{
	o.prikazi(izlaz);
	return izlaz;
}
