#include<iostream>
using namespace std;
class Employee {
    private:
        int id;
        int salary;
    public:
        string name;
        string position;
        Employee(int empId, string empName, string empPosition, int empSalary) {
            id = empId;
            name = empName;
            position = empPosition;
            salary = empSalary;
        }
        void displayInfo() {
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Position: " << position << endl;
            cout << "Salary: $" << salary << endl;
        }
};
int main(){
    Employee emp1(1, "John Doe", "Software Engineer", 75000);
    emp1.displayInfo();
    Employee emp2(2, "Jane Smith", "Project Manager", 90000);
    emp2.displayInfo();
    return 0;
}