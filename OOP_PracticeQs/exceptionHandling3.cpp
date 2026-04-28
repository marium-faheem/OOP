#include<iostream>
using namespace std;
int divide(int a, int b){
    if(b==0) 
    throw string("Division by zero!");
    else 
    return a/b;
}
int main(){
    try{
        divide(10,0);
    }
    catch(string e){
        cout<<"Error: "<<e;
    }
}