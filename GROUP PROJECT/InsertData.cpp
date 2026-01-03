void inputAndSaveData() {
    string itemName;
    int quantity, brokenQty, lostQty;
    double unitValue;

    cout << "\n--- SPORT STOREROOM: INSERT MODE ---" << endl;
    cout << "(Press Ctrl+Z then Enter to stop and return to menu)" << endl;

    // Using loop condition that reads itemName from cin to continue looping
    // and returns false when Ctrl+Z is detected
    cout << "\nEnter Item Name: ";
    while (cin >> itemName) {

        // Collect the rest of the data for this item
        cout << "Enter Total Quantity: ";
        cin >> quantity;

        cout << "Enter Broken Quantity: ";
        cin >> brokenQty;

        cout << "Enter Lost Quantity: ";
        cin >> lostQty;

        cout << "Enter Estimate Value per Unit (RM): ";
        cin >> unitValue;

        // Open file in Append Mode
        ofstream outFile("StoreroomData.txt", ios::app);

        if (outFile.is_open()) {
            // Save raw data separated by spaces
            outFile << itemName << " "
                << quantity << " "
                << brokenQty << " "
                << lostQty << " "
                << fixed << setprecision(2) << unitValue << endl;

            outFile.close();
            cout << ">> '" << itemName << "' saved successfully." << endl;
        }
        else {
            cout << ">> Error: Unable to access StoreroomData.txt." << endl;
        }

        // Prompt for the next name to keep the loop going
        cout << "\nEnter Item Name: ";
    }
    // Clearing to ensure selection menu works after ctrl+Z
    cin.clear();
    cout << "\n>> Item entry complete. Returning to system..." << endl;
}