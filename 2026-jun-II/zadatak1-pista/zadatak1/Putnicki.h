#pragma once
#include "Avion.h"
class Putnicki :
    public Avion
{
    int brSedista;
    int nepopunjeni;
    int sedistaBiznis;
    double masaKofera;
public:
    Putnicki();
    Putnicki(const char* _kod, const char* _naziv, int _brSedista,
        int _nepopunjeni, int _sedistaBiznis, double _masaKofera);
    Putnicki(const Putnicki& p);
    ~Putnicki(){}

    Avion* Kloniraj();
    void Prikazi(ostream& izlaz)const override;
    bool Preko90() const override;
    double StepenPopunjenosti() const;
};

