#include<iostream>
#include<set>
using namespace std;
int main(){
    set<string> guests;
    string names;
    while(names != "stop"){
      cout<<"Enter guests names: ";
      cin>>names;

      if(names!="stop"){
        guests.insert(names);
      }
    }
    for(string name : guests){     
    cout << name <<endl; 
    }
    cout<<"Total count: "<<guests.size();
    return 0;
}
