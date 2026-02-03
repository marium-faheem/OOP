#include<iostream>
using namespace std;
class Employee{
    int id;
    int count;
    public:
    void setData(void){
        cout<<"Entrer the id: ";
        cin>>id;
    }
    void getData(void){
        cout<<"The id of this employee is "<<id;
    }
};

int main(){
    Employee marium;
    marium.setData();
    marium.getData();

    return 0;
}