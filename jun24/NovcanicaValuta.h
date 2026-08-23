#pragma once
#include <iostream>
using namespace std;
class NovcanicaValuta
{
	char kod[4];
	int vrednost;
	float kurs;
public:
	NovcanicaValuta();
	NovcanicaValuta(const char* _kod, int _vrednost, float _kurs);
	~NovcanicaValuta(){}
	friend ostream& operator<<(ostream& izlaz, const NovcanicaValuta& n);
	friend istream& operator>>(istream& ulaz, NovcanicaValuta& n);
	float vrednostUDinarima()const;
	bool operator<=(NovcanicaValuta& n);
	bool operator==(NovcanicaValuta& n);
	float operator+(float _vrednost);

};

