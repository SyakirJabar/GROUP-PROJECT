//Projectile.h
//derived from SportsEquip
#pragma once

#include "SportsEquip.h"

class Projectile : public SportsEquip
{
private:
    str name;
    str categ;      //category of sports equipment
    int goodQ;      //quantity of ball not lost or broken
    int brokenQ;
    int lostQ;

public:\
    //constructors
    Projectile(const str&, const str&, const int&, const int&, const int&);
    Projectile();     //default

    ~Projectile();    //destructor

    //getters
    str getName() const override;
    str getCateg() const override;
    int getGoodQ() const override;  
    int getBrokenQ() const override;
    int getLostQ() const override;
};