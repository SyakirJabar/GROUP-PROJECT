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

    std::ifstream inFile("StoreroomData.txt");

    //read every line in external file
    while (inFile >> type >> name >> categ >> goodQ >> brokenQ >> lostQ >> unitValRM)
    {
        switch (type)
        {
        case 'B':   sportsEquip = std::make_unique<Ball>(name, categ, goodQ, brokenQ, lostQ, unitValRM);
                    break;

        case 'R':   sportsEquip = std::make_unique<Racket>(name, categ, goodQ, brokenQ, lostQ, unitValRM);
                    break;

        case 'T':   sportsEquip = std::make_unique<Throwable>(name, categ, goodQ, brokenQ, lostQ, unitValRM);
                    break;

        case 'S':   sportsEquip = std::make_unique<Stick>(name, categ, goodQ, brokenQ, lostQ, unitValRM);
            break;

        case 'H':   sportsEquip = std::make_unique<Helmet>(name, categ, goodQ, brokenQ, lostQ, unitValRM);
            break;
        }       

        eqpmnts.push_back(std::move(sportsEquip));  //transfer pointer ownership from sportsEquip
    }
    inFile.close();  //close file (good practice)

    char usrIn{};

    bool loop{true};
    while (loop)
    {
        std::cout << "MAIN MENU\n";
        std::cout << "=========\n";
        std::cout << "1. Insert Record\n";
        std::cout << "2. Display All Records\n";
        std::cout << "3. Search Records\n";
        std::cout << "4. Print Report\n";
        std::cout << "Q to exit\n";
        std::cout << "-----------------------\n";
        std::cout << "User input: ";
        std::cin >> usrIn;

        switch (std::tolower(usrIn))
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

    std::ofstream outFile("StoreroomData.txt", std::ios::out);

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

//insert sports equipments into 
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
        std::cout << "\nEnter type of sports equipment\n";
        std::cout << "[B]all - object launched into the air by hitting another object, e.g. soccer ball, volley ball\n";
        std::cout << "[R]acket - item used to hit a ball\n";
        std::cout << "[T]hrowable - item made to be thrown, e.g. javelin spear\n";
        std::cout << "[S]tick - item look like a stick (not meant to be thrown), e.g. bat, hockey stick\n";
        std::cout << "[H]elmet - to be worn on the head\n";
        std::cout << "Q to quit\n";
        std::cout << "------------\n";
        std::cout << "Equipment type: ";
        std::cin >> equipType;

        if (std::tolower(equipType) != 'b' && std::tolower(equipType) != 'r' 
            && std::tolower(equipType) != 't' && std::tolower(equipType) != 's'
            && std::tolower(equipType) != 'h' && std::tolower(equipType) != 'q')
        {
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (std::tolower(equipType) == 'q')   break;

        equipType = std::tolower(equipType);

        // Using loop condition that reads itemName from cin to continue looping
        // and returns false when Ctrl+Z is detected
        std::cout << "\nName (NO spaces): ";
        std::cin >>itemName;

        // Collect the rest of the data for this item
        std::cout << "Category (NO spaces): ";
        std::cin >> itemCateg;

        std::cout << "Good (Not Lost/Broken) Quantity: ";
        std::cin >> goodQty;

        std::cout << "Broken Quantity: ";
        std::cin >> brokenQty;

        std::cout << "Lost Quantity: ";
        std::cin >> lostQty;

        std::cout << "Value per Unit (RM): ";
        std::cin >> unitValue;

        //instantiate SportsEquip derivation depending on equipment type
        switch(equipType)
        {
        case 'b':   sportsEquip = std::make_unique<Ball> 
                            (itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue);
                    break;

        case 'r':   sportsEquip = std::make_unique<Racket> 
                            (itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue);
                    break;

        case 't':   sportsEquip = std::make_unique<Throwable> 
                            (itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue);
                    break;

        case 's':   sportsEquip = std::make_unique<Stick> 
                        (itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue);
                break;

        case 'h':   sportsEquip = std::make_unique<Helmet> 
                        (itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue);
                break;
        }

        //transfer ownership sportsEquip from pointer sportsEquip
        eqpmnts.push_back(std::move(sportsEquip));
    }
}

