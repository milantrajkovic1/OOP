#include "Novcanica.h"

Novcanica::Novcanica(int _vrednost, int _broj)
{
	vrednost = _vrednost;
	broj = _broj;
}

void Novcanica::povecajBroj(int za)
{
	broj += za;
}

void Novcanica::smanjiBroj(int za)
{
	broj -= za;
}

ostream& operator<<(ostream& izlaz, const Novcanica& n)
{
	n.Prikazi(izlaz);
	return izlaz;
}
