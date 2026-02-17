#include<iostream>
using namespace std;
class Cricketer{
    public:
       int runs;
       string name;

       Cricketer(string name,int runs){
        this->name = name;  //using this bcz parameter of constructor and class datatypes has same name
        this->runs = runs;
       }
};

int main(){
    Cricketer c1("Babar Azam", 30000);
    Cricketer c2("Rizwan", 20000);

    cout<<c1.name<<" "<<c1.runs<<endl;
    cout<<c2.name<<" "<<c2.runs<<endl;
}  