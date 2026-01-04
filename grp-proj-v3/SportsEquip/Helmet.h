//Helmet.h
//derived from SportsEquip
#pragma once

#include "SportsEquip.h"

class Helmet : public SportsEquip
{
private:
    char type{'H'};
    str name;
    str categ;      //category of sports equipment
    int goodQ;      //quantity of helmet not lost or broken
    int brokenQ;
    int lostQ;
    double unitValRM;

public:
    //constructors
    Helmet(const str&, const str&, const int&, const int&, const int&, const double&);
    Helmet();     //default

    ~Helmet();    //destructor

    //getters
    char getType() const override;
    str getName() const override;
    str getCateg() const override;
    int getGoodQ() const override;  
    int getBrokenQ() const override;
    int getLostQ() const override;
    double getUnitValRM() const override;
};