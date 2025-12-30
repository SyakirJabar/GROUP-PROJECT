#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

// --- PASS BY VALUE ---
void saveToFile(string name, int totalQty, int bQty, int lQty, double totalval) {
    ofstream outputSystem("MainRecord.txt", ios::app);

    if (outputSystem) {
        outputSystem << "Item: " << name
            << " | Total: " << totalQty << " | Broken: " << bQty << " | Lost: " << lQty
            << " | Total Value: RM" << fixed << setprecision(2) << totalval << endl;

        outputSystem.close();
        cout << ">> Record successfully saved to file!" << endl;
    }
    else
        cout << ">> Error: File could not be opened!" << endl;
}

// --- PASS BY REFERENCE ---
// Calculates value of lost/broken items specifically
void calculateValues(int totalQty, int bQty, int lQty, double unitPrice, double& damageval) {
    damageval = (bQty + lQty) * unitPrice;
}

int main() {
    string itemName;
    int total, broken, lost;
    double price, totalDamageValue;

    cout << "===== SPORT STOREROOM MANAGEMENT =====" << endl;
    cout << "(Press Ctrl+Z then Enter at 'Item Name' to stop)" << endl;

    cout << "\nEnter Item Name: ";
    // while(cin >> itemName) handles the infinite loop and Ctrl+Z
    while (cin >> itemName) {

        cout << "Enter Total Quantity: ";
        cin >> total;

        cout << "Enter broken quantity: ";
        cin >> broken;

        cout << "Enter lost quantity: ";
        cin >> lost;

        cout << "Enter estimate value per unit (RM): ";
        cin >> price;

        // Pass by Reference: totalDamageValue is updated inside the function
        calculateValues(total, broken, lost, price, totalDamageValue);
        // Pass by Value: Sends copies of all data to be saved
        saveToFile(itemName, total, broken, lost, totalDamageValue);

        cout << "\n---------------------------------------" << endl;
        cout << "\nEnter Item Name: ";
    }

    cout << "\nProgram terminated. Check 'MainRecord.txt'." << endl;
    return 0;
}