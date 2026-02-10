#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;

public:
    void setName(string n) {
        name = n;
    }

    void showName() {
        cout << "Name: " << name << endl;
    }
};

// Derived class (Level 1)
class Student : public Person {
protected:
    int rollNo;

public:
    void setRollNo(int r) {
        rollNo = r;
    }

    void showRollNo() {
        cout << "Roll Number: " << rollNo << endl;
    }
};

// Derived class (Level 2)
class Result : public Student {
private:
    float marks;

public:
    void setMarks(float m) {
        marks = m;
    }

    void showResult() {
        showName();      // from Person
        showRollNo();    // from Student
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Result obj;

    obj.setName("Marium");
    obj.setRollNo(168);
    obj.setMarks(88.5);

    obj.showResult();

    return 0;
}
