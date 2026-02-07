#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 20;

    const int* ptr = &x;   // data is const

    // *ptr = 15;  ❌ NOT allowed
    ptr = &y;     // ✅ allowed

    cout << *ptr;
    return 0;
}
