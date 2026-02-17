#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char* EmployeeName;
    const int EmployeeId;   

public:
    Employee(const char* name, int id) : EmployeeId(id) {
        EmployeeName = new char[strlen(name) + 1];
        strcpy(EmployeeName, name);
    }

    // Destructor
    ~Employee() {
        delete[] EmployeeName;
    }

    const char* getEmployeeName() const {
        return EmployeeName;
    }

    int getEmployeeId() const {
        return EmployeeId;
    }

    void setEmployeeName(const char* name) {
        delete[] EmployeeName;  
        EmployeeName = new char[strlen(name) + 1];
        strcpy(EmployeeName, name);
    }
};

int main() {

    Employee Employee1("Hania", 101);
    Employee Employee2("Arisha", 102);
    Employee Employee3("Ifrah", 103);

    Employee1.setEmployeeName("Marium");
    Employee2.setEmployeeName("Memoona");

    cout << "Employee 1: " 
         << Employee1.getEmployeeName()
         << " | ID: " 
         << Employee1.getEmployeeId() << endl;

    cout << "Employee 2: " 
         << Employee2.getEmployeeName()
         << " | ID: " 
         << Employee2.getEmployeeId() << endl;

    cout << "Employee 3: " 
         << Employee3.getEmployeeName()
         << " | ID: " 
         << Employee3.getEmployeeId() << endl;

    return 0;
}