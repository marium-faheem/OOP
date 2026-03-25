#include<iostream>
using namespace std;
class DynamicArray {
    int* arr;
    int size;
public:
    // Constructor — allocates memory
    DynamicArray(int s) {
        size = s;
        arr = new int[size];  // heap memory
    }

    // Fill array
    void setValues() {
        for (int i = 1; i <= size; i++)
            arr[i] = i * 10;
    }

    // Print array
    void display() const {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
            cout<<endl;
    }

    // Destructor — frees memory
    ~DynamicArray() {
        delete[] arr;  // MUST free heap memory
    }
};
int main(){
    DynamicArray a(5);
    a.setValues();
    a.display();
    DynamicArray b(10);
    b.setValues();
    b.display();
}