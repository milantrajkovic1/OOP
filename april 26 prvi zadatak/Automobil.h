#pragma once
#include <cstring>
#include <ostream>
using namespace std;
class Automobil {
protected:
	char* RegistarskaOznaka;
	int Kilometraza;
	float zapreminaRezervoara;
	float prosecnaPotrosnja;
	float zapreminaPotrosenogGoriva;
public:
	Automobil();
	Automobil(const char*, int, float, float, float);
	Automobil(const Automobil&);
	virtual ~Automobil();

	const char* getRegistarska()const { return RegistarskaOznaka; }
	int getKilometraza()const { return Kilometraza; }
	float getPotrosenoGorivo() const { return zapreminaPotrosenogGoriva; }
	virtual  float MaximalnaKilometraza() const = 0;
	virtual void ObavljenaVoznja(int ) = 0;

	virtual Automobil* kloniraj()const = 0;
	virtual void prikazi(ostream& )const;
	friend ostream& operator<<(ostream&, const Automobil&);

};