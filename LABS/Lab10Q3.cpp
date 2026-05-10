#include <iostream>
using namespace std;

// General Template Class
template <class T>
class mycontainer {
private:
    T element;

public:
    // Constructor
    mycontainer(T arg) {
        element = arg;
    }

    // Function to increase value
    T increase() {
        return ++element;
    }
};

// Template Specialization for char
template <>
class mycontainer<char> {
private:
    char element;

public:
    // Constructor
    mycontainer(char arg) {
        element = arg;
    }

    // Function to convert into uppercase
    char uppercase() {

        if (element >= 'a' && element <= 'z')
            element = element - 32;

        return element;
    }
};

int main() {

    // Integer Object
    mycontainer<int> obj1(10);

    cout << "Integer value after increase: ";
    cout << obj1.increase() << endl;

    // Float Object
    mycontainer<float> obj2(5.5);

    cout << "Float value after increase: ";
    cout << obj2.increase() << endl;

    // Character Object
    mycontainer<char> obj3('m');

    cout << "Uppercase Character: ";
    cout << obj3.uppercase() << endl;

    return 0;
}