#include<iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Constructor for Base" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Constructor for Derived" << endl;
    }
};

int main() {

    Base base;
    Derived derived;

    return 0;
}

