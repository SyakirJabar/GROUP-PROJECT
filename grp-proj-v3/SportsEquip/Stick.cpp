//Stick.cpp
//derived from SportsEquip

#include "Stick.h"
#include <iostream>

/*  CONSTRUCTORS & DESTRUCTORS  */
Stick::Stick
    (const str& n, const str& c, const int& gq, const int& bq, const int& lq, const double& uv)
    : name{n}, categ{c}, goodQ{gq}, brokenQ{bq}, lostQ{lq}, unitValRM{uv}
{}

//default constructor
Stick::Stick()
{
    std::cerr << "Object Stick must NOT be empty!";
    exit(1);
}

//destructor
Stick::~Stick()
{}
/*******************************/

/*  GETTERS  */
char Stick::getType() const
{
    return type;
}

str Stick::getName() const
{
    return name;
}

str Stick::getCateg() const
{
    return categ;
}

int Stick::getGoodQ() const
{
    return goodQ;
}

int Stick::getBrokenQ() const
{
    return brokenQ;
}

int Stick::getLostQ() const
{
    return lostQ;
}

double Stick::getUnitValRM() const
{
    return unitValRM;
}
/*******************************/