#include <iostream>
using namespace std;

// Template function for swapping
template <class T, class U>
void swapData(T &a, U &b) {
    auto temp = a;
    a = b;
    b = temp;
}

int main() {

    // Same datatype
    int x = 10, y = 20;

    cout << "Before Swapping (int): " << endl;
    cout << "x = " << x << " y = " << y << endl;

    swapData(x, y);

    cout << "After Swapping (int): " << endl;
    cout << "x = " << x << " y = " << y << endl;

    cout << endl;

    // Different datatype
    int a = 5;
    float b = 7.5;

    cout << "Before Swapping (int, float): " << endl;
    cout << "a = " << a << " b = " << b << endl;

    swapData(a, b);

    cout << "After Swapping (int, float): " << endl;
    cout << "a = " << a << " b = " << b << endl;

    return 0;
}