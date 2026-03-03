#include<iostream>
using namespace std;
class Base {
public:
    void print() {
        cout << "Base class" << endl;
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived class" << endl;
    }
};
int main() {
    Derived derivedObj;
    Base* basePtr = &derivedObj;  // Upcasting
    basePtr->print();  
    // Outputs: Base class
    return 0;
}