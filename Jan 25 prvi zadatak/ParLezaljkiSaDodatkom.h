#pragma once
#include "ParLezaljki.h"
class ParLezaljkiSaDodatkom :public ParLezaljki {
	int brDodatnih;
public:

	ParLezaljkiSaDodatkom(int rbr=0, int r=0, int c=0, int cp=0, int bd=0);

	int getbrDodatnih()const { return brDodatnih; }

	double SvotaZaNaplatu() const override;
	void Prikazi(ostream&) const override;
	int BrojLezaljki() const override;
};