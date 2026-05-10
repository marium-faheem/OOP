#include <iostream>
using namespace std;

// Abstract base class
class ArrayMultiplier {
public:
    virtual void calculate() = 0; // Pure virtual function
};

// Derived class for 1D array multiplication
class ArrayMultiplier1D : public ArrayMultiplier {
private:
    int arr[100], size;

public:
    void input() {
        cout << "Enter size of 1D array: ";
        cin >> size;
        cout << "Enter elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void calculate() override {
        int product = 1;
        for (int i = 0; i < size; i++) {
            product *= arr[i];
        }
        cout << "Product of 1D array elements = " << product << endl;
    }
};

// Derived class for 2D array multiplication
class ArrayMultiplier2D : public ArrayMultiplier {
private:
    int arr[10][10], rows, cols;

public:
    void input() {
        cout << "Enter number of rows and columns: ";
        cin >> rows >> cols;
        cout << "Enter elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> arr[i][j];
            }
        }
    }

    void calculate() override {
        int product = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                product *= arr[i][j];
            }
        }
        cout << "Product of 2D array elements = " << product << endl;
    }
};

// Main function
int main() {
    ArrayMultiplier* ptr;

    ArrayMultiplier1D obj1;
    obj1.input();
    ptr = &obj1;
    ptr->calculate();

    ArrayMultiplier2D obj2;
    obj2.input();
    ptr = &obj2;
    ptr->calculate();

    return 0;
}