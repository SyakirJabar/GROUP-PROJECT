//Throwable.cpp
//derived from SportsEquip

#include "Throwable.h"
#include <iostream>

/*  CONSTRUCTORS & DESTRUCTORS  */
Throwable::Throwable
    (const str& n, const str& c, const int& gq, const int& bq, const int& lq, const double& uv)
    : name{n}, categ{c}, goodQ{gq}, brokenQ{bq}, lostQ{lq}, unitValRM{uv}
{}

//default constructor
Throwable::Throwable()
{
    std::cerr << "Object Racket must NOT be empty!";
    exit(1);
}

//destructor
Throwable::~Throwable()
{}
/*******************************/

/*  GETTERS  */
char Throwable::getType() const
{
    return type;
}

str Throwable::getName() const
{
    return name;
}

str Throwable::getCateg() const
{
    return categ;
}

int Throwable::getGoodQ() const
{
    return goodQ;
}

int Throwable::getBrokenQ() const
{
    return brokenQ;
}

int Throwable::getLostQ() const
{
    return lostQ;
}

double Throwable::getUnitValRM() const
{
    return unitValRM;
}
/*******************************/