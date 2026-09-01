#pragma once
#include <ostream>
using namespace std;
class OsnovnaKarta {
protected:
	char* oznaka;
	char sektor;
	int cena;
public:
	OsnovnaKarta(const char* _oznaka = "", char _sektor = '\0', int _cena=0);
	OsnovnaKarta(const OsnovnaKarta&);
	virtual ~OsnovnaKarta();

	virtual OsnovnaKarta* Kloniraj() = 0;
    int getCena()const { return cena; }
	char getSektor() { return sektor; }
	virtual float ProdajnaCena()const = 0;
	virtual float ZaradaZaDan(int dan, float)const = 0;

	virtual void prikazi(ostream& izlaz)const;
	friend ostream& operator<<(ostream& izlaz, OsnovnaKarta& o);

};