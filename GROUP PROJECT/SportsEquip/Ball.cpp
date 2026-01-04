//Ball.cpp
//derived from SportsEquip

#include "Ball.h"
#include <iostream>

/*  CONSTRUCTORS & DESTRUCTORS  */
Ball::Ball
    (const str& n, const str& c, const int& gq, const int& bq, const int& lq)
    : name{n}, categ{c}, goodQ{gq}, brokenQ{bq}, lostQ{lq}
{}

//default constructor
Ball::Ball()
{
    std::cerr << "Object Ball must NOT be empty!";
    exit(1);
}

//destructor
Ball::~Ball()
{}
/*******************************/

/*  GETTERS  */
str Ball::getName() const
{
    return name;
}

str Ball::getCateg() const
{
    return categ;
}
/*******************************/