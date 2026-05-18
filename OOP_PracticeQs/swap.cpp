#include<iostream>
using namespace std;
template <typename T>
void mySwap(T& a, T& b) {
    auto temp = a;
    a = b;
    b = temp;
}

int main(){
    int a,b;
    float x,y;
    cout<<"Enter a(integer)= ";
    cin>>a;
    cout<<"Enter b(integer)= ";
    cin>>b;
    cout<<"Before swapping: a = "<<a<<" ,b = "<<b<<endl;
    mySwap(a,b);
    cout<<"After swapping: a = "<<a<<" ,b = "<<b<<endl;
    cout<<"Enter x(float)= ";
    cin>>x;
    cout<<"Enter y(integer)= ";
    cin>>y;
    cout<<"Before swapping: x = "<<x<<" ,y = "<<y<<endl;
    mySwap(x,y);
    cout<<"After swapping: x = "<<x<<" ,y = "<<y<<endl;
    return 0;
}