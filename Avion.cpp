#include "Avion.h"
#include <string.h>

Avion::Avion()
{
	kod = nullptr;
	nazivAvioKompanije = nullptr;
}

Avion::Avion(const char* _kod, const char* _nazivAvioKompanije)
{
	kod = new char[strlen(_kod) + 1];
	strcpy(kod, _kod);
	nazivAvioKompanije = new char[strlen(_nazivAvioKompanije) + 1];
	strcpy(nazivAvioKompanije, _nazivAvioKompanije);
}

Avion::Avion(const Avion& a)
{
	kod = new char[strlen(a.kod) + 1];
	strcpy(kod, a.kod);
	nazivAvioKompanije = new char[strlen(a.nazivAvioKompanije) + 1];
	strcpy(nazivAvioKompanije, a.nazivAvioKompanije);
}

Avion::~Avion()
{
	delete[] kod;
	delete[] nazivAvioKompanije;
}

void Avion::Prikazi(ostream& izlaz) const
{
	izlaz << "Kod Aviona: " << kod << endl
		<< "Naziv avio kompanije: "<<nazivAvioKompanije << endl;
}

ostream& operator<<(ostream& izlaz, const Avion& a)
{
	a.Prikazi(izlaz);
	return izlaz;
}
