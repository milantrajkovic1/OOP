#include "Voda.h"

Voda::Voda(float _zapremina):Pice(_zapremina,1)
{
}

void Voda::Prikazi(ostream& izlaz) const
{
	izlaz << "Voda: " << endl;
	Pice::Prikazi(izlaz);
}

Pice* Voda::kloniraj()
{
	return new Voda(*this);
}
