#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int currentSize;   
public:
    DynamicArray(int size) {
        currentSize = size;
        arr = new int[currentSize];

        for (int i = 0; i < currentSize; i++) {
            arr[i] = 0;
        }
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void push(int value) {

        int* newArr = new int[currentSize + 1];

        for (int i = 0; i < currentSize; i++) {
            newArr[i] = arr[i];
        }

        newArr[currentSize] = value;

        delete[] arr;

        arr = newArr;
        currentSize++;
    }
    int size() const {
        return currentSize;
    }

    void display() const {
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    DynamicArray obj(3);

    cout << "Initial array: ";
    obj.display();

    obj.push(10);
    obj.push(20);

    cout << "After pushing values: ";
    obj.display();

    cout << "Size of array: " << obj.size() << endl;

    return 0;
}