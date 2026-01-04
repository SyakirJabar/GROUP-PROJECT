//SportsStoreProg.h
#pragma once

struct SportsStoreProg
{
private:
    std::vector<std::unique_ptr<Equipment>> equipments;  //sports equipments stored

public:
    SportsStoreProg();  //constructor


    void insEquip();
    void displayAllEquip();
    void searchEquip();
    void printSummary();
    void menu();
};