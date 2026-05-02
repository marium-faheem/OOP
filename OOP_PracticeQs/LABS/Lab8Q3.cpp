#include <iostream>
using namespace std;

// Base Account class
class Account {
protected:
    double balance;
public:
    Account() {
        cout << "Enter balance: ";
        cin >> balance;
    }
    Account(double b) : balance(b) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient balance!" << endl;
        else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    void checkBalance() {
        cout << "Balance: Rs." << balance << endl;
    }
};

// InterestAccount - adds 30% on every deposit
class InterestAccount : virtual public Account {
protected:
    double interest;
public:
    InterestAccount() : Account() {
        cout << "Enter interest rate (default 0.30): ";
        cin >> interest;
    }
    InterestAccount(double b, double i) : Account(b), interest(i) {}

    void deposit(double amount) override {
        double withInterest = amount + (amount * interest);
        balance += withInterest;
        cout << "Deposited with " << interest * 100 << "% interest: Rs." << withInterest << endl;
    }
};

// ChargingAccount - charges Rs.25 on every withdrawal
class ChargingAccount : virtual public Account {
protected:
    double fee;
public:
    ChargingAccount() : Account() {
        cout << "Enter fee (default 25): ";
        cin >> fee;
    }
    ChargingAccount(double b, double f) : Account(b), fee(f) {}

    void withdraw(double amount) override {
        double totalDeduction = amount + fee;
        if (totalDeduction > balance)
            cout << "Insufficient balance (including Rs." << fee << " fee)!" << endl;
        else {
            balance -= totalDeduction;
            cout << "Withdrawn: Rs." << amount << " + Rs." << fee << " fee" << endl;
        }
    }
};

// ACI - inherits both (diamond problem!)
class ACI : public InterestAccount, public ChargingAccount {
public:
    ACI(double b, double i, double f)
        : Account(b), InterestAccount(b, i), ChargingAccount(b, f) {}

    // transfer to a base Account
    void transfer(double amount, Account& acc) {
        if (amount > balance)
            cout << "Insufficient balance for transfer!" << endl;
        else {
            balance -= amount;
            acc.deposit(amount);
            cout << "Transferred Rs." << amount << " to Account." << endl;
        }
    }

    // transfer to InterestAccount
    void transfer(double amount, InterestAccount& acc) {
        if (amount > balance)
            cout << "Insufficient balance for transfer!" << endl;
        else {
            balance -= amount;
            acc.deposit(amount);
            cout << "Transferred Rs." << amount << " to Interest Account." << endl;
        }
    }

    // transfer to ChargingAccount
    void transfer(double amount, ChargingAccount& acc) {
        if (amount > balance)
            cout << "Insufficient balance for transfer!" << endl;
        else {
            balance -= amount;
            acc.deposit(amount);
            cout << "Transferred Rs." << amount << " to Charging Account." << endl;
        }
    }

    void deposit(double amount) override {
        InterestAccount::deposit(amount);
    }

    void withdraw(double amount) override {
        ChargingAccount::withdraw(amount);
    }

    void checkBalance() {
        cout << "ACI Balance: Rs." << balance << endl;
    }
};

int main() {
    cout << "===== Account System =====" << endl;

    Account acc(1000);
    InterestAccount ia(2000, 0.30);
    ChargingAccount ca(3000, 25);
    ACI aci(5000, 0.30, 25);

    cout << "\n--- Basic Account ---" << endl;
    acc.deposit(500);
    acc.checkBalance();
    acc.withdraw(200);
    acc.checkBalance();

    cout << "\n--- Interest Account ---" << endl;
    ia.deposit(1000);
    ia.checkBalance();

    cout << "\n--- Charging Account ---" << endl;
    ca.withdraw(500);
    ca.checkBalance();

    cout << "\n--- ACI ---" << endl;
    aci.deposit(1000);
    aci.checkBalance();
    aci.withdraw(500);
    aci.checkBalance();

    cout << "\n--- ACI Transfer ---" << endl;
    aci.transfer(300, acc);
    aci.transfer(200, ia);
    aci.transfer(100, ca);
    aci.checkBalance();

    return 0;
}