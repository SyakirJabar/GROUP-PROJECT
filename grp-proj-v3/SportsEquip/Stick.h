//Stick.h
//derived from SportsEquip
#pragma once

#include "SportsEquip.h"

class Stick : public SportsEquip
{
private:
    char type{'S'};
    str name;
    str categ;      //category of sports equipment
    int goodQ;      //quantity of stick not lost or broken
    int brokenQ;
    int lostQ;
    double unitValRM;

public:
    //constructors
    Stick(const str&, const str&, const int&, const int&, const int&, const double&);
    Stick();     //default

    ~Stick();    //destructor

    //getters
    char getType() const override;
    str getName() const override;
    str getCateg() const override;
    int getGoodQ() const override;  
    int getBrokenQ() const override;
    int getLostQ() const override;
    double getUnitValRM() const override;
};