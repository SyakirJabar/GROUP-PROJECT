//SportsStoreProg.h
#pragma once

#include "../SportsEquip/Ball.h"
#include "../SportsEquip/Racket.h"
#include "../SportsEquip/Throwable.h"
#include "../SportsEquip/Stick.h"
#include "../SportsEquip/Helmet.h"
#include <fstream>
#include <vector>
#include <memory>

struct SportsStoreProg
{
private:
    //vector storing (unique) pointers to objects of classes derived 
    //from SportsEquip (base) class
    std::vector<std::unique_ptr<SportsEquip>> eqpmnts;  //sports equipments
    std::vector<std::vector<str>> eqpmntsVal;           //2D vector

public:
    SportsStoreProg();      //constructor
    ~SportsStoreProg();

    void insEquip();        //insert record of sports equipments
    void dispAllEquip();    //display sports equipments
    void searchEquip();     //search equipments
    void printSummary();    //print summary of sports equipments records
};