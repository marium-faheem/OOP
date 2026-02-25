#include <iostream>
#include <vector>

using namespace std;

class Vehicle {
private:
    string brand;
    int hp;
public:
    Vehicle(string brand = "", int hp = 0) {
        this->brand = brand;
        this->hp = hp;
    }

    void print() {
        cout << " - " << brand << " with " << hp << " horsepower" << endl;
    }
};

class Dealership {
private:
    string name;
    vector<Vehicle> cars;
public:
    Dealership(string name = 0, vector<Vehicle> cars = {}) {
        this->name = name;
        this->cars = cars;
    }

    // We take the new vehicle as argument
    Dealership& operator+=(const Vehicle &v) {
        cars.push_back(v);
        return *this;
    }

    void printDetails() {
        cout << "Dealership: " << name << " | Number of cars: " << cars.size() << endl;
        for(auto car : cars)
            car.print();
    }
};

int main() {

    Dealership dealership("NYC Cars");
    Vehicle car1("BMW", 320);
    Vehicle car2("Mustang", 477);
    Vehicle car3("Mercedes", 386);
    dealership += car1;
    dealership += car2;
    dealership += car3;

    dealership.printDetails();

    return 0;
}