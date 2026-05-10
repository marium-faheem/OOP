#include <iostream>
using namespace std;

// Class template
template <class T, class U>
class Calculator {
private:
    T num1;
    U num2;

public:
    Calculator(T a, U b) {
        num1 = a;
        num2 = b;
    }

    void add() {
        cout << "Addition = " << (num1 + num2) << endl;
    }

    void subtract() {
        cout << "Subtraction = " << (num1 - num2) << endl;
    }

    void multiply() {
        cout << "Multiplication = " << (num1 * num2) << endl;
    }

    void divide() {
        if (num2 != 0)
            cout << "Division = " << (num1 / num2) << endl;
        else
            cout << "Division by zero is not allowed!" << endl;
    }
};

int main() {
    // Same datatype example
    Calculator<int, int> c1(10, 5);
    cout << "Using int, int:" << endl;
    c1.add();
    c1.subtract();
    c1.multiply();
    c1.divide();

    cout << endl;

    // Different datatype example
    Calculator<int, float> c2(10, 2.5);
    cout << "Using int, float:" << endl;
    c2.add();
    c2.subtract();
    c2.multiply();
    c2.divide();

    return 0;
}