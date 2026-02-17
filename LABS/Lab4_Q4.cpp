#include <iostream>
using namespace std;

class Student {
private:
    const int roll_no;   
    string name;

public:
    Student(int r, string n) : roll_no(r) {
        name = n;
    }

    void display() const {  
        cout << "Roll Number: " << roll_no << endl;
        cout << "Name: " << name << endl;
    }
};

int main() {
    Student s1(168, "Marium");

    s1.display();

    return 0;
}