#include <iostream>

void MenuController()
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
        case '1': inputAndSaveData();
                  break;
        case '2': //DisplayAllRecords();
                  break;
        case '3': SearchRetrieve();
                  break;
        case '4': SummaryReport();
                  break;
        case 'q': return;
                  break;
        default : std::cout << "Invalid input. Try again...\n\n";
        }
    }
}