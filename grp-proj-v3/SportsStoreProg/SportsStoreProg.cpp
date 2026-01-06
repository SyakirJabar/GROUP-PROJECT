//SportsStoreProg.cpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>

typedef std::string str;

#include "SportsStoreProg.h"

//constructor
//includes menu controller 
//[B152510010 Ariff Sanusi]
SportsStoreProg::SportsStoreProg()
{
    //open external file for writing (append mode)
    std::ofstream tStampRecord("SysAccessRecords.txt", std::ios::app);

    if (tStampRecord.is_open())
    {
        // Get the timestamp for the current date and time
        time_t timestamp;
        time(&timestamp);

        // Display the date and time represented by the timestamp
        tStampRecord << ctime(&timestamp);

        tStampRecord.close();       //close file
    }

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
        //assign pointer to Ball obj
        case 'B':   sportsEquip = std::make_unique<Ball>(name, categ, goodQ, brokenQ, lostQ, unitValRM);
                    break;

        //assign pointer to Racket obj
        case 'R':   sportsEquip = std::make_unique<Racket>(name, categ, goodQ, brokenQ, lostQ, unitValRM);
                    break;

        //assign pointer to Throwable obj
        case 'T':   sportsEquip = std::make_unique<Throwable>(name, categ, goodQ, brokenQ, lostQ, unitValRM);
                    break;

        //assign pointer to Stick obj
        case 'S':   sportsEquip = std::make_unique<Stick>(name, categ, goodQ, brokenQ, lostQ, unitValRM);
            break;

        //assign pointer to Helmet obj
        case 'H':   sportsEquip = std::make_unique<Helmet>(name, categ, goodQ, brokenQ, lostQ, unitValRM);
            break;
        }       

        eqpmnts.push_back(std::move(sportsEquip));  //transfer ownership from pointer sportsEquip to an element of eqpmnts
    }
    inFile.close();     //close file (good practice)

    char usrIn{};
    bool loop{true};
    
    //loop main menu until 'q' - exit
    while (loop)
    {
        char mainMenu[150]{""};

        strcat(mainMenu, "MAIN MENU\n");
        strcat(mainMenu, "=========\n");
        strcat(mainMenu, "1. Insert Record\n");
        strcat(mainMenu, "2. Display All Records\n");
        strcat(mainMenu, "3. Search Records\n");
        strcat(mainMenu, "4. Print Report\n");
        strcat(mainMenu, "Q to exit\n");
        strcat(mainMenu, "-----------------------\n");
        strcat(mainMenu, "User input: ");
        std::cout << mainMenu;
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

    //open .txt file for writing (writing mode)
    std::ofstream outFile("StoreroomData.txt", std::ios::out);

    //write every equipment in vector to StoreroomData.txt
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

//Add / Insert Record
//insert sports equipments into eqpmnts vector
//[B152510105 Mohamad Adiputra Aiman bin Awang]
void SportsStoreProg::insEquip() {
    str itemName, itemCateg;
    int goodQty, brokenQty, lostQty;
    double unitValue;
    //unique pointer to an object that is derived from SportsEquip (base) class
    std::unique_ptr<SportsEquip> sportsEquip{nullptr};   

    std::cout << "\n--- SPORT STOREROOM: INSERT MODE ---" << std::endl;

    while (true) {
        char equipType{};

        char invalidIn[30]{""};

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

        //input validation
        if (std::tolower(equipType) != 'b' && std::tolower(equipType) != 'r' 
            && std::tolower(equipType) != 't' && std::tolower(equipType) != 's'
            && std::tolower(equipType) != 'h' && std::tolower(equipType) != 'q')
        {
            strcpy(invalidIn, "\nInvalid input. Try again.\n");
            std::cout << invalidIn;
            continue;
        }

        //go back to main menu
        if (std::tolower(equipType) == 'q')   break;

        equipType = std::tolower(equipType);    //ensure equipType is always lowercase letter

        //prompt user to enter a record of sports equipment
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

        //instantiate a SportsEquip derived class depending on equipment type
        switch(equipType)
        {
        //assign pointer to Ball obj
        case 'b':   sportsEquip = std::make_unique<Ball> 
                            (itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue);
                    break;

        //assign pointer to Racket obj
        case 'r':   sportsEquip = std::make_unique<Racket> 
                            (itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue);
                    break;

        //assign pointer to Throwable obj
        case 't':   sportsEquip = std::make_unique<Throwable> 
                            (itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue);
                    break;

        //assign pointer to Stick obj
        case 's':   sportsEquip = std::make_unique<Stick> 
                        (itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue);
                break;

        //assign pointer to Helmet obj
        case 'h':   sportsEquip = std::make_unique<Helmet> 
                        (itemName, itemCateg, goodQty, brokenQty, lostQty, unitValue);
                break;
        }

        //transfer ownership from pointer sportsEquip to an element in eqpmnts
        eqpmnts.push_back(std::move(sportsEquip));
    }
}

// Display All Records
//display all sports equipment records
//[B152510087 Muhammad Syakir bin Abd Jabar Tambi]
void SportsStoreProg::dispAllEquip()
{
    //if vector is empty, let user know
    if (eqpmnts.empty()) {
        std::cout << "\nNo records to display!" << std::endl;
        return;
    }

    //display all equipment records in table format
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

//Search / Retrieve
//search a sports equipment by equipment name
//[B152510069 Muhammad Haziq bin Md Halid]
void SportsStoreProg::searchEquip()
{
    str itemName;
    
    std::cout << "\n--- SPORTS STOREROOM: SEARCH / RETRIEVE MODE ---\n";

    char itemFound[30]{""};
    char itemNotFound[30]{""};

    while (true)
    {
        bool found{false};

        //prompt user to enter equipment name 
        std::cout << "\nEnter item name to search (Q to quit): ";
        std::cin >> itemName;

        if (itemName == "Q" || itemName == "q") break;

        //go through array to find equipment record
        for (size_t i = 0; i < eqpmnts.size(); i++)
        {
            //let user know if equipment found, then print equipment record
            if (strcmp(itemName.c_str(), eqpmnts[i]->getName().c_str()) == 0)
            {
                found = true;
                strcpy(itemFound, "\nItem found!");
                std::cout << itemFound;
                std::cout << "\n\nName                : " << eqpmnts[i]->getName() << "\n";
                std::cout << "Category            : " << eqpmnts[i]->getCateg() << "\n";
                std::cout << "Good Quantity       : " << eqpmnts[i]->getGoodQ() << "\n";
                std::cout << "Broken Quantity     : " << eqpmnts[i]->getBrokenQ() << "\n";
                std::cout << "Lost Quantity       : " << eqpmnts[i]->getLostQ() << "\n";
                std::cout << "Value per unit (RM) : " << eqpmnts[i]->getUnitValRM() << "\n";
                break;
            }
        }
        //let user know if equipment record doesn't exist
        if (!found) {
            strcpy(itemNotFound, "\nItem not found...\n");
            std::cout << itemNotFound;
        }
    }
    std::cout << "\n-----------------------------\n\n";
}

//Summary / Report
//calculate totals, averages, highest/lowest, and show overall summary
//[B152510111 Muhammad Nabil Mohd Tam]
void SportsStoreProg::printSummary()
{
    eqpmntsVal.clear();     //clear 2D vector first

    //let user know if no records
    if (eqpmnts.size() == 0) {
        std::cout << "\nNo records to summarize!" << std::endl;
        return;
    }

    int totalQty{0}, totalGood{0}, totalBroken{0}, totalLost{0};
    double avgValue{0}, avgGoodVal{0}, avgBrokenVal{0}, avgLostVal{0};
    double totalValue{0}, goodValue{0}, brokenValue{0}, lostValue{0};

    //calculate total and average equipment quantity and value
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

        eqpmntsVal.push_back(
                                {eqpmnts[i]->getName(),
                                    std::to_string((eqpmnts[i]->getGoodQ() + eqpmnts[i]->getBrokenQ() 
                                                + eqpmnts[i]->getLostQ()) 
                                                * eqpmnts[i]->getUnitValRM()),
                                    std::to_string(eqpmnts[i]->getGoodQ() * eqpmnts[i]->getUnitValRM()),
                                    std::to_string(eqpmnts[i]->getBrokenQ() 
                                                    * eqpmnts[i]->getUnitValRM()), 
                                    std::to_string(eqpmnts[i]->getLostQ() * eqpmnts[i]->getUnitValRM())}
                            );
    }
    avgValue = (totalQty > 0)        ? totalValue /  totalQty : 0.0;
    avgGoodVal = (totalGood > 0)     ? goodValue / totalGood : 0.0;
    avgBrokenVal = (totalBroken > 0) ? brokenValue / totalBroken : 0.0;
    avgLostVal = (totalLost > 0)     ? lostValue / totalLost : 0.0;

    //find equipment with highest total, good, broken, and lost values
    str hiTotalVal{eqpmntsVal[0][0]};
    double maxTotal = std::stod(eqpmntsVal[0][1]);
    for (size_t i = 1; i < eqpmntsVal.size(); i++) {
        double val = std::stod(eqpmntsVal[i][1]);
        if (val > maxTotal) {
            maxTotal = val;
            hiTotalVal = eqpmntsVal[i][0];
        }
    }

    str hiGoodVal{eqpmntsVal[0][0]};
    double maxGood = std::stod(eqpmntsVal[0][2]);
    for (size_t i = 1; i < eqpmntsVal.size(); i++) {
        double val = std::stod(eqpmntsVal[i][2]);
        if (val > maxGood) {
            maxGood = val;
            hiGoodVal = eqpmntsVal[i][0];
        }
    }

    str hiBrokenVal{eqpmntsVal[0][0]};
    double maxBroken = std::stod(eqpmntsVal[0][3]);
    for (size_t i = 1; i < eqpmntsVal.size(); i++) {
        double val = std::stod(eqpmntsVal[i][3]);
        if (val > maxBroken) {
            maxBroken = val;
            hiBrokenVal = eqpmntsVal[i][0];
        }
    }

    str hiLostVal{eqpmntsVal[0][0]};
    double maxLost = std::stod(eqpmntsVal[0][4]);
    for (size_t i = 1; i < eqpmntsVal.size(); i++) {
        double val = std::stod(eqpmntsVal[i][4]);
        if (val > maxLost) {
            maxLost = val;
            hiLostVal = eqpmntsVal[i][0];
        }
    }

    //print report
    std::cout << "\n--- SPORTS STOREROOM: REPORT ---\n" << std::endl;
    std::cout << "Sports Equipment Records       : " << eqpmnts.size() << std::endl;

    std::cout << "\nTotal Equipments               : " << totalQty << std::endl;
    std::cout << "Total Good Equipments          : " << totalGood << std::endl;
    std::cout << "Total Broken Equipments        : " << totalBroken << std::endl;
    std::cout << "Total Lost Equipments          : " << totalLost << std::endl;

    std::cout << "\nTotal Equipment Value          : RM" << std::fixed << std::setprecision(2) 
                << totalValue << std::endl;
    std::cout << "Total Good Equipment Value     : RM" << std::fixed << std::setprecision(2) 
                << goodValue << std::endl;
    std::cout << "Total Broken Equipment Value   : RM" << std::fixed << std::setprecision(2) 
                << brokenValue << std::endl;
    std::cout << "Total Lost Equipment Value     : RM" << std::fixed << std::setprecision(2) 
                << lostValue << std::endl;

    std::cout << "\nEquipments with the...\n";
    std::cout << "Highest Total Value            : " << hiTotalVal << " (RM" << std::fixed << std::setprecision(2) << maxTotal << ")" << std::endl;
    std::cout << "Highest Good Value             : " << hiGoodVal << " (RM" << std::fixed << std::setprecision(2) << maxGood << ")" << std::endl;
    std::cout << "Highest Broken Value           : " << hiBrokenVal << " (RM" << std::fixed << std::setprecision(2) << maxBroken << ")" << std::endl;
    std::cout << "Highest Lost Value             : " << hiLostVal << " (RM" << std::fixed << std::setprecision(2) << maxLost << ")" << std::endl;

    std::cout << "\nAverage Equipment Value        : RM" << std::fixed << std::setprecision(2) 
            << avgValue << std::endl;
    std::cout << "Average Good Equipment Value   : RM" << std::fixed << std::setprecision(2) 
            << avgGoodVal << std::endl;
    std::cout << "Average Broken Equipment Value : RM" << std::fixed << std::setprecision(2) 
            << avgBrokenVal << std::endl;
    std::cout << "Average Lost Equipment Value   : RM" << std::fixed << std::setprecision(2) 
            << avgLostVal << std::endl;

    std::cout << "\n-----------------------------\n\n";
}
