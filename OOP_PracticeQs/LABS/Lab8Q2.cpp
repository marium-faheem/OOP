#include <iostream>
using namespace std;

// Base class
class Character {
protected:
    string name;
    int level, health;
public:
    Character(string n, int l, int h) : name(n), level(l), health(h) {}

    virtual void display() {
        cout << "Name: " << name << "\nLevel: " << level << "\nHealth: " << health << endl;
    }

    virtual void ability() = 0;
};

// Warrior
class Warrior : virtual public Character {
protected:
    int strength;
    string meleeWeapon;
public:
    Warrior(string n, int l, int h, int s, string mw)
        : Character(n, l, h), strength(s), meleeWeapon(mw) {}

    void display() override {
        Character::display();
        cout << "Strength: " << strength << "\nMelee Weapon: " << meleeWeapon << endl;
    }

    void ability() override {
        cout << name << " uses SLASH! " << endl;
    }
};

// Mage
class Mage : virtual public Character {
protected:
    int intelligence;
    string spellCasting;
public:
    Mage(string n, int l, int h, int intel, string sc)
        : Character(n, l, h), intelligence(intel), spellCasting(sc) {}

    void display() override {
        Character::display();
        cout << "Intelligence: " << intelligence << "\nSpell Casting: " << spellCasting << endl;
    }

    void ability() override {
        cout << name << " uses FIREBALL! " << endl;
    }
};

// Archer
class Archer : virtual public Character {
protected:
    int dexterity;
    string rangedWeapon;
public:
    Archer(string n, int l, int h, int dex, string rw)
        : Character(n, l, h), dexterity(dex), rangedWeapon(rw) {}

    void display() override {
        Character::display();
        cout << "Dexterity: " << dexterity << "\nRanged Weapon: " << rangedWeapon << endl;
    }

    void ability() override {
        cout << name << " uses RAPID SHOT! " << endl;
    }
};

// NPC
class NPC : public Character {
private:
    string movementPattern, dialogue;
public:
    NPC(string n, int l, int h, string mp, string d)
        : Character(n, l, h), movementPattern(mp), dialogue(d) {}

    void display() override {
        Character::display();
        cout << "Movement Pattern: " << movementPattern << "\nDialogue: " << dialogue << endl;
    }

    void ability() override {
        cout << name << " follows scripted behavior!" << endl;
    }
};

// Mighty - multiple inheritance (Warrior + Mage) - diamond problem!
class Mighty : public Warrior, public Mage {
public:
    Mighty(string n, int l, int h, int s, string mw, int intel, string sc)
        : Character(n, l, h),
          Warrior(n, l, h, s, mw),
          Mage(n, l, h, intel, sc) {}

    void display() override {
        Character::display();
        cout << "Strength: " << strength << "\nMelee Weapon: " << meleeWeapon
             << "\nIntelligence: " << intelligence << "\nSpell Casting: " << spellCasting << endl;
    }

    void ability() override {
        Warrior::ability();
        Mage::ability();
    }
};

int main() {
    cout << "===== Warrior =====" << endl;
    Warrior w("Thor", 10, 100, 85, "Sword");
    w.display();
    w.ability();

    cout << "\n===== Mage =====" << endl;
    Mage m("Gandalf", 15, 80, 95, "Fire Magic");
    m.display();
    m.ability();

    cout << "\n===== Archer =====" << endl;
    Archer a("Legolas", 12, 90, 88, "Longbow");
    a.display();
    a.ability();

    cout << "\n===== NPC =====" << endl;
    NPC npc("Village Elder", 1, 50, "Patrol", "Welcome traveler!");
    npc.display();
    npc.ability();

    cout << "\n===== Mighty =====" << endl;
    Mighty mighty("Merlin", 20, 150, 90, "Battle Axe", 98, "Lightning Magic");
    mighty.display();
    mighty.ability();

    return 0;
}