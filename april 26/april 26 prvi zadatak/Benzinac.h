#pragma once
#include "Automobil.h"
class Benzinac :public Automobil {

public:
	Benzinac();
	Benzinac(const char* r, int k, float zr, float pp, float zpg);
	Benzinac(const Benzinac&);
	~Benzinac() override {}

	float MaximalnaKilometraza()const override;
	void ObavljenaVoznja(int )override;

	Automobil* kloniraj()const override;
	void prikazi(ostream&) const;


};