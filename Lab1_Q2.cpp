#include"Swap.h"
int main(){
    int a=5,b=10,c=15;
    cout<<"Before swapping: \n";
    cout<<"a="<<a<<" b="<<b<<" c="<<c<<"\n";
    swap(a,b,c);
    cout<<"After swapping: \n";
    cout<<"a="<<a<<" b="<<b<<" c="<<c<<"\n";
    return 0;
}