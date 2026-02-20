#include<iostream>
using namespace std;
class Number{
    public:
    int value;
    Number(int v){
        value=v;
    }
    Number operator +(Number n){
        return Number(value + n.value);
    }
    void show(){
        cout<<value<<endl;
    }
};
int main(){
    Number a(5),b(3);
    Number sum = a + b;
    cout<<"Sum : ";
    sum.show();
    return 0;
}