//SportsStoreProg.h

class SportsStoreProg
{
private:
    std::vector<std::unique_ptr<Equipment>> equipments;  //sports equipments stored

public:
    void insEquip();
    void displayAllEquip();
    void searchEquip();
    void printSummary();
    void menu();
};