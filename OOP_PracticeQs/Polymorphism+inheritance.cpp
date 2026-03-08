#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

// Derived class
class Rectangle : public Shape {
public:
    void draw() {
        cout << "Drawing a Rectangle" << endl;
    }
};

// Another derived class
class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a Circle" << endl;
    }
};

// Multilevel inheritance
class ColoredCircle : public Circle {
public:
    void draw() {
        cout << "Drawing a Colored Circle" << endl;
    }
};

int main() {

    Shape* s;

    Rectangle r;
    Circle c;
    ColoredCircle cc;

    s = &r;
    s->draw();

    s = &c;
    s->draw();

    s = &cc;
    s->draw();

    return 0;
}