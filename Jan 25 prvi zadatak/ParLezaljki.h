#pragma once
#include <iostream>
using namespace std;
class ParLezaljki {
protected:
	int redniBroj;
	int red;
	int cena;
	int cenaPica;
public:
	
	ParLezaljki(int _redniBroj=0, int _red=0,
		int _cena=0, int _cenaPica=0);
	virtual ~ParLezaljki() {};

	int getRedniBroj() const {return redniBroj;};
	int getRed()const { return red; }
	int getCena() const { return cena; }
	int getCenaPica() const { return cenaPica; }

	virtual double SvotaZaNaplatu()const;
	virtual int BrojLezaljki() const { return 2; }

	virtual void Prikazi(ostream& izlaz = cout)const;
	friend ostream& operator<<(ostream&, const ParLezaljki&);

};