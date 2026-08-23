#pragma once
#include "Avion.h"
class Teretni :
    public Avion
{
    int maxDolet;
    double maxMasaTereta;
    double trenutnaMasaTereta;
public:
    Teretni();
    Teretni(const char* _kod, const char* _naziv, int _maxDolet,
        double _maxMasaTereta, double _trenutnaMasaTereta);
    Teretni(const Teretni& t);
    ~Teretni(){}

    Avion* Kloniraj()override;
    void Prikazi(ostream& izlaz)const override;
    bool Preko90()const override;
    double StepenPopunjenosti() const override;
};

