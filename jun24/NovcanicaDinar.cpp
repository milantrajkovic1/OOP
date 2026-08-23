#include "NovcanicaDinar.h"

NovcanicaDinar::NovcanicaDinar(int _vrednost): Novcanica(_vrednost,1)
{

}

bool NovcanicaDinar::operator==(const Novcanica& n) const
{
    return vrednost == n.getVrednost();
}

void NovcanicaDinar::Prikazi(ostream& izlaz) const
{
    izlaz << "Valuta: DIN"<< endl<<
        "Vrednost: " << vrednost << endl <<
        "Broj Novcanica: " << broj << endl<<
        "Ukupna Vrednost: " << ukupnaVrednost() << endl;
    izlaz << endl;
}

Novcanica* NovcanicaDinar::kloniraj() const
{
    return new NovcanicaDinar(*this);
}
