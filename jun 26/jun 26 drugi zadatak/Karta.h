#pragma once
#include <iostream>
using namespace std;
class Karta
{
	int oznaka;
	int cena;
	float popust;
public:
	Karta(int _oznaka=0, int _cena=0, float _popust=0);
	~Karta(){}

	int cenaSaPopustom()const;
	friend ostream& operator<<(ostream& izlaz, const Karta& k);
	friend istream& operator>>(istream& ulaz, Karta& k);

	bool operator>(int cena)const;
	bool operator>(Karta& k)const;
	bool operator<(Karta& k)const;
	Karta operator-(int za);
	int operator-(Karta& k);
	int operator+(int za);
};

