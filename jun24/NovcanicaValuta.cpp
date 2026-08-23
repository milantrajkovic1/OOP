#include "NovcanicaValuta.h"
#include <cstring>
#include <iostream>
NovcanicaValuta::NovcanicaValuta()
{
	strcpy(kod, "RSD");
	vrednost = 0;
	kurs = 1;

}
NovcanicaValuta::NovcanicaValuta(const char* _kod, int _vrednost, float _kurs)
{
	strcpy(kod, _kod);
	vrednost = _vrednost;
	kurs = _kurs;
}

float NovcanicaValuta::vrednostUDinarima() const
{
	return vrednost*kurs;
}

bool NovcanicaValuta::operator<=(NovcanicaValuta& n)
{
	return vrednostUDinarima() <= n.vrednostUDinarima();
}

bool NovcanicaValuta::operator==(NovcanicaValuta& n)
{
	return strcmp(kod, n.kod) == 0 && vrednost == n.vrednost;
}

float NovcanicaValuta::operator+(float _vrednost)
{
	return (vrednost * kurs) + _vrednost;
}

ostream& operator<<(ostream& izlaz, const NovcanicaValuta& n)
{
	return izlaz << n.kod << " " << n.vrednost << " " << n.kurs;
}

istream& operator>>(istream& ulaz, NovcanicaValuta& n)
{
	return ulaz >> n.kod >> n.vrednost >> n.kurs;
}
