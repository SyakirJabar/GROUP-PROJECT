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
    virtual str getName() const = 0;
    virtual str setCateg() const = 0;        //category of sports equipment
    virtual int setGoodQ() const = 0;        //quantity of equipments not broken or lost
    virtual int setBrokenQ() const = 0;
    virtual int setLostQ() const = 0;
};  
