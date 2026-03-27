#include<iostream>
using namespace std;
//Abstract class
class FoodItem {
    protected:
    string name;
    int quantity;
    public:
    FoodItem(string n, int q){
        name=n;
        quantity=q;
    }
    virtual double calculatePrice() = 0;
    virtual void displayOrder() {
        cout<<"Item: "<<name<<endl;
        cout<<"Quantity: "<<quantity<<endl;
        cout<<"Total: Rs."<<calculatePrice()<<endl;
    }
    virtual ~FoodItem(){}
};
//Pizza - charged per slice
class Pizza : public FoodItem {
    double pricePerSlice;
    public:
    Pizza(string n, int slices, double price) : FoodItem(n, slices) {
        pricePerSlice = price;
    }

    double calculatePrice() override {
        return quantity * pricePerSlice;
    }
};
// Drink — charged per bottle with tax
class Drink : public FoodItem {
    double pricePerBottle;
    double taxRate;

public:
    Drink(string n, int bottles, double price, double tax) : FoodItem(n, bottles) {
        pricePerBottle = price;
        taxRate = tax;
    }

    double calculatePrice() override {
        double base = quantity * pricePerBottle;
        return base + (base * taxRate / 100);
    }
};

// Deal — flat price no matter what
class Deal : public FoodItem {
    double flatPrice;

public:
    Deal(string n, int qty, double price) : FoodItem(n, qty) {
        flatPrice = price;
    }

    double calculatePrice() override {
        return flatPrice;  // fixed price regardless of quantity
    }

    // Overriding display too just to add a custom message
    void displayOrder() override {
        FoodItem::displayOrder();
        cout << "Deal applied!" << endl;
    }
};

int main() {
    FoodItem* order[3];
    order[0] = new Pizza("Zinger Pizza", 4, 350);
    order[1] = new Drink("Pepsi", 2, 150, 10);
    order[2] = new Deal("Family Deal", 1, 2500);

    cout << "===== Your Order =====\n";
    double grandTotal = 0;

    for (int i = 0; i < 3; i++) {
        order[i]->displayOrder();
        grandTotal += order[i]->calculatePrice();
        cout << "----------\n";
    }

    cout << "Grand Total: Rs." << grandTotal << endl;

    delete order[0];
    delete order[1];
    delete order[2];

    return 0;
}