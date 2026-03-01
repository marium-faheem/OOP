#include<iostream>
using namespace std;
class Pet {
private:
    string name;
    int age;
public:
    void eat() {
        cout << "Eating";
        cout << endl;
    }
};
class Dog : public Pet {
private:
    string home;
public:
    void bark() {
        cout << "Barking";
        cout << endl;
    }
};
int main() {

    Pet pet;
    Dog dog;
    
    pet.eat();
    dog.eat();
    dog.bark();

    return 0;
}