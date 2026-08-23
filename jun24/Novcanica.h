#pragma once
#include <ostream>
#include <iostream>
using namespace std;
class Novcanica {
protected:
	int vrednost;
	int broj;
public:
	Novcanica(int _vrednost = 0, int _broj = 1);
	virtual ~Novcanica() {}

	void povecajBroj(int za = 1);
	void smanjiBroj(int za);

	int getVrednost()const { return vrednost; }
	int getBroj() const { return broj; }
	virtual const char* getKodValute()const { return "DIN"; }
	virtual double getKurs()const { return 0.0; }

	virtual bool operator==(const Novcanica& n) const = 0;

	virtual void Prikazi(ostream& izlaz=cout) const = 0;
	friend ostream& operator<<(ostream& izlaz, const Novcanica& n);
	virtual double ukupnaVrednost() const { return vrednost * broj; }
	virtual Novcanica* kloniraj()const = 0;
};