#include <iostream>
using namespace std;
class Person {
public:
int *age;
Person(int a) {
age = new int(a);
}
void ouput(){
    cout<<""<<*age;
}
~Person() {
delete age;
}
};

int main() {
Person p1(30);
Person p2 = p1; // default copy constructor
p2.ouput();
*p2.age = 20;
cout<<endl;
p1.ouput();
return 0;
}