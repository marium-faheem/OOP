#include<iostream>
#include<string>
using namespace std;

class Binary {
    string s;
public:
void read(void){
    cout<<"Enter  binary number:";
    cin>>s;
}
void check(void){
    for(int i=0; i<s.length(); i++){
        if(s.at(i)!='0' && s.at(i)!='1'){
        cout<<"Incorrect binary format"<<endl;
        exit(0);
        }
    }
}
void ones(void){
    cout<<"One's Compliment: ";
    for(int i=0; i<s.length(); i++){
        if(s.at(i)=='0'){
            s.at(i)='1';
        }
        else{
            s.at(i)='0';
        }
    }
}
void display(void){
    for(int i=0; i<s.length(); i++){
        cout<<s.at(i);
    }
}
};
int main(){
    Binary b;
    b.read();
    b.check();
    b.ones();
    b.display();
}