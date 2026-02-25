#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle {
private:
    string brand;
    int hp;

public:
    // Constructor
    Vehicle(string brand = "", int hp = 0) {
        this->brand = brand;
        this->hp = hp;
    }

    // Display function
    void display() const {
        cout << "Brand: " << brand << ", Horsepower: " << hp << endl;
    }
};

class Dealership {
private:
    string name;
    vector<Vehicle> cars;

public:
    // Corrected constructor
    Dealership(string name = "", vector<Vehicle> cars = {}) {
        this->name = name;
        this->cars = cars;
    }

    // Overloaded += operator
    Dealership& operator+=(const Vehicle &v) {
        cars.push_back(v);
        return *this; 
    }

    // Display all vehicles
    void display() const {
        cout << "Dealership Name: " << name << endl;
        cout << "Available Vehicles:\n";
        for (const auto &car : cars) {
            car.display();
        }
    }
};

int main() {

    // Create Vehicle objects
    Vehicle v1("Toyota", 150);
    Vehicle v2("Honda", 180);
    Vehicle v3("BMW", 300);

    // Create Dealership object
    Dealership d1("Super Cars");

    // Add vehicles using overloaded +=
    d1 += v1;
    d1 += v2;
    d1 += v3;

    // Display dealership inventory
    d1.display();

    return 0;
}
