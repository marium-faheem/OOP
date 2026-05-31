#include<iostream>
#include<set>
using namespace std;
int main(){
    set<string> names;

    names.insert("Marium");
    names.insert("Memoona");
    names.insert("Arisha");
    names.insert("Afia");
    names.insert("Ifrah");
    names.insert("Afia");

    for(auto& x : names){
        cout<<x<<endl;
    }
    
    return 0;
}