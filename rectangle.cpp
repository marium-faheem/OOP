#include <iostream>
using namespace std;

class Rectangle {
public:
    int length, width;

    Rectangle() {
        length = 5;
        width = 3;
    }

    int area() {
        return length * width;
    }
};

int main() {
    Rectangle r;
    cout << "Area: " << r.area();
    return 0;
}
