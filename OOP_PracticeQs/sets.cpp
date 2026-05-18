#include<iostream>
#include<set>
using namespace std;
int main(){
    set<string> guests;
    string names;
    while(names != "stop"){
        cout<<"Enter guests names(or 'stop' to finish): ";
        cin>>names;
        if(names != "stop"){
        guests.insert(names);
        }
    }
    cout<<"==== Guests list ====="<<endl;
    for(string name : guests){     
    cout << name << "\n"; 
    }
    cout<<"Total count: "<<guests.size();
    return 0;
}