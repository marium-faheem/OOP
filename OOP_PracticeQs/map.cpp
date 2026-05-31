#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,float> grades;
    grades["Marium"] = 90;
    grades["Arisha"] = 78;
    grades["Memoona"] = 88;

    cout<<grades["Marium"]<<endl;

    for(auto& pair : grades){
        cout<<pair.first<<" : "<<pair.second<<endl;
    }
    
    return 0;
}