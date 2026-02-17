#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char* name;

public:
    // Default constructor
    Student() {
        name = new char[8];
        strcpy(name, "Unknown");
        cout << "Default constructor called\n";
    }

    // Parameterized constructor
    Student(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        cout << "Parameterized constructor called\n";
    }

    // Copy constructor (deep copy)
    Student(const Student& s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        cout << "Copy constructor called\n";
    }

    // Setter to modify name
    void setName(const char* n) {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Display function
    void display() const {
        cout << "Student Name: " << name << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called for " << name << endl;
        delete[] name;
    }
};

int main() {
    Student s1;                 // Default constructor
    Student s2("Marium");       // Parameterized constructor
    Student s3 = s2;            // Copy constructor

    cout << "\nBefore modification:\n";
    s1.display();
    s2.display();
    s3.display();

    // Modify copied object
    s3.setName("Ayesha");

    cout << "\nAfter modifying copied object:\n";
    s2.display();   // Original remains unchanged
    s3.display();   // Copied object updated

    return 0;
}
