#pragma once
#include "Pice.h"

class Voda :
    public Pice
{
public:
    Voda(float _zapremina = 0);
    ~Voda(){}

    void Prikazi(ostream& izlaz)const override;
    Pice* kloniraj()override;
    float cena() const { return zapremina * brojAmbalaza; }
};