//display all sports equipments
void SportsStoreProg::dispAllEquip()
{
    if (eqpmnts.empty()) {
        std::cout << "\nNo records to display!" << std::endl;
        return;
    }

    std::cout << "\n--- ALL EQUIPMENT RECORDS ---\n\n";
    
    //header row
    std::cout << std::left
              << std::setw(6)  << "#"
              << std::setw(20) << "Name"
              << std::setw(15) << "Category"
              << std::setw(10) << "Good"
              << std::setw(10) << "Broken"
              << std::setw(10) << "Lost"
              << std::setw(12) << "Unit (RM)" << "\n";
    
    //separator line
    std::cout << std::string(83, '-') << "\n";
    
    //data rows
    for (size_t i = 0; i < eqpmnts.size(); i++)
    {
        std::cout << std::left
                  << std::setw(6)  << i+1
                  << std::setw(20) << eqpmnts[i]->getName()
                  << std::setw(15) << eqpmnts[i]->getCateg()
                  << std::setw(10) << eqpmnts[i]->getGoodQ()
                  << std::setw(10) << eqpmnts[i]->getBrokenQ()
                  << std::setw(10) << eqpmnts[i]->getLostQ()
                  << std::setw(12) << std::fixed << std::setprecision(2) << eqpmnts[i]->getUnitValRM() << "\n";
    }
    
    std::cout << std::string(83, '-') << "\n";
    std::cout << "Total records: " << eqpmnts.size() << "\n";

    std::cout << "\n-----------------------------\n\n";
}

//search a sports equipment by equipment name
void SportsStoreProg::searchEquip()
{
    str itemName;
    
        std::cout << "\n--- SPORTS STOREROOM: SEARCH / RETRIEVE MODE ---\n";

        while (true)
        {
            bool found{false};

            std::cout << "\nEnter item name to search (Q to quit): ";
            std::cin >> itemName;

            if (itemName == "Q" || itemName == "q") break;

            //go through
            for (size_t i = 0; i < eqpmnts.size(); i++)
            {
                if (itemName == eqpmnts[i]->getName()) 
                {
                    found = true;
                    std::cout << "\nItem found!";
                    std::cout << "\n\nName                : " << eqpmnts[i]->getName() << "\n";
                    std::cout << "Category            : " << eqpmnts[i]->getCateg() << "\n";
                    std::cout << "Good Quantity       : " << eqpmnts[i]->getGoodQ() << "\n";
                    std::cout << "Broken Quantity     : " << eqpmnts[i]->getBrokenQ() << "\n";
                    std::cout << "Lost Quantity       : " << eqpmnts[i]->getLostQ() << "\n";
                    std::cout << "Value per unit (RM) : " << eqpmnts[i]->getUnitValRM() << "\n";
                    break;
                }
            }
            if (!found) {
                std::cout << "\nItem not found..." << std::endl;
            }
        }
        std::cout << "\n-----------------------------\n\n";
}


void SportsStoreProg::printSummary()
{
    if (eqpmnts.size() == 0) {
        std::cout << "\nNo records to summarize!" << std::endl;
        return;
    }

    int totalQty{0}, totalGood{0}, totalBroken{0}, totalLost{0};
    double avgValue{0};
    double totalValue{0}, goodValue{0}, brokenValue{0}, lostValue{0};

    for (size_t i = 0; i < eqpmnts.size(); i++) {
        totalQty += eqpmnts[i]->getGoodQ() + eqpmnts[i]->getBrokenQ() + eqpmnts[i]->getLostQ();
        totalGood += eqpmnts[i]->getGoodQ();
        totalBroken += eqpmnts[i]->getBrokenQ();
        totalLost += eqpmnts[i]->getLostQ();

        totalValue += (eqpmnts[i]->getGoodQ() + eqpmnts[i]->getBrokenQ() 
                        + eqpmnts[i]->getLostQ()) * eqpmnts[i]->getUnitValRM();
        goodValue += eqpmnts[i]->getGoodQ() * eqpmnts[i]->getUnitValRM();
        brokenValue += eqpmnts[i]->getBrokenQ() * eqpmnts[i]->getUnitValRM();
        lostValue += eqpmnts[i]->getLostQ() * eqpmnts[i]->getUnitValRM();
    }
    avgValue = totalValue /  totalQty;

    std::cout << "\n--- SPORTS STOREROOM: REPORT ---\n" << std::endl;
    std::cout << "Item Records              : " << eqpmnts.size() << std::endl;

    std::cout << "\nTotal Quantity            : " << totalQty << std::endl;
    std::cout << "Total Good                : " << totalGood << std::endl;
    std::cout << "Total Broken              : " << totalBroken << std::endl;
    std::cout << "Total Lost                : " << totalLost << std::endl;

    std::cout << "\nAverage Equipment Value   : RM" << std::fixed << std::setprecision(2) 
            << avgValue << std::endl;

    std::cout << "\nTotal Value               : RM" << std::fixed << std::setprecision(2) 
                << totalValue << std::endl;
    std::cout << "Total Good Value          : RM" << std::fixed << std::setprecision(2) 
                << goodValue << std::endl;
    std::cout << "Total Broken Value        : RM" << std::fixed << std::setprecision(2) 
                << brokenValue << std::endl;
    std::cout << "Total Lost Value          : RM" << std::fixed << std::setprecision(2) 
                << lostValue << std::endl;
    std::cout << "\n-----------------------------\n\n";
}
