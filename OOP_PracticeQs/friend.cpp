#include<iostream>
using namespace std;
class Circle; 
class Rectangle{
    private:
    int area;
    public:
    Rectangle(int a):area(a){}
    friend void CompareArea(Rectangle r, Circle c);
};
class Circle{
    private:
    int area;
    public:
    Circle(int a):area(a){}
    friend void CompareArea(Rectangle r, Circle c);
};
void CompareArea(Rectangle r, Circle c){
    if(r.area>c.area) cout<<r.area;
    else cout<<c.area;
}
int main(){
    Rectangle r(50);
    Circle c(78);
    CompareArea(r,c);
    return 0;
}