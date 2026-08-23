#pragma once
#include "Novcanica.h"
class NovcanicaStrana : public Novcanica {
	char kodValute[4];
	double kurs;
public:
	NovcanicaStrana(int _vrednost=0, const char* _kodvalute="", double _kurs=0);
	~NovcanicaStrana(){}

	const char* getKodValute()const { return kodValute; }
	double getKurs()const { return kurs;}
	Novcanica* kloniraj()const;

	void Prikazi(ostream& izlaz) const;
	bool operator==(const Novcanica& n) const override;
	double ukupnaVrednost() const;
};