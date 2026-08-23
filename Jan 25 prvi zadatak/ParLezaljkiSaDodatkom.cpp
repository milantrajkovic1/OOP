#include "ParLezaljkiSaDodatkom.h"

ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom(int rbr, int r, int c, int cp, int bd):
	ParLezaljki(rbr,r,c,cp)
{
	brDodatnih = bd;
}

double ParLezaljkiSaDodatkom::SvotaZaNaplatu() const
{
	return cena * (1 + 0.4 * brDodatnih) +
		cenaPica * (1 - (40 - 2 * red - 5 * brDodatnih) / 100.0);
}

void ParLezaljkiSaDodatkom::Prikazi(ostream& izlaz) const
{
	ParLezaljki::Prikazi(izlaz);
	izlaz << "Broj dodatnih Lezaljki: " << 
		brDodatnih << endl;
}

int ParLezaljkiSaDodatkom::BrojLezaljki() const
{
	return 2+brDodatnih;
}
