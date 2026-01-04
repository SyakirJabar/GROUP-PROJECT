//Projectile.cpp
//derived from SportsEquip

#include "Projectile.h"
#include <iostream>

/*  CONSTRUCTORS & DESTRUCTORS  */
Projectile::Projectile
    (const str& n, const str& c, const int& gq, const int& bq, const int& lq)
    : name{n}, categ{c}, goodQ{gq}, brokenQ{bq}, lostQ{lq}
{}

//default constructor
Projectile::Projectile()
{
    std::cerr << "Object Racket must NOT be empty!";
    exit(1);
}

//destructor
Projectile::~Projectile()
{}
/*******************************/

/*  GETTERS  */
str Projectile::getName() const
{
    return name;
}

str Projectile::getCateg() const
{
    return categ;
}

int Projectile::getGoodQ() const
{
    return goodQ;
}

int Projectile::getBrokenQ() const
{
    return brokenQ;
}

int Projectile::getLostQ() const
{
    return lostQ;
}
/*******************************/