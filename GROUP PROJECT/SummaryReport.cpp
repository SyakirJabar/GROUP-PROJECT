// ================= SUMMARY FUNCTION =================
void summaryReport(Equipment items[], int count) {
    if (count == 0) {
        cout << "\nNo records to summarize!" << endl;
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

    cout << "\n===== SUMMARY / REPORT =====" << endl;
    cout << "Total Item Records: " << count << endl;
    cout << "Total Quantity: " << totalQty << endl;
    cout << "Total Broken: " << totalBroken << endl;
    cout << "Total Lost: " << totalLost << endl;
    cout << "Total Value: RM" << fixed << setprecision(2) << totalValue << endl;
    cout << "Total Broken Value: RM" << fixed << setprecision(2) << brokenValue << endl;
    cout << "Total Lost Value: RM" << fixed << setprecision(2) << lostValue << endl;
}