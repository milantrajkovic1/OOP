#pragma once
#include "Novcanica.h"
class NovcanicaDinar : public Novcanica {

public:
	NovcanicaDinar(int _vrednost = 0);
	~NovcanicaDinar() {}

	bool operator==(const Novcanica& n) const;
	void Prikazi(ostream& izlaz) const;
	Novcanica* kloniraj()const;
};