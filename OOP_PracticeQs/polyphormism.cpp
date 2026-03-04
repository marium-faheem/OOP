#include <iostream>
using namespace std;

// Base Class
class Animal {
public:
    // Virtual function for runtime polymorphism
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }

    // Function overloading (Compile-time polymorphism)
    void eat() {
        cout << "Animal eats food" << endl;
    }

    void eat(string food) {
        cout << "Animal eats " << food << endl;
    }
};

// Derived Class 1
class Dog : public Animal {
public:
    // Overriding base class function
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

// Derived Class 2
class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    // Base class pointer (Runtime Polymorphism)
    Animal* a1;
    Dog d;
    Cat c;

    a1 = &d;
    a1->sound();  // Calls Dog's sound()

    a1 = &c;
    a1->sound();  // Calls Cat's sound()

    // Compile-time Polymorphism
    d.eat();
    d.eat("bone");

    return 0;
}