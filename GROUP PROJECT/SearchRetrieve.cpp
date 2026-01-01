// ================= SEARCH / RETRIEVE =================
void searchFromFile() {
    string searchItem, itemName;
    int quantity, brokenQty, lostQty;
    double unitValue;
    bool found = false;

    cout << "\n--- SEARCH / RETRIEVE MODE ---" << endl;
    cout << "Enter item name to search: ";
    cin >> searchItem;

    ifstream inFile("StoreroomData.txt");

    if (!inFile.is_open()) {
        cout << ">> Error: Cannot open StoreroomData.txt." << endl;
        return;
    }

    // Read data exactly in the same order as saved
    while (inFile >> itemName >> quantity >> brokenQty >> lostQty >> unitValue) {

        if (itemName == searchItem) {
            double totalValue = quantity * unitValue;
            double brokenValue = brokenQty * unitValue;
            double lostValue = lostQty * unitValue;

            cout << "\nItem Found!" << endl;
            cout << "Item Name       : " << itemName << endl;
            cout << "Total Quantity  : " << quantity << endl;
            cout << "Broken Quantity : " << brokenQty << endl;
            cout << "Lost Quantity   : " << lostQty << endl;
            cout << "Unit Value (RM) : " << fixed << setprecision(2) << unitValue << endl;
            cout << "Total Value     : RM" << totalValue << endl;
            cout << "Broken Value    : RM" << brokenValue << endl;
            cout << "Lost Value      : RM" << lostValue << endl;

            found = true;
            break;
        }
    }

    inFile.close();

    if (!found) {
        cout << "\n>> Item not found." << endl;
    }
}

