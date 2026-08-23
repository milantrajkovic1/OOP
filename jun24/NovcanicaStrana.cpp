#include "NovcanicaStrana.h"

NovcanicaStrana::NovcanicaStrana(int _vrednost, const char* _kodvalute, double _kurs):Novcanica(_vrednost, 1)
{
	strcpy(kodValute, _kodvalute);
	kurs = _kurs;
}

bool NovcanicaStrana::operator==(const Novcanica& n) const
{
	return strcmp(kodValute, n.getKodValute()) == 0 && vrednost == n.getVrednost() && kurs == n.getKurs();
}

double NovcanicaStrana::ukupnaVrednost() const {
	return vrednost * broj * kurs;
}

void NovcanicaStrana::Prikazi(ostream& izlaz) const {
	izlaz << "Valuta: " << kodValute << endl <<
		"Kurs: "<< kurs<<endl<<
		"Vrednost: " << vrednost << endl <<
		"Broj Novcanica: " << broj << endl <<
		"Ukupna Vrednost: " << ukupnaVrednost()<< " RSD" << endl;
	izlaz << endl;
}

Novcanica* NovcanicaStrana::kloniraj()const {
	return new NovcanicaStrana(*this);
}