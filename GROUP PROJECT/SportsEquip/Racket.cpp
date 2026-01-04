//Racket.cpp
//derived from SportsEquip

#include "Racket.h"
#include <iostream>

/*  CONSTRUCTORS & DESTRUCTORS  */
Racket::Racket
    (const str& n, const str& c, const int& gq, const int& bq, const int& lq)
    : name{n}, categ{c}, goodQ{gq}, brokenQ{bq}, lostQ{lq}
{}

//default constructor
Racket::Racket()
{
    std::cerr << "Object Racket must NOT be empty!";
    exit(1);
}

//destructor
Racket::~Racket()
{}
/*******************************/

/*  GETTERS  */
str Racket::getName() const
{
    return name;
}

str Racket::getCateg() const
{
    return categ;
}

int Racket::getGoodQ() const
{
    return goodQ;
}

int Racket::getBrokenQ() const
{
    return brokenQ;
}

int Racket::getLostQ() const
{
    return lostQ;
}
/*******************************/