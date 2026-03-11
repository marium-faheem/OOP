#include <iostream>
using namespace std;

// Base Class
class Character {
protected:
    string name;
    int power;

public:
    Character(string n, int p) {
        name = n;
        power = p;
    }

    // Virtual function
    virtual void attack() {
        cout << name << " attacks with power " << power << endl;
    }
};

// Derived Class 1
class Wizard : public Character {
public:
    Wizard(string n, int p) : Character(n, p) {}

    void attack() {
        cout << name << " casts a fire spell with power " << power << endl;
    }
};

// Derived Class 2
class Ninja : public Character {
public:
    Ninja(string n, int p) : Character(n, p) {}

    void attack() {
        cout << name << " throws a shuriken with power " << power << endl;
    }
};

int main() {
    Character* c;

    Wizard w("Merlin", 90);
    Ninja n("Shadow", 75);

    c = &w;
    c->attack();

    c = &n;
    c->attack();

    return 0;
}