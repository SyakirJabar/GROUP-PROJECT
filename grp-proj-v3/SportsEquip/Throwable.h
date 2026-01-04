//Projectile.h
//derived from SportsEquip
#pragma once

#include "SportsEquip.h"

class Throwable : public SportsEquip
{
private:
    char type{'T'};
    str name;
    str categ;      //category of sports equipment
    int goodQ;      //quantity of ball not lost or broken
    int brokenQ;
    int lostQ;
    double unitValRM;

public:
    //constructors
    Throwable(const str&, const str&, const int&, const int&, const int&, const double&);
    Throwable();     //default

    ~Throwable();    //destructor

    //getters
    char getType() const override;
    str getName() const override;
    str getCateg() const override;
    int getGoodQ() const override;  
    int getBrokenQ() const override;
    int getLostQ() const override;
    double getUnitValRM() const override;
};