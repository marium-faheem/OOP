#include <iostream>
using namespace std;

class TollBooth {
private:
    int totalCars;
    double totalCash;

public:
    // Constructor
    TollBooth() {
        totalCars = 0;
        totalCash = 0.0;
    }

    // Function for a paying car
    void payingCar() {
        totalCars++;
        totalCash += 0.50;
    }

    // Display totals
    void display() const {
        cout << "\nTotal Cars Passed: " << totalCars << endl;
        cout << "Total Cash Collected: $" << totalCash << endl;
    }
};

int main() {
    TollBooth booth;
    int choice;

    cout << "Toll Booth Simulation\n";

    do {
        cout << "\n1. Car Passed (Paying)\n";
        cout << "2. Display Totals\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            booth.payingCar();
            cout << "Car registered. $0.50 added.\n";
            break;
        case 2:
            booth.display();
            break;
        case 3:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}