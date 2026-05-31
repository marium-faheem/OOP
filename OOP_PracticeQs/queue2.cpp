#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<string> names;
    names.push("Marium");
    names.push("Memoona");
    names.push("Arisha");
    names.push("Afia");
    names.push("Ifrah");
    names.push("Afia");

    while(!names.empty()){
        cout<<names.front()<<endl;
        names.pop();
    }

    return 0;
}