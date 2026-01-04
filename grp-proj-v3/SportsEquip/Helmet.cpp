//Helmet.cpp
//derived from SportsEquip

#include "Helmet.h"
#include <iostream>

/*  CONSTRUCTORS & DESTRUCTORS  */
Helmet::Helmet
    (const str& n, const str& c, const int& gq, const int& bq, const int& lq, const double& uv)
    : name{n}, categ{c}, goodQ{gq}, brokenQ{bq}, lostQ{lq}, unitValRM{uv}           //member init list
{}

//default constructor
Helmet::Helmet()
{
    std::cerr << "Object Helmet must NOT be empty!";
    exit(1);
}

//destructor
Helmet::~Helmet()
{}
/*******************************/

/*  GETTERS  */
char Helmet::getType() const
{
    return type;
}

str Helmet::getName() const
{
    return name;
}

str Helmet::getCateg() const
{
    return categ;
}

int Helmet::getGoodQ() const
{
    return goodQ;
}

int Helmet::getBrokenQ() const
{
    return brokenQ;
}

int Helmet::getLostQ() const
{
    return lostQ;
}

double Helmet::getUnitValRM() const
{
    return unitValRM;
}
/*******************************/