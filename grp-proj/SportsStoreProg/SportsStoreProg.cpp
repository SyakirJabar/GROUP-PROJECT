//SportsStoreProg.cpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

typedef std::string str;

#include "SportsStoreProg.h"

//constructor
SportsStoreProg::SportsStoreProg()
{
    char type;
    str name, categ;
    int goodQ, brokenQ, lostQ;
    double unitValRM;
    std::unique_ptr<SportsEquip> sportsEquip;

    std::ifstream inFile("../StoreroomData.txt");

    while (inFile >> type >> name >> categ >> goodQ >> brokenQ >> lostQ >> unitValRM)
    {
        switch (type)
        {
        case 'B':   sportsEquip = std::make_unique<Ball>(Ball(name, categ, goodQ, brokenQ, lostQ, unitValRM));
                    break;

        case 'R':   sportsEquip = std::make_unique<Racket>(Racket(name, categ, goodQ, brokenQ, lostQ, unitValRM));
                    break;

        case 'T':   sportsEquip = std::make_unique<Throwable>(Throwable(name, categ, goodQ, brokenQ, lostQ, unitValRM));
                    break;
        }

        eqpmnts.push_back(std::move(sportsEquip));
    }
    inFile.close();

    //test only
    // for (const auto& equip : eqpmnts)
    // {
    //     std::cout << equip->getType() << " | "
    //             << equip->getName() << " | "
    //             << equip->getCateg() << " | "
    //             << equip->getGoodQ() << " | "
    //             << equip->getBrokenQ() << " | "
    //             << equip->getLostQ() << " | "
    //             << std::fixed << std::setprecision(2) << equip->getUnitValRM() << "\n";
    // }

    char usrIn{};

    bool loop{true};
    while (loop)
    {
        std::cout << "MAIN MENU\n";
        std::cout << "=========\n";
        std::cout << "\n1. Insert Record\n";
        std::cout << "2. Display All Records\n";
        std::cout << "3. Search Records\n";
        std::cout << "4. Print Report\n";
        std::cout << "q to exit\n";
        std::cout << "-----------------------\n";
        std::cout << "User input: ";
        
        std::cin >> usrIn;

        switch (usrIn)
        {
        case '1': insEquip();
                  break;
        case '2': dispAllEquip();
                  break;
        case '3': searchEquip();
                  break;
        case '4': printSummary();
                  break;
        case 'q': loop = false;
                  break;
        default : std::cout << "Invalid input. Try again...\n\n";
        }
    }

    std::ofstream outFile("../StoreroomData.txt", std::ios::out);

    if (outFile.is_open()) {
        for (size_t i = 0; i < eqpmnts.size(); i++)
        {
        // Save raw data separated by spaces
        outFile << eqpmnts[i]->getType() << " "
                << eqpmnts[i]->getName() << " "
                << eqpmnts[i]->getCateg() << " "
                << eqpmnts[i]->getGoodQ() << " "
                << eqpmnts[i]->getBrokenQ() << " "
                << eqpmnts[i]->getLostQ() << " "
                << std::fixed << std::setprecision(2) 
                << eqpmnts[i]->getUnitValRM() << std::endl;
        }
    }
    else 
    {
        std::cerr << "Error: Unable to access StoreroomData.txt.";
        std::exit(1);
    } 
    outFile.close();
}

//destructor
SportsStoreProg::~SportsStoreProg()
{}

void SportsStoreProg::insEquip() {
    str itemName, itemCateg;
    int goodQty, brokenQty, lostQty;
    double unitValue;
    //unique pointer to an object that is derived from SportsEquip (base) class
    std::unique_ptr<SportsEquip> sportsEquip{nullptr};   

    std::cout << "\n--- SPORT STOREROOM: INSERT MODE ---" << std::endl;

    while (true) {
        char equipType{};

        // Prompt user to enter type of sports equipment
        std::cout << "\nEnter type of equipments\n";
        std::cout << "[B]all\n";
        std::cout << "[R]acket\n";
        std::cout << "[T]hrowable\n";
        std::cout << "X to quit\n";
        std::cin >> equipType;

        if (equipType != 'B' && equipType != 'R' && equipType != 'T' && equipType != 'X')
        {
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (equipType == 'X')   break;

        // Using loop condition that reads itemName from cin to continue looping
        // and returns false when Ctrl+Z is detected
        std::cout << "\nEnter Item Name: ";
        std::cin.ignore();  // Clear leftover newline first
        std::getline(std::cin, itemName);

        // Collect the rest of the data for this item
        std::cout << "Enter Item Category: ";
        std::getline(std::cin, itemCateg);

        std::cout << "Enter Good Quantity: ";
        std::cin >> goodQty;

        std::cout << "Enter Broken Quantity: ";
        std::cin >> brokenQty;

        std::cout << "Enter Lost Quantity: ";
        std::cin >> lostQty;

        std::cout << "Enter Estimate Value per Unit (RM): ";
        std::cin >> unitValue;

        switch(equipType)
        {
        case 'B':   sportsEquip = std::make_unique<Ball> 
                            (Ball(itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue));
                    break;

        case 'R':   sportsEquip = std::make_unique<Racket> 
                            (Racket(itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue));
                    break;

        case 'T':   sportsEquip = std::make_unique<Throwable> 
                            (Throwable(itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue));
                    break;
        }

        eqpmnts.push_back(std::move(sportsEquip));
    }
}

void SportsStoreProg::dispAllEquip()
{
    if (eqpmnts.empty()) {
        std::cout << "\nNo records to display!" << std::endl;
        return;
    }

    std::cout << "\n--- ALL EQUIPMENT RECORDS ---\n\n";
    
    // Header row
    std::cout << std::left
              << std::setw(6)  << "Type"
              << std::setw(20) << "Name"
              << std::setw(15) << "Category"
              << std::setw(10) << "Good"
              << std::setw(10) << "Broken"
              << std::setw(10) << "Lost"
              << std::setw(12) << "Unit (RM)" << "\n";
    
    // Separator line
    std::cout << std::string(83, '-') << "\n";
    
    // Data rows
    for (size_t i = 0; i < eqpmnts.size(); i++)
    {
        std::cout << std::left
                  << std::setw(6)  << eqpmnts[i]->getType()
                  << std::setw(20) << eqpmnts[i]->getName()
                  << std::setw(15) << eqpmnts[i]->getCateg()
                  << std::setw(10) << eqpmnts[i]->getGoodQ()
                  << std::setw(10) << eqpmnts[i]->getBrokenQ()
                  << std::setw(10) << eqpmnts[i]->getLostQ()
                  << std::setw(12) << std::fixed << std::setprecision(2) << eqpmnts[i]->getUnitValRM() << "\n";
    }
    
    std::cout << std::string(83, '-') << "\n";
    std::cout << "Total records: " << eqpmnts.size() << "\n";
}

void SportsStoreProg::searchEquip()
{
    str searchItem, itemName;
    bool found{false};

    std::cout << "\n--- SEARCH / RETRIEVE MODE ---" << std::endl;
    std::cout << "Enter item name to search: ";
    std::cin.ignore();
    std::getline(std::cin, itemName);

    
    for (size_t i = 0; i < eqpmnts.size(); i++)
    {
        if (itemName == eqpmnts[i]->getName()) 
        {
            found = true;
            std::cout << ">> Item found!";
            std::cout << "\nName: " << eqpmnts[i]->getName() << "\n";
            std::cout << "Category: " << eqpmnts[i]->getCateg() << "\n";
            std::cout << "Good Quantity: " << eqpmnts[i]->getGoodQ() << "\n";
            std::cout << "Broken Quantity: " << eqpmnts[i]->getBrokenQ() << "\n";
            std::cout << "Lost Quantity: " << eqpmnts[i]->getLostQ() << "\n";
            std::cout << "Value per unit (RM): " << eqpmnts[i]->getUnitValRM() << "\n";
            break;
        }
    }

    if (!found) {
        std::cout << "\n>> Item not found." << std::endl;
    }
}

void SportsStoreProg::printSummary()
{
    if (eqpmnts.size() == 0) {
        std::cout << "\nNo records to summarize!" << std::endl;
        return;
    }

    int totalQty = 0, totalBroken = 0, totalLost = 0;
    double totalValue = 0, brokenValue = 0, lostValue = 0;

    for (size_t i = 0; i < eqpmnts.size(); i++) {
        totalQty += eqpmnts[i]->getGoodQ() + eqpmnts[i]->getBrokenQ() + eqpmnts[i]->getLostQ();
        totalBroken += eqpmnts[i]->getBrokenQ();
        totalLost += eqpmnts[i]->getLostQ();
        totalValue += (eqpmnts[i]->getGoodQ() + eqpmnts[i]->getBrokenQ() + eqpmnts[i]->getLostQ()) * eqpmnts[i]->getUnitValRM();
        brokenValue += eqpmnts[i]->getBrokenQ() * eqpmnts[i]->getUnitValRM();
        lostValue += eqpmnts[i]->getLostQ() * eqpmnts[i]->getUnitValRM();
    }

    std::cout << "\n===== SUMMARY / REPORT =====" << std::endl;
    std::cout << "Total Item Records: " << eqpmnts.size() << std::endl;
    std::cout << "Total Quantity: " << totalQty << std::endl;
    std::cout << "Total Broken: " << totalBroken << std::endl;
    std::cout << "Total Lost: " << totalLost << std::endl;
    std::cout << "Total Value: RM" << std::fixed << std::setprecision(2) << totalValue << std::endl;
    std::cout << "Total Broken Value: RM" << std::fixed << std::setprecision(2) << brokenValue << std::endl;
    std::cout << "Total Lost Value: RM" << std::fixed << std::setprecision(2) << lostValue << std::endl;
}
