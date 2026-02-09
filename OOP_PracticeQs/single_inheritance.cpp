#include<iostream>
using namespace std;
class base{
    public:
    int x;
    void getData(){
        cout<<"Enter value of x = ";
        cin>>x;
    }
};
class derive : public base {
    private:
    int y;
    public:
    void readData(){
        cout<<"Enter value of y = ";
        cin>>y;
    }
    void product(){
        cout<<"Product = "<<x*y;
    }
};
int main(){
    derive a;
    a.getData();
    a.readData();
    a.product();
    return 0;
}