#include<iostream>
using namespace std;
class Car{
    public:
        string brand;
        string model;
        int year;
        Car(){
            brand = "Ford";
            model = "Mustang";
            year = 2020;
        }
};
int main(){
    Car MyCar;
    cout<<"Brand : "<<MyCar.brand<<endl;
    cout<<"Model : "<<MyCar.model<<endl;
    cout<<"Year : "<<MyCar.year<<endl;
    return 0;
}