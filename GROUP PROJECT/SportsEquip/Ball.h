//Ball.h
//derived from SportsEquip
#pragma once

#include "SportsEquip.h"

class Ball : public SportsEquip
{
private:
    str name;
    str categ;      //category of sports equipment
    int goodQ;      //quantity of ball not lost or broken
    int brokenQ;
    int lostQ;

public:\
    //constructors
    Ball(const str&, const str&, const int&, const int&, const int&);
    Ball();     //default

    ~Ball();    //destructor

    //setters
    void setName(const str&) override;
    void setCateg(const str&) override;  
    void setGoodQ(const int&) override;  
    void setBrokenQ(const int&) override;
    void setLostQ(const int&) override;

    //getters
    str getName() const override;
    str setCateg() const override;
    int setGoodQ() const override;  
    int setBrokenQ() const override;
    int setLostQ() const override;
};