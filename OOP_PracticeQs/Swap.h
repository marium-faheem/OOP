#include<iostream>
using namespace std;
void swap(int &a, int &b, int &c){
    int temp = a;
    a = b;
    b = c;
    c = temp;
    return;
}