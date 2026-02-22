#include <iostream>
#include <string>
using namespace std;
class Athlete {
public:
    string name;
    int age;
    float salary;
    Athlete(string name,int age,float salary){
        this->name = name;
        this->age = age;
        this->salary = salary;
    }
    void print(){
        cout<<name<<" Age: "<<age<<" Salary: $"<<salary;
    }
};
int main(){
    Athlete John("John Cena",48,1000);
    John.print();
    return 0;
}