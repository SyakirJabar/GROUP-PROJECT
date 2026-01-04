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
    }
}

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

void SportsStoreProg::printSummary()
{
    if (count == 0) {
        std::cout << "\nNo records to summarize!" << std::endl;
        return;
    }

    int totalQty = 0, totalBroken = 0, totalLost = 0;
    double totalValue = 0, brokenValue = 0, lostValue = 0;

    for (int i = 0; i < count; i++) {
        totalQty += items[i].quantity;
        totalBroken += items[i].broken;
        totalLost += items[i].lost;
        totalValue += items[i].quantity * items[i].unitPrice;
        brokenValue += items[i].broken * items[i].unitPrice;
        lostValue += items[i].lost * items[i].unitPrice;
    }

    std::cout << "\n===== SUMMARY / REPORT =====" << std::endl;
    std::cout << "Total Item Records: " << count << std::endl;
    std::cout << "Total Quantity: " << totalQty << std::endl;
    std::cout << "Total Broken: " << totalBroken << std::endl;
    std::cout << "Total Lost: " << totalLost << std::endl;
    std::cout << "Total Value: RM" << std::fixed << std::setprecision(2) << totalValue << std::endl;
    std::cout << "Total Broken Value: RM" << std::fixed << std::setprecision(2) << brokenValue << std::endl;
    std::cout << "Total Lost Value: RM" << std::fixed << std::setprecision(2) << lostValue << std::endl;
}
