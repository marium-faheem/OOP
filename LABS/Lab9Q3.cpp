#include <iostream>
using namespace std;

// Abstract Base Class
class Vehicle {
protected:
    int carId;
    string brand;
    string model;

public:
    Vehicle(int id, string b, string m) {
        carId = id;
        brand = b;
        model = m;
    }

    // Pure Virtual Functions
    virtual bool isAvailable() = 0;
    virtual void rent() = 0;
    virtual void returnVehicle() = 0;

    // Display Function
    virtual void display() {
        cout << "\nCar ID: " << carId << endl;
        cout << "Brand : " << brand << endl;
        cout << "Model : " << model << endl;
    }

    // Virtual Destructor
    virtual ~Vehicle() {}
};

// Derived Class
class Car : public Vehicle {
private:
    bool available;

public:
    Car(int id, string b, string m, bool a = true)
        : Vehicle(id, b, m) {
        available = a;
    }

    // Implementation of Pure Virtual Functions
    bool isAvailable() override {
        return available;
    }

    void rent() override {
        if (available) {
            available = false;
            cout << "Car rented successfully.\n";
        }
        else {
            cout << "Car is already rented.\n";
        }
    }

    void returnVehicle() override {
        available = true;
        cout << "Car returned successfully.\n";
    }

    void display() override {
        Vehicle::display();
        cout << "Availability: ";
        
        if (available)
            cout << "Available\n";
        else
            cout << "Not Available\n";
    }
};

// Rental System Class
class RentalSystem {
public:
    void rentVehicle(Vehicle* v) {
        if (v->isAvailable()) {
            v->rent();
        }
        else {
            cout << "Vehicle is not available.\n";
        }
    }

    void returnVehicle(Vehicle* v) {
        v->returnVehicle();
    }
};

// Customer Class
class Customer {
private:
    string customerName;

public:
    Customer(string name) {
        customerName = name;
    }

    void rentVehicle(RentalSystem& rs, Vehicle* v) {
        cout << "\nCustomer " << customerName 
             << " wants to rent a vehicle.\n";
        rs.rentVehicle(v);
    }

    void returnVehicle(RentalSystem& rs, Vehicle* v) {
        cout << "\nCustomer " << customerName 
             << " is returning a vehicle.\n";
        rs.returnVehicle(v);
    }
};

// Main Function
int main() {

    // Array of Base Class Pointers
    Vehicle* vehicles[3];

    // Dynamic Memory Allocation
    vehicles[0] = new Car(101, "Toyota", "Corolla");
    vehicles[1] = new Car(102, "Honda", "Civic");
    vehicles[2] = new Car(103, "Suzuki", "Swift");

    // Display All Vehicles
    cout << "===== Available Cars =====\n";

    for (int i = 0; i < 3; i++) {
        vehicles[i]->display();
    }

    RentalSystem rs;

    Customer c1("Ali");

    // Renting Vehicle
    c1.rentVehicle(rs, vehicles[0]);

    // Display Updated Status
    vehicles[0]->display();

    // Returning Vehicle
    c1.returnVehicle(rs, vehicles[0]);

    // Display Updated Status
    vehicles[0]->display();

    // Free Memory
    for (int i = 0; i < 3; i++) {
        delete vehicles[i];
    }

    return 0;
}