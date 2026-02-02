#include <iostream>
using namespace std;

class Student {
    const int rollNo;   // constant data member

public:
    Student(int r) : rollNo(r) {}   // initialization list

    void show() {
        cout << "Roll Number: " << rollNo << endl;
    }
};

int main() {
    Student s1(23);
    s1.show();
    return 0;
}
