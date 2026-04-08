#include <iostream>
#include <string>
using namespace std;
class Character {
protected:
    string name;
    int    health;
    int    level;
public:
    Character(const string& n, int hp, int lvl)
        : name(n), health(hp), level(lvl) {}

    // Pure virtual functions — must be overridden by derived classes
    virtual void attack() = 0;
    virtual void power()  = 0;

    // Non-virtual helper
    void showStats() const {
        cout << "  Name   : " << name   << "\n"
             << "  Health : " << health << "\n"
             << "  Level  : " << level  << "\n";
    }
    virtual ~Character() {}
};
class Warrior : public Character {
public:
    Warrior(const string& n, int hp, int lvl)
        : Character(n, hp, lvl) {}

    void attack() override {
        cout << "[Warrior] " << name
             << " swings a heavy broadsword! ⚔️\n";
    }
    void power() override {
        cout << "[Warrior] " << name
             << " activates SHIELD BASH — stuns the enemy! 🛡️\n";
    }
};
class Mage : public Character {
public:
    Mage(const string& n, int hp, int lvl)
        : Character(n, hp, lvl) {}
    void attack() override {
        cout << "[Mage] " << name
             << " hurls a magic missile! 🔮\n";
    }
    void power() override {
        cout << "[Mage] " << name
             << " casts INFERNO BLAST — deals massive area damage! 🔥\n";
    }
};
class DamageCalculator {
public:
    // Overload 1 — basic attack (1 parameter: base damage)
    int calculateDamage(int baseDamage) {
        return baseDamage;
    }
    // Overload 2 — special attack (2 parameters: base + multiplier)
    int calculateDamage(int baseDamage, float multiplier) {
        return static_cast<int>(baseDamage * multiplier);
    }
};
class Position {
public:
    float x, y;
    Position(float px = 0.0f, float py = 0.0f) : x(px), y(py) {}
    // Operator overload: combine two positions
    Position operator+(const Position& other) const {
        return Position(x + other.x, y + other.y);
    }
    // Stream insertion overload for easy printing
    friend ostream& operator<<(ostream& os, const Position& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};
int main() {
    cout << "========================================\n";
    cout << "       2D GAME SYSTEM — C++ Demo\n";
    cout << "========================================\n\n";
    cout << "--- POLYMORPHISM (Virtual Functions) ---\n\n";
    // Create objects
    Warrior thor("Thor",  200, 10);
    Mage    merlin("Merlin", 120, 15);
    // Base class pointers pointing to derived objects
    Character* characters[2];
    characters[0] = &thor;
    characters[1] = &merlin;
    for (int i = 0; i < 2; i++) {
        characters[i]->showStats();
        characters[i]->attack();   // calls correct override via vtable
        characters[i]->power();    // calls correct override via vtable
        cout << "\n";
    }
    cout << "--- FUNCTION OVERLOADING (DamageCalculator) ---\n\n";
    DamageCalculator calc;
    int basic   = calc.calculateDamage(50);           // 1 param
    int special = calc.calculateDamage(50, 2.5f);     // 2 params
    cout << "  Basic Attack  (1 param)  : "
         << basic   << " damage\n";
    cout << "  Special Attack (2 params): "
         << special << " damage\n\n";
    cout << "--- OPERATOR OVERLOADING (Position +) ---\n\n";
    Position warrior_pos(3.0f, 5.0f);
    Position movement(2.0f, -1.0f);
    Position new_pos = warrior_pos + movement;   // calls operator+
    cout << "  Warrior start position : " << warrior_pos << "\n";
    cout << "  Movement vector        : " << movement    << "\n";
    cout << "  New position           : " << new_pos     << "\n\n";
    cout << "========================================\n";
    cout << "           End of Demo\n";
    cout << "========================================\n";
    return 0;
}