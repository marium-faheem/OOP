#include<iostream>
using namespace std;

class Character {
private:
    int *health;
    int *attackPower;
    int *defense;

public:
    // Default Constructor
    Character() {
        health = new int(100);
        attackPower = new int(50);
        defense = new int(30);
    }

    // Parameterized Constructor
    Character(int h, int a, int d) {
        health = new int(h);
        attackPower = new int(a);
        defense = new int(d);
    }

    // Copy Constructor (Deep Copy)
    Character(const Character &obj) {
        health = new int(*(obj.health));
        attackPower = new int(*(obj.attackPower));
        defense = new int(*(obj.defense));
    }

    // Setter methods
    void setHealth(int h) {
        *health = h;
    }

    void setAttackPower(int a) {
        *attackPower = a;
    }

    void setDefense(int d) {
        *defense = d;
    }

    // Getter methods
    int getHealth() const {
        return *health;
    }

    int getAttackPower() const {
        return *attackPower;
    }

    int getDefense() const {
        return *defense;
    }

    // Display Character Stats
    void display() const {
        cout << "Health: " << *health
             << ", Attack Power: " << *attackPower
             << ", Defense: " << *defense << endl;
    }

    // Destructor
    ~Character() {
        delete health;
        delete attackPower;
        delete defense;
    }
};

int main() {
    // Default character
    Character c1;
    cout << "Default Character:\n";
    c1.display();

    // Parameterized character
    Character c2(150, 80, 60);
    cout << "\nCustom Character:\n";
    c2.display();

    // Copied character
    Character c3 = c2;
    cout << "\nCopied Character:\n";
    c3.display();

    return 0;
}