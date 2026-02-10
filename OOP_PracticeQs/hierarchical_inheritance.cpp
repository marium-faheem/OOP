#include <iostream>
using namespace std;

class Shape {
public:
    void display() {
        cout << "This is a shape" << endl;
    }
};

class Rectangle : public Shape {
};

class Circle : public Shape {
};

int main() {
    Rectangle r;
    Circle c;

    r.display();
    c.display();

    return 0;
}
