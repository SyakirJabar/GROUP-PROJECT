//Racket.h
//derived from SportsEquip
#pragma once

#include "SportsEquip.h"

class Racket : public SportsEquip
{
private:
    char type{'R'};

public:\
    //constructors
    Racket(const str&, const str&, const int&, const int&, const int&, const double&);
    Racket();     //default

    ~Racket();    //destructor

    //getters
    char getType() const override;
    str getName() const override;
    str getCateg() const override;
    int getGoodQ() const override;  
    int getBrokenQ() const override;
    int getLostQ() const override;
    double getUnitValRM() const override;
};