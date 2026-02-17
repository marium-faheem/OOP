#include<iostream>
using namespace std;
class Calculator {
    public:
    double add(double a, double b) {
        return a + b;
    }
    double subtract(double a, double b) {
        return a - b;
    }
    double multiply(double a, double b) {
        return a * b;
    }
    double divide(double a, double b) {
        if(b != 0)
            return a / b;
        else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
};
int main(){
    Calculator calc;
    cout << "Addition: " << calc.add(10, 5) << endl;
    cout << "Subtraction: " << calc.subtract(10, 5) << endl;
    cout << "Multiplication: " << calc.multiply(10, 5) << endl;
    cout << "Division: " << calc.divide(10, 5) << endl;
    return 0;
}