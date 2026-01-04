//SportsEquip.h
//base (abstract) class
#pragma once

#include <string>

typedef std::string str;

class SportsEquip
{
public:
    ~SportsEquip();     //destructor

    //getters (virtual)
    //does not modify object representation
    virtual char getType() const = 0;
    virtual str getName() const = 0;
    virtual str getCateg() const = 0;        //category of sports equipment
    virtual int getGoodQ() const = 0;        //quantity of equipments not broken or lost
    virtual int getBrokenQ() const = 0;
    virtual int getLostQ() const = 0;
    virtual double getUnitValRM() const = 0;
};  
