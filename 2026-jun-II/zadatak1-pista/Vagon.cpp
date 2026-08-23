#include "Vagon.h"

Vagon::Vagon(float _masa, float _masaTereta)
{
	masa = _masa;
	masaTereta = _masaTereta;
	if (masaTereta > masa)
		throw new exception("Masa tereta veca od MASE VAGONA!");
}

bool Vagon::operator>(const Vagon& v) const
{
	return masaTereta>v.masaTereta;
}

Vagon Vagon::operator+(const Vagon& v) const
{
	Vagon pom(masa + v.masa, masaTereta + v.masaTereta);
	return pom;
}

ostream& operator<<(ostream& izlaz, const Vagon& v)
{
	izlaz << v.masa << " " << v.masaTereta << endl;
	return izlaz;
}

istream& operator>>(istream& ulaz, Vagon& v)
{
	float masa;
	float teret;

	cout << "Masa: ";
	ulaz >> masa;
	cout << "Teret: ";
	ulaz >> teret;

	v = Vagon(masa, teret);
	return ulaz;
}
