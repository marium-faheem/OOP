#include <iostream>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Person constructor called\n";
    }

    // Function Overloading (Compile-time Polymorphism)
    void display() {
        cout << "Name: " << name << endl;
    }

    void display(int x) {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Virtual function (Abstraction + Runtime Polymorphism)
    virtual void role() {
        cout << "This person has a role.\n";
    }

    // Destructor
    ~Person() {
        cout << "Person destructor called\n";
    }
};

// Derived Class (Inheritance)
class Student : public Person {
private:
    int rollNo;

public:
    // Constructor
    Student(string n, int a, int r) : Person(n, a) {
        rollNo = r;
        cout << "Student constructor called\n";
    }

    // Function Overriding (Runtime Polymorphism)
    void role() {
        cout << "Role: Student\n";
    }

    void showStudent() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
    }

    // Destructor
    ~Student() {
        cout << "Student destructor called\n";
    }
};

int main() {
    // Object creation
    Student s1("Umer", 20, 101);

    cout << endl;

    // Encapsulation through member functions
    s1.display();
    s1.display(1);

    cout << endl;

    // Runtime Polymorphism
    Person* p;
    p = &s1;
    p->role();

    cout << endl;

    s1.showStudent();

    return 0;
}