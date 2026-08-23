#include "Sok.h"
#include <cstring>
Sok::Sok(float _zapremina,
	const char* _ukus, int _procenat, float _odnosCene):Pice(_zapremina,1 )
{
	ukus = new char[strlen(_ukus) + 1];
	strcpy(ukus, _ukus);
	procenatVoca = _procenat;
	odnosCene = _odnosCene;
}

Sok::Sok(const Sok& s):Pice(s)
{
	ukus = new char[strlen(s.ukus) + 1];
	strcpy(ukus, s.ukus);
	procenatVoca = s.procenatVoca;
	odnosCene = s.odnosCene;
}

Sok::~Sok()
{
	delete[] ukus;
}

Pice* Sok::kloniraj()
{
	return new Sok(*this);
}


bool Sok::operator==(const Pice& p)
{
	return zapremina == p.getZapremina() && strcmp(ukus, p.getUkus()) == 0 &&
		procenatVoca == p.getProcenatVoca() && odnosCene == p.getOdnosCene();
}

void Sok::Prikazi(ostream& izlaz) const
{
	izlaz << "Sok: " << endl;
	Pice::Prikazi(izlaz);
	izlaz << "ukus: " << ukus << endl
		<< "procenat voca: " << procenatVoca << endl
		<< "Odnos cene: " << odnosCene << endl;
}

float Sok::cena() const
{
	float litriVodeUSoku = ((100 - procenatVoca) / 100.0f) * zapremina;

	float x = (litriVodeUSoku * 100) / (odnosCene * 100);

	return x * brojAmbalaza;
}
