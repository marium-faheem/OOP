#include<iostream>
using namespace std;
int main() {
    int x = 10;

    const int* const ptr = &x;

    // *ptr = 20; ❌
    // ptr = &x;  ❌

    cout << *ptr;
    return 0;
}
