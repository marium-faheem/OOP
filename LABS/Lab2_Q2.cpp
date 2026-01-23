#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;
    int transactions;
    double interestRate;

public:
    // Constructor
    BankAccount() {
        balance = 0.0;
        transactions = 0;
        interestRate = 0.05;   // 5% interest
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactions++;
            cout << "Deposit successful.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactions++;
            cout << "Withdrawal successful.\n";
        } else {
            cout << "Invalid withdrawal amount.\n";
        }
    }

    void displayBalance() {
        cout << "Current Account Balance: Rs. " << balance << endl;
    }

    void displayTransactions() {
        cout << "Number of Transactions: " << transactions << endl;
    }

    void displayInterest() {
        double interest = balance * interestRate;
        cout << "Interest Earned: Rs. " << interest << endl;
    }
};

int main() {
    BankAccount account;
    int choice;
    double amount;

    do {
        cout << "\n--- ABC BANK MENU ---\n";
        cout << "1. Display the account balance\n";
        cout << "2. Display the number of transactions\n";
        cout << "3. Display interest earned for this period\n";
        cout << "4. Make a deposit\n";
        cout << "5. Make a withdrawal\n";
        cout << "6. Exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.displayBalance();
                break;

            case 2:
                account.displayTransactions();
                break;

            case 3:
                account.displayInterest();
                break;

            case 4:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 5:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 6:
                cout << "Thank you for using ABC Bank!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}