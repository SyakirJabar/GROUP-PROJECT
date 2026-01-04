//SportsStoreProg.h
#pragma once

struct SportsStoreProg
{
private:
    std::vector<std::unique_ptr<Equipment>> eqpmnts;  //sports equipments

public:
    SportsStoreProg();      //constructor
    ~SportsStoreProg();

    void insEquip();        //insert record of sports equipments
    void dispAllEquip();    //display sports equipments
    void searchEquip();     //search equipments
    void printSummary();    //print summary of sports equipments records
};