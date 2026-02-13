#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;
    static int totalAccounts;

public:
    // Default Constructor
    BankAccount() {
        accountHolder = "Unknown";
        accountNumber = 0;
        balance = 0.0;
        totalAccounts++;
    }

    // Parameterized Constructor
    BankAccount(string name, int accNo, double bal) {
        accountHolder = name;
        accountNumber = accNo;
        balance = bal;
        totalAccounts++;
    }

    // Destructor
    ~BankAccount() {
        cout << "Account of " << accountHolder << " deleted.\n";
        totalAccounts--;
    }

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    // Display function
    void display() const {
        cout << "Name: " << accountHolder << endl;
        cout << "Account No: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "----------------------\n";
    }

    // Static function
    static void showTotalAccounts() {
        cout << "Total Accounts: " << totalAccounts << endl;
    }
};

// Static variable initialization
int BankAccount::totalAccounts = 0;

int main() {
    BankAccount acc1("Marium", 101, 5000);
    BankAccount acc2("Ali", 102, 3000);

    acc1.deposit(1000);
    acc2.withdraw(500);

    acc1.display();
    acc2.display();

    BankAccount::showTotalAccounts();

    return 0;
}
