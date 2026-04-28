#include<iostream>
using namespace std;
void checkAge(int age){
    if(age<18) {
        throw string("Too Young");
    }
}
int main(){
    try{
        checkAge(15);
    }
    catch(string e){
        cout<<e;
    }
}