#include<iostream>
using namespace std;
int main() {
    int x = 10;
    int y = 20;

    int* const ptr = &x;   // pointer is const

    *ptr = 15;   // ✅ allowed
    // ptr = &y; ❌ NOT allowed

    cout << *ptr;
    return 0;
}
