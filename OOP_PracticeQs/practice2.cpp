#include <iostream>
using namespace std;

// Base Class (Abstraction)
class Animal {
protected:
    string name;

public:
    // Constructor
    Animal(string n) {
        name = n;
    }

    // Virtual function (for polymorphism)
    virtual void speak() {
        cout << name << " makes a sound." << endl;
    }
};

// Derived Class (Inheritance)
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    // Function overriding (Polymorphism)
    void speak() {
        cout << name << " barks." << endl;
    }
};

// Another Derived Class
class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    void speak() {
        cout << name << " meows." << endl;
    }
};

// Encapsulation Example
class BankAccount {
private:
    double balance;

public:
    // Setter
    void deposit(double amount) {
        balance += amount;
    }

    // Getter
    double getBalance() {
        return balance;
    }
};

int main() {

    // Objects
    Dog d1("Buddy");
    Cat c1("Kitty");

    // Polymorphism using base class pointer
    Animal* a;

    a = &d1;
    a->speak();

    a = &c1;
    a->speak();

    // Encapsulation demo
    BankAccount acc;
    acc.deposit(500);

    cout << "Balance: " << acc.getBalance() << endl;

    return 0;
}