#pragma once
#include <iostream>
using namespace std;

class Avion
{
protected:
	char* kod;
	char* nazivAvioKompanije;
public:
	Avion();
	Avion(const char* _kod, const char* _naziv);
	Avion(const Avion& a);
	virtual ~Avion();

	const char* getNazivKompanije() const { return nazivAvioKompanije; }
	virtual Avion* Kloniraj() = 0;
	virtual void Prikazi(ostream& izlaz)const;
	virtual bool Preko90() const=0;
	virtual double StepenPopunjenosti() const = 0;
	friend ostream& operator<<(ostream& izlaz, const Avion& a);
};

