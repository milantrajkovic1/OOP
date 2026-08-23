#pragma once
#include "OsnovnaKarta.h"
class JednodnevnaKarta :
    public OsnovnaKarta
{
    int RedniBrojDana;
public:
    JednodnevnaKarta(const char* _oznaka = "", char _sektor = '\0', int _cena = 0, int rbd = 0);
    JednodnevnaKarta(const JednodnevnaKarta&);
    ~JednodnevnaKarta() {}

    OsnovnaKarta* Kloniraj();
    float ProdajnaCena()const override;
    float ZaradaZaDan(int dan, float procenat)const override;

    void prikazi(ostream&) const override;

};

