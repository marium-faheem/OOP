#include<iostream>
using namespace std;
template<typename T, typename U>
class Calculator{
    T a;
    T b;
    public:
    Calculator(T x, T y){
        a = x;
        b = y;
    }
    void add(){
        cout<<"Addition : "<<(a+b)<<endl;
    }
    void subtract(){
        cout<<"Subtraction : "<<(a-b)<<endl;
    }
    void multiplication(){
        cout<<"Multiplication : "<<(a*b)<<endl;
    }
    void division(){
        if(b==0) cout<<"Undefined";
        else cout<<"Division : "<<(a/b)<<endl;
    }
};

int main(){
    Calculator<int,int> calc(10,20);
    calc.add();
    calc.subtract();
    calc.multiplication();
    calc.division();
    return 0;
}