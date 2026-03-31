#include <iostream>
using namespace std;
class Complex {
private:
double real;
double imag;
public:
// Constructor
Complex(double r = 0, double i = 0) {
real = r;
imag = i;
}
// Overloading + operator
Complex operator + (Complex obj) {
Complex temp;
temp.real = real + obj.real;
temp.imag = imag + obj.imag;
return temp;
}
void display() {
cout << real << " + " << imag << "i" << endl;
}
};
int main() {
Complex c1(3, 4), c2(2, 5);
Complex c3 = c1 + c2;
cout << "Result: ";
c3.display();
return 0;
}