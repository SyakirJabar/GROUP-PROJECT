//Ball.h
//derived from SportsEquip
#pragma once

#include "SportsEquip.h"

class Ball : public SportsEquip
{
private:
    char type{'B'};
    str name;
    str categ;      //category of sports equipment
    int goodQ;      //quantity of ball not lost or broken
    int brokenQ;
    int lostQ;
    double unitValRM;

public:
    //constructors
    Ball(const str&, const str&, const int&, const int&, const int&, const double&);
    Ball();     //default

    ~Ball();    //destructor

    //getters
    char getType() const override;
    str getName() const override;
    str getCateg() const override;
    int getGoodQ() const override;  
    int getBrokenQ() const override;
    int getLostQ() const override;
    double getUnitValRM() const override;
};