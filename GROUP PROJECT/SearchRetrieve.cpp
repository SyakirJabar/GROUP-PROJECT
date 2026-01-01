// ================= SEARCH / RETRIEVE =================
void searchRecord(Equipment items[], int count) {
    if (count == 0) {
        cout << "\nNo records to search!" << endl;
        return;
    }

    char searchName[50];
    bool found = false;

    cout << "\nEnter equipment name to search: ";
    cin.getline(searchName, 50);  // pastikan buffer clear sebelum panggil

    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, searchName) == 0) {
            double totalValue = items[i].quantity * items[i].unitPrice;
            double brokenValue = items[i].broken * items[i].unitPrice;
            double lostValue = items[i].lost * items[i].unitPrice;

            cout << "\nRecord Found!" << endl;
            cout << "Equipment Name : " << items[i].name << endl;
            cout << "Total Quantity : " << items[i].quantity << endl;
            cout << "Broken Quantity: " << items[i].broken << endl;
            cout << "Lost Quantity  : " << items[i].lost << endl;
            cout << "Unit Price (RM): " << fixed << setprecision(2) << items[i].unitPrice << endl;
            cout << "Total Value    : RM" << fixed << setprecision(2) << totalValue << endl;
            cout << "Broken Value   : RM" << fixed << setprecision(2) << brokenValue << endl;
            cout << "Lost Value     : RM" << fixed << setprecision(2) << lostValue << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nItem not found!" << endl;
    }
}

