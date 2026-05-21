#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Person{
    public:
    string name;
    int age;
    Person(string n, int a):name(n),age(a){}

};

int main(){
    Person person1("Marium",20);

    ofstream outfile("person.bin",ios::binary);
    outfile.write((char*)&person1,sizeof(person1));
    outfile.close();

    ifstream infile("person.bin",ios::binary);
    infile.read((char*)&person1,sizeof(person1));
    infile.close();

    cout<<"Data read from file: "<<endl;
    cout<<"Name: "<<person1.name<<endl;
    cout<<"Age: "<<person1.age<<endl;

    return 0;
}