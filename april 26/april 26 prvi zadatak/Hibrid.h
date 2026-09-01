#pragma once
#include "Automobil.h"

class Hibrid : public Automobil {

	int maxKilometrazaNaElPogon;
public:
	Hibrid();
	Hibrid(const char* r, int k, float zr,
		float pp, float zpg, int mk);
	Hibrid(const Hibrid&);
	~Hibrid() override {}

	float MaximalnaKilometraza()const override;
	void ObavljenaVoznja(int )override;

	Automobil* kloniraj()const override;
	void prikazi(ostream& izlaz) const;
};