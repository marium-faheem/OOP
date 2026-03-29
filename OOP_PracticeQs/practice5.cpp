#include <iostream>
using namespace std;

// ========== ABSTRACT BASE CLASS ==========
class Account {
protected:
    string ownerName;
    double* transactions;  // dynamic array (Week 4)
    int transCount;
    static int totalAccounts;  // static member (Week 4)

public:
    // Constructor
    Account(string name, int count) {
        ownerName = name;
        transCount = count;
        transactions = new double[transCount];  // heap memory (Week 4)
        totalAccounts++;
    }

    // Const function (Week 4)
    string getName() const {
        return ownerName;
    }

    // Static function (Week 4)
    static int getTotalAccounts() {
        return totalAccounts;
    }

    // Pure virtual (Week 7)
    virtual double calculateBalance() = 0;

    // Regular virtual (Week 7)
    virtual void display() {
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: Rs." << calculateBalance() << endl;
    }

    // Virtual destructor
    virtual ~Account() {
        delete[] transactions;  // free heap memory
    }
};

int Account::totalAccounts = 0;  // static member initialization


// ========== INHERITANCE (Week 5) ==========
class SavingsAccount : public Account {
    double interestRate;

public:
    SavingsAccount(string name, int count, double rate) : Account(name, count) {
        interestRate = rate;
        // fill some dummy transactions
        for (int i = 0; i < transCount; i++)
            transactions[i] = (i + 1) * 1000;
    }

    // Function overriding (Week 5)
    double calculateBalance() override {
        double total = 0;
        for (int i = 0; i < transCount; i++)
            total += transactions[i];
        return total + (total * interestRate / 100);  // with interest
    }

    void display() override {
        cout << "--- Savings Account ---" << endl;
        Account::display();  // call parent display
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CurrentAccount : public Account {
    double overdraftLimit;

public:
    CurrentAccount(string name, int count, double limit) : Account(name, count) {
        overdraftLimit = limit;
        for (int i = 0; i < transCount; i++)
            transactions[i] = (i + 1) * 500;
    }

    double calculateBalance() override {
        double total = 0;
        for (int i = 0; i < transCount; i++)
            total += transactions[i];
        return total;  // no interest
    }

    void display() override {
        cout << "--- Current Account ---" << endl;
        Account::display();
        cout << "Overdraft Limit: Rs." << overdraftLimit << endl;
    }
};


// ========== OPERATOR OVERLOADING (Week 6) ==========
class Money {
    double amount;

public:
    Money(double a) : amount(a) {}

    // + operator overloading
    Money operator+(const Money& m) {
        return Money(amount + m.amount);
    }

    // == operator overloading
    bool operator==(const Money& m) {
        return amount == m.amount;
    }

    // << operator overloading (friend function)
    friend ostream& operator<<(ostream& out, const Money& m) {
        out << "Rs." << m.amount;
        return out;
    }
};


// ========== MAIN ==========
int main() {

    // Abstract class pointers (Week 7)
    Account* accounts[2];
    accounts[0] = new SavingsAccount("Marium", 3, 10);
    accounts[1] = new CurrentAccount("Umer", 3, 5000);

    // Display all accounts
    for (int i = 0; i < 2; i++) {
        accounts[i]->display();
        cout << endl;
    }

    // Static member (Week 4)
    cout << "Total Accounts: " << Account::getTotalAccounts() << endl;
    cout << endl;

    // Operator overloading (Week 6)
    Money m1(1500), m2(2500);
    Money m3 = m1 + m2;
    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;
    cout << "m1 + m2 = " << m3 << endl;
    cout << "m1 == m2? " << (m1 == m2 ? "Yes" : "No") << endl;

    // Cleanup
    delete accounts[0];
    delete accounts[1];

    return 0;
}