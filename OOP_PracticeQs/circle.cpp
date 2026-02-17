#include <iostream>
using namespace std;

class Circle {
public:
    int radius;

    Circle() {
        radius = 7;
    }

    int area() {
        return 3.14 * radius * radius;
    }
};

int main() {
    Circle c;
    cout << "Area: " << c.area();
    return 0;
}
