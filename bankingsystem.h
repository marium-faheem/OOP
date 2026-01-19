#include <iostream>
using namespace std;

int processWithdrawal() {
    long accountNumber;
    char accountType;
    double balance = 200000;
    double withdrawAmount;
    double fee = 0, tax = 0;

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    cout << "Enter Account Type (S for Savings / C for Current): ";
    cin >> accountType;

    cout << "Enter Withdrawal Amount: ";
    cin >> withdrawAmount;

    // Check maximum withdrawal limit
    if (withdrawAmount > 100000) {
        cout << "Error: Cannot withdraw more than 100,000 at a time." << endl;
        return 0;
    }

    // Savings Account
    if (accountType == 'S' || accountType == 's') {
        fee = withdrawAmount * 0.02;   // 2% fee

        if (withdrawAmount > 50000) {
            tax = withdrawAmount * 0.05; // 5% tax
        }
    }
    // Current Account
    else if (accountType == 'C' || accountType == 'c') {
        fee = 100;   // fixed fee

        if (withdrawAmount > 50000) {
            tax = withdrawAmount * 0.05; // 5% tax
        }
    }
    else {
        cout << "Invalid Account Type!" << endl;
        return 0;
    }

    double totalDeduction = withdrawAmount + fee + tax;

    if (totalDeduction > balance) {
        cout << "Insufficient Balance!" << endl;
    } else {
        balance -= totalDeduction;

        cout << "\n--- Transaction Details ---" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Withdrawal Amount: " << withdrawAmount << endl;
        cout << "Fee: " << fee << endl;
        cout << "Tax: " << tax << endl;
        cout << "Remaining Balance: " << balance << endl;
    }

    return 0;
}