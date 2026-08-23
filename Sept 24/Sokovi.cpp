#include "Sokovi.h"

Sokovi::Sokovi()
{
	naziv = nullptr;
	zapremina = procenat = 0;
}

Sokovi::Sokovi(const char* _naziv, float _zapremina, int _procenat)
{
	naziv = new char[strlen(_naziv) + 1];
	strcpy(naziv, _naziv);
	zapremina = _zapremina;
	procenat = _procenat;
}

Sokovi::Sokovi(const Sokovi& s)
{
	naziv = new char[strlen(s.naziv) + 1];
	strcpy(naziv, s.naziv);
	zapremina = s.zapremina;
	procenat = s.procenat;
}

Sokovi::~Sokovi()
{
	delete[] naziv;
}

Sokovi& Sokovi::operator=(const Sokovi& s)
{
	
	if (this != &s) {
		delete[] naziv;

		naziv = new char[strlen(s.naziv) + 1];
		strcpy(naziv, s.naziv);
		zapremina = s.zapremina;
		procenat = s.procenat;
	}
	return *this;
}

bool Sokovi::operator>(Sokovi& s)
{
	return zapremina>s.zapremina;
}

bool Sokovi::operator==(Sokovi& s)
{
	return zapremina==s.zapremina;
}

float Sokovi::operator+(float desni)
{
	return zapremina+desni;
}

float Sokovi::operator+(const Sokovi& s)
{
	return zapremina+s.zapremina;
}


ostream& operator<<(ostream& izlaz, const Sokovi& s)
{
	izlaz << s.naziv << endl << s.zapremina << endl << s.procenat << endl;
	return izlaz;
}

istream& operator>>(istream& ulaz,  Sokovi& s)
{
	char nazivVoca[100];
	float zapremina;
	int procenatVoca;

	if (ulaz >> nazivVoca >> zapremina >> procenatVoca) {
		delete[] s.naziv;
		s.zauzmiMem(nazivVoca, zapremina, procenatVoca);
	}
	return ulaz;
}

void Sokovi::zauzmiMem(const char* nazivVoca, float zapremina, int procenatVoca)
{
	this->naziv = new char[strlen(nazivVoca) + 1];
	strcpy(this->naziv, nazivVoca);
	this->zapremina = zapremina;
	this->procenat = procenatVoca;
}