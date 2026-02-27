#include<iostream>
using namespace std;

class Pet {
private:
    string name;
    int age;
public:
    Pet(string name = "", int age = 0) {
        this->name = name;
        this->age = age;
    }
    void eat() {
        cout << "Pet is eating" << endl;
    }
};

class Dog : public Pet {
private:
    string home;
public:
    Dog(string name = "", int age = 0, string home = "")
            : Pet(name, age) {
        this->home = home;
    }
    void eat() {
        cout << "Dog is eating" << endl;
    }
};
int main() {
    
    Pet pet;
    Dog dog;
    pet.eat();
    dog.eat();
    
    return 0;
}