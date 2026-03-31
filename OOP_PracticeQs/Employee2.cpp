#include<iostream>
#include<string>
using namespace std;

class Employee {
protected:
    string name;
public:
    Employee(string n) : name(n) {}
    virtual float calculateMonthlyEarnings() = 0;  // pure virtual
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Monthly Earnings: " << calculateMonthlyEarnings() << endl;
    }
};

class FullTimeEmployee : public Employee {
private:
    float salary;
public:
    FullTimeEmployee(string n, float s) : Employee(n), salary(s) {}
    float calculateMonthlyEarnings() override {
        return salary;  // fixed salary
    }
};

class PartTimeEmployee : public Employee {
private:
    float hourlyPay;
    int hoursWorked;
public:
    PartTimeEmployee(string n, float h, int hrs) 
        : Employee(n), hourlyPay(h), hoursWorked(hrs) {}
    float calculateMonthlyEarnings() override {
        return hourlyPay * hoursWorked;  // hourly * hours
    }
};

int main() {
    FullTimeEmployee fte("Ali", 50000);
    PartTimeEmployee pte("Sara", 500, 80);
    
    fte.display();
    pte.display();
    return 0;
}