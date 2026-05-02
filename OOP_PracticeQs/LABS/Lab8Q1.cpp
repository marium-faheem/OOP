#include <iostream>
using namespace std;

// Base class
class Vehicle {
protected:
    string typeCar, make, model, color;
    int year;
    double milesDriven;
public:
    Vehicle(string t, string mk, string mo, string c, int y, double m)
        : typeCar(t), make(mk), model(mo), color(c), year(y), milesDriven(m) {}

    virtual void display() {
        cout << "Type: " << typeCar << "\nMake: " << make
             << "\nModel: " << model << "\nColor: " << color
             << "\nYear: " << year << "\nMiles Driven: " << milesDriven << endl;
    }
};

// GasVehicle - virtual inheritance
class GasVehicle : virtual public Vehicle {
protected:
    double fuelTankSize;
public:
    GasVehicle(string t, string mk, string mo, string c, int y, double m, double f)
        : Vehicle(t, mk, mo, c, y, m), fuelTankSize(f) {}

    void display() override {
        Vehicle::display();
        cout << "Fuel Tank Size: " << fuelTankSize << "L" << endl;
    }
};

// ElectricVehicle - virtual inheritance
class ElectricVehicle : virtual public Vehicle {
protected:
    double energyStorage;
public:
    ElectricVehicle(string t, string mk, string mo, string c, int y, double m, double e)
        : Vehicle(t, mk, mo, c, y, m), energyStorage(e) {}

    void display() override {
        Vehicle::display();
        cout << "Energy Storage: " << energyStorage << " kWh" << endl;
    }
};

// HighPerformance inherits GasVehicle
class HighPerformance : public GasVehicle {
protected:
    double horsePower, topSpeed;
public:
    HighPerformance(string t, string mk, string mo, string c, int y, double m,
                    double f, double hp, double ts)
        : Vehicle(t, mk, mo, c, y, m), GasVehicle(t, mk, mo, c, y, m, f),
          horsePower(hp), topSpeed(ts) {}

    void display() override {
        GasVehicle::display();
        cout << "Horse Power: " << horsePower << "\nTop Speed: " << topSpeed << " km/h" << endl;
    }
};

// HeavyVehicle inherits both GasVehicle and ElectricVehicle (diamond!)
class HeavyVehicle : public GasVehicle, public ElectricVehicle {
protected:
    double maxWeight, length;
    int numWheels;
public:
    HeavyVehicle(string t, string mk, string mo, string c, int y, double m,
                 double f, double e, double mw, int nw, double l)
        : Vehicle(t, mk, mo, c, y, m),
          GasVehicle(t, mk, mo, c, y, m, f),
          ElectricVehicle(t, mk, mo, c, y, m, e),
          maxWeight(mw), numWheels(nw), length(l) {}

    void display() override {
        Vehicle::display();
        cout << "Fuel Tank Size: " << fuelTankSize << "L"
             << "\nEnergy Storage: " << energyStorage << " kWh"
             << "\nMax Weight: " << maxWeight << " tons"
             << "\nNumber of Wheels: " << numWheels
             << "\nLength: " << length << "m" << endl;
    }
};

// SportsCar inherits HighPerformance
class SportsCar : public HighPerformance {
private:
    string gearbox, driveSystem;
public:
    SportsCar(string t, string mk, string mo, string c, int y, double m,
              double f, double hp, double ts, string gb, string ds)
        : Vehicle(t, mk, mo, c, y, m),
          HighPerformance(t, mk, mo, c, y, m, f, hp, ts),
          gearbox(gb), driveSystem(ds) {}

    void display() override {
        HighPerformance::display();
        cout << "Gearbox: " << gearbox << "\nDrive System: " << driveSystem << endl;
    }
};

// ConstructionTruck inherits HeavyVehicle
class ConstructionTruck : public HeavyVehicle {
public:
    string cargo;
    ConstructionTruck(string t, string mk, string mo, string c, int y, double m,
                      double f, double e, double mw, int nw, double l, string cg)
        : Vehicle(t, mk, mo, c, y, m),
          HeavyVehicle(t, mk, mo, c, y, m, f, e, mw, nw, l),
          cargo(cg) {}

    void display() override {
        HeavyVehicle::display();
        cout << "Cargo: " << cargo << endl;
    }
};

// Bus inherits HeavyVehicle
class Bus : public HeavyVehicle {
private:
    int numSeats;
public:
    Bus(string t, string mk, string mo, string c, int y, double m,
        double f, double e, double mw, int nw, double l, int seats)
        : Vehicle(t, mk, mo, c, y, m),
          HeavyVehicle(t, mk, mo, c, y, m, f, e, mw, nw, l),
          numSeats(seats) {}

    void display() override {
        HeavyVehicle::display();
        cout << "Number of Seats: " << numSeats << endl;
    }
};

int main() {
    Bus myBus("Heavy", "Mercedes", "Citaro", "White", 2022, 50000.0,
              200.0, 100.0, 18.0, 6, 12.0, 50);

    cout << "===== Bus Details =====" << endl;
    myBus.display();

    return 0;
}