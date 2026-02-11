#include <iostream>
using namespace std;

class Print {
public:
    void show(int x) {
        cout << "Integer: " << x << endl;
    }
    void show(double x) {
        cout << "Double: " << x << endl;
    }
    void show(string x) {
        cout << "String: " << x << endl;
    }
};

int main() {
    Print p;
    p.show(10);         // calls show(int)
    p.show(3.14);       // calls show(double)
    p.show("Hello");    // calls show(string)
    return 0;
}
