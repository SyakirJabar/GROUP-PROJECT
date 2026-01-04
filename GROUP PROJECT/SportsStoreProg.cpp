//SportsStoreProg.cpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

typedef std::string str;

#include "SportsStoreProg.h"

//constructor
SportsStoreProg::SportsStoreProg()
{}

//destructor
SportsStoreProg::~SportsStoreProg()
{}

void insEquip() {
    str itemName;
    int quantity, brokenQty, lostQty;
    double unitValue;

    std::cout << "\n--- SPORT STOREROOM: INSERT MODE ---" << std::endl;
    std::cout << "(Press Ctrl+Z then Enter to stop and return to menu)" << std::endl;

    // Using loop condition that reads itemName from cin to continue looping
    // and returns false when Ctrl+Z is detected
    std::cout << "\nEnter Item Name: ";
    while (std::cin >> itemName) {

        // Collect the rest of the data for this item
        std::cout << "Enter Total Quantity: ";
        std::cin >> quantity;

        std::cout << "Enter Broken Quantity: ";
        std::cin >> brokenQty;

        std::cout << "Enter Lost Quantity: ";
        std::cin >> lostQty;

        std::cout << "Enter Estimate Value per Unit (RM): ";
        std::cin >> unitValue;

        // Open file in Append Mode
        std::ofstream outFile("StoreroomData.txt", std::ios::app);

        if (outFile.is_open()) {
            // Save raw data separated by spaces
            outFile << itemName << " "
                << quantity << " "
                << brokenQty << " "
                << lostQty << " "
                << std::fixed << std::setprecision(2) << unitValue << std::endl;

            outFile.close();
            std::cout << ">> '" << itemName << "' saved successfully." << std::endl;
        }
        else {
            std::cout << ">> Error: Unable to access StoreroomData.txt." << std::endl;
        }

        // Prompt for the next name to keep the loop going
        std::cout << "\nEnter Item Name: ";
    }
    // Clearing to ensure selection menu works after ctrl+Z
    std::cin.clear();
    std::cout << "\n>> Item entry complete. Returning to system..." << std::endl;
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