#include<iostream>
using namespace std;
class Print{
    public:
    void show(int x){
        cout<<"Integer: "<<x<<endl;
    }
    void show(float x){
        cout<<"Float: "<<x<<endl;
    }
};
int main(){
    Print p;
    p.show(10);
    p.show(3.5f);
    return 0;
}