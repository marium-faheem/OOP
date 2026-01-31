#include<iostream>
using namespace std;
class Wall { // declare a class
private:
double length;
public:
// default constructor to initialize variable
Wall() {
length = 5.5;
cout << "Creating a wall." << endl;
cout << "Length = " << length << endl;
}
};
int main() {
Wall wall1;
return 0;
}