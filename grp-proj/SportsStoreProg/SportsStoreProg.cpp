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
    char usrIn{};
    bool exit{};

    std::cout << "Welcome\n";
    std::cout << "-------\n";

    while (true)
    {
        
        std::cout << "1. Insert Record\n";
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
        case 'q': return;
                  break;
        default : std::cout << "Invalid input. Try again...\n\n";
        }

        // Open file in Write Mode
        std::ofstream outFile("../StoreroomData.txt", std::ios::out);

        if (outFile.is_open()) {
            for (int i = 0; i < eqpmnts.size(); i++)
            {
            // Save raw data separated by spaces
            outFile << eqpmnts[i]->getName() << " "
                << eqpmnts[i]->getCateg() << " "
                << eqpmnts[i]->getGoodQ() << " "
                << eqpmnts[i]->getBrokenQ() << " "
                << eqpmnts[i]->getLostQ() << " "
                << std::fixed << std::setprecision(2) << eqpmnts[i]->getUnitValRM() << std::endl;
            }
            outFile.close();
        }
        else {
            std::cout << ">> Error: Unable to access StoreroomData.txt." << std::endl;
        }
    }
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
    std::cout << "(Press Ctrl+Z then Enter to stop and return to menu)" << std::endl;


    while (true) {
        char equipType{};

        // Prompt user to enter type of sports equipment
        std::cout << "Enter type of equipments\n";
        std::cout << "[B]all\n";
        std::cout << "[R]acket\n";
        std::cout << "[P]rojectile\n";
        std::cout << "X to quit\n";
        std::cin >> equipType;

        if (equipType != 'B' && equipType != 'R' && equipType != 'P' && equipType != 'X')
        {
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (equipType == 'X')   break;

        // Using loop condition that reads itemName from cin to continue looping
        // and returns false when Ctrl+Z is detected
        std::cout << "\nEnter Item Name: ";
        std::cin >> itemName;

        // Collect the rest of the data for this item
        std::cout << "Enter Item Category: ";
        std::cin >> itemCateg;

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
                            (Ball(itemName, itemCateg, brokenQty, lostQty, unitValue));
                    break;

        case 'R':   sportsEquip = std::make_unique<Racket> 
                            (Racket(itemName, itemCateg, brokenQty, lostQty, unitValue));
                    break;

        case 'P':   sportsEquip = std::make_unique<Projectile> 
                            (Projectile(itemName, itemCateg, brokenQty, lostQty, unitValue));
        }

        eqpmnts.push_back(std::move(sportsEquip));

        // // Open file in Append Mode
        // std::ofstream outFile("StoreroomData.txt", std::ios::app);

        // if (outFile.is_open()) {
        //     // Save raw data separated by spaces
        //     outFile << itemName << " "
        //         << itemCateg << " "
        //         << brokenQty << " "
        //         << lostQty << " "
        //         << std::fixed << std::setprecision(2) << unitValue << std::endl;

        //     outFile.close();
        //     std::cout << ">> '" << itemName << "' saved successfully." << std::endl;
        // }
        // else {
        //     std::cout << ">> Error: Unable to access StoreroomData.txt." << std::endl;
        // }
    }
    // Clearing to ensure selection menu works after ctrl+Z
    // std::cin.clear();
    // std::cout << "\n>> Item entry complete. Returning to system..." << std::endl;
}

void SportsStoreProg::dispAllEquip()
{

}

void SportsStoreProg::searchEquip()
{
    str searchItem, itemName;
    int quantity, brokenQty, lostQty;
    double unitValue;
    bool found = false;

    std::cout << "\n--- SEARCH / RETRIEVE MODE ---" << std::endl;
    std::cout << "Enter item name to search: ";
    std::cin >> searchItem;

    std::ifstream inFile("StoreroomData.txt");

    if (!inFile.is_open()) {
        std::cout << ">> Error: Cannot open StoreroomData.txt." << std::endl;
        return;
    }

    // Read data exactly in the same order as saved
    while (inFile >> itemName >> quantity >> brokenQty >> lostQty >> unitValue) {

        if (itemName == searchItem) {
            double totalValue = quantity * unitValue;
            double brokenValue = brokenQty * unitValue;
            double lostValue = lostQty * unitValue;

            std::cout << "\nItem Found!" << std::endl;
            std::cout << "Item Name       : " << itemName << std::endl;
            std::cout << "Total Quantity  : " << quantity << std::endl;
            std::cout << "Broken Quantity : " << brokenQty << std::endl;
            std::cout << "Lost Quantity   : " << lostQty << std::endl;
            std::cout << "Unit Value (RM) : " << std::fixed << std::setprecision(2) << unitValue << std::endl;
            std::cout << "Total Value     : RM" << totalValue << std::endl;
            std::cout << "Broken Value    : RM" << brokenValue << std::endl;
            std::cout << "Lost Value      : RM" << lostValue << std::endl;

            found = true;
            break;
        }
    }

    inFile.close();

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

    for (int i = 0; i < eqpmnts.size(); i++) {
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
