#include <iostream>
using namespace std;

// Base class (Abstraction + Encapsulation)
class Animal {
protected:
    string name;

public:
    void setName(string n) {   // setter (encapsulation)
        name = n;
    }

    string getName() {        // getter
        return name;
    }

    // Virtual function for polymorphism
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

// Derived class (Inheritance)
class Dog : public Animal {
public:
    void sound() {   // Function overriding (Polymorphism)
        cout << name << " says: Bark" << endl;
    }
};

// Another derived class
class Cat : public Animal {
public:
    void sound() {
        cout << name << " says: Meow" << endl;
    }
};

int main() {
    Dog d;
    Cat c;

    d.setName("Tommy");
    c.setName("Kitty");

    d.sound();
    c.sound();

    return 0;
}