#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char* firstName;      // DMA
    string lastName;
    int monthlySalary;

public:
    // Default constructor
    Employee() {
        firstName = nullptr;
        monthlySalary = 0;
    }

    // Setter function
    void setEmployee(const char* fName, string lName, int salary) {
        // Allocate memory for first name
        firstName = new char[strlen(fName) + 1];
        strcpy(firstName, fName);

        lastName = lName;

        if (salary > 0)
            monthlySalary = salary;
        else
            monthlySalary = 0;
    }

    // Getter functions
    char* getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    int getMonthlySalary() {
        return monthlySalary;
    }

    // Function to calculate yearly salary
    int getYearlySalary() {
        return monthlySalary * 12;
    }

    // Function to give 10% raise
    void giveRaise() {
        monthlySalary = monthlySalary + (monthlySalary * 10 / 100);
    }

    // Destructor to free DMA
    ~Employee() {
        delete[] firstName;
    }
};

int main() {
    Employee emp1, emp2;

    // Initialize employees
    emp1.setEmployee("Ali", "Khan", 50000);
    emp2.setEmployee("Sara", "Ahmed", 60000);

    // Display yearly salaries
    cout << "Yearly Salary of " << emp1.getFirstName()
         << " " << emp1.getLastName() << " : "
         << emp1.getYearlySalary() << endl;

    cout << "Yearly Salary of " << emp2.getFirstName()
         << " " << emp2.getLastName() << " : "
         << emp2.getYearlySalary() << endl;

    // Give 10% raise
    emp1.giveRaise();
    emp2.giveRaise();

    cout << "\nAfter 10% Raise:\n";

    cout << "Yearly Salary of " << emp1.getFirstName()
         << " " << emp1.getLastName() << " : "
         << emp1.getYearlySalary() << endl;

    cout << "Yearly Salary of " << emp2.getFirstName()
         << " " << emp2.getLastName() << " : "
         << emp2.getYearlySalary() << endl;

    return 0;
}