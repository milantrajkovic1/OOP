#include "Pice.h"

Pice::Pice(float _zapremina, int _brojAmbalaza)
{
	zapremina = _zapremina;
	brojAmbalaza = _brojAmbalaza;
}

void Pice::PovecajBroj(int za)
{
	brojAmbalaza += za;
}

void Pice::SmanjiBroj(int za)
{
	brojAmbalaza -= za;
}

bool Pice::operator==(const Pice& p)
{
	return zapremina==p.zapremina;
}


void Pice::Prikazi(ostream& izlaz) const
{
	izlaz << "Zapremina: " << zapremina << endl
		<< "Broj Ambalaza: " << brojAmbalaza << endl;
}

ostream& operator<<(ostream& izlaz, const Pice& p)
{
	p.Prikazi(izlaz);
	return izlaz;
}
