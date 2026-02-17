#include <iostream>
using namespace std;


class HotelInterface {
public:
    virtual void calculateRent() = 0;
    virtual void display() const = 0;
};

class HotelMercato : public HotelInterface {
private:
    string customerName;
    int days;
    const double rentPerDay;  
    double totalRent;

public:
    HotelMercato(string name, int d)
        : customerName(name), days(d), rentPerDay(1000.85) {
        totalRent = 0;
    }

    void calculateRent() override {
        int chargeableDays = days;

        if (days > 7) {
            chargeableDays = days - 1;   
        }

        totalRent = chargeableDays * rentPerDay;
    }

    void display() const override {
        cout << "Customer Name: " << customerName << endl;
        cout << "Days Stayed: " << days << endl;
        cout << "Total Rent: Rs. " << totalRent << endl;
    }
};

int main() {
    HotelMercato customer1("Marium", 8);

    customer1.calculateRent();
    customer1.display();

    return 0;
}