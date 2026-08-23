#pragma once
#include <iostream>
using namespace std;
class Pice
{
protected:
	float zapremina;
	int brojAmbalaza;
public:
	Pice(float _zapremina = 0, int _brojAmbalaza = 0);
	virtual ~Pice(){}
	void PovecajBroj(int za=1);
	void SmanjiBroj(int za);
	float getZapremina()const { return zapremina; }
	int getBrojAmbalaza()const { return brojAmbalaza; }

	float ukupnaZapremina()const { return zapremina * brojAmbalaza; }
	virtual const char* getUkus()const { return nullptr; }
	virtual int getProcenatVoca()const { return 0; }
	virtual float getOdnosCene() const { return 1; }

	virtual Pice* kloniraj() = 0;
	virtual bool operator==(const Pice& p);
	virtual void Prikazi(ostream& izlaz =cout)const;
	friend ostream& operator<<(ostream& izlaz, const Pice& p);
	
	virtual float cena() const = 0;
};

