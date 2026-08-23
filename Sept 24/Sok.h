#pragma once
#include "Pice.h"
class Sok :
    public Pice
{
    char* ukus;
    int procenatVoca;
    float odnosCene;
public:
    Sok(float _zapremina, const char* _ukus, int _procenat, float _odnosCene);
    Sok(const Sok& s);
    ~Sok();

    const char* getUkus()const override{ return ukus; }
    int getProcenatVoca()const override{ return procenatVoca; }
    Pice* kloniraj();
    void Prikazi(ostream& izlaz=cout)const override;
    float getOdnosCene() const override{ return odnosCene; }
    bool operator==(const Pice& p) override;
    float cena() const override;
};

