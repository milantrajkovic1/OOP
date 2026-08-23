#pragma once
#include "OsnovnaKarta.h"
class KompletKarata :
    public OsnovnaKarta
{
    float ProcenatPopusta;
public:
    KompletKarata(const char* _oznaka = "", char _sektor = '\0',int _cena =0, float Procenat = 0);
    KompletKarata(const KompletKarata&);
    ~KompletKarata(){}

    OsnovnaKarta* Kloniraj() override;
    float ProdajnaCena()const override;
    float ZaradaZaDan(int dan, float procenat)const override;

    void prikazi(ostream& izlaz) const override;
};

