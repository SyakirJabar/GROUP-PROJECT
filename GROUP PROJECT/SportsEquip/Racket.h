//Racket.h
//derived from SportsEquip
#pragma once

#include "SportsEquip.h"

class Racket : public SportsEquip
{
private:
    str name;
    str categ;      //category of sports equipment
    int goodQ;      //quantity of ball not lost or broken
    int brokenQ;
    int lostQ;

public:\
    //constructors
    Racket(const str&, const str&, const int&, const int&, const int&);
    Racket();     //default

    ~Racket();    //destructor

    //getters
    str getName() const override;
    str getCateg() const override;
    int getGoodQ() const override;  
    int getBrokenQ() const override;
    int getLostQ() const override;
};