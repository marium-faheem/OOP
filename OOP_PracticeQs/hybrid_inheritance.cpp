#include <iostream>
using namespace std;

class A {
public:
    void showA() {
        cout << "Class A" << endl;
    }
};

class B : public A {
};

class C {
public:
    void showC() {
        cout << "Class C" << endl;
    }
};

class D : public B, public C {
};

int main() {
    D obj;
    obj.showA();
    obj.showC();
    return 0;
}
