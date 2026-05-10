#include <iostream>
using namespace std;

// Abstract Class
class Store {
protected:
    float total_bill;

public:
    // Constructor
    Store(float bill) {
        total_bill = bill;
    }

    // Pure Virtual Function
    virtual void calculateFinalBill() = 0;
};

// Derived Class for Imtiaz Store
class ImtiazStore : public Store {
public:
    ImtiazStore(float bill) : Store(bill) {}

    void calculateFinalBill() override {
        float discount = total_bill * 0.07;
        float final_bill = total_bill - discount;

        cout << "\n--- Imtiaz Store ---" << endl;
        cout << "Total Bill: " << total_bill << endl;
        cout << "Discount (7%): " << discount << endl;
        cout << "Final Bill: " << final_bill << endl;
    }
};

// Derived Class for Bin Hashim Store
class BinHashimStore : public Store {
public:
    BinHashimStore(float bill) : Store(bill) {}

    void calculateFinalBill() override {
        float discount = total_bill * 0.05;
        float final_bill = total_bill - discount;

        cout << "\n--- Bin Hashim Store ---" << endl;
        cout << "Total Bill: " <<total_bill << endl;
        cout << "Discount (5%): " << discount << endl;
        cout << "Final Bill: " << final_bill << endl;
    }
};

int main() {
    float bill;

    cout << "Enter Total Bill Amount: ";
    cin >> bill;

    // Base class pointer
    Store* ptr;

    // Imtiaz Store Object
    ImtiazStore i1(bill);
    ptr = &i1;
    ptr->calculateFinalBill();

    // Bin Hashim Store Object
    BinHashimStore b1(bill);
    ptr = &b1;
    ptr->calculateFinalBill();

    return 0;
}