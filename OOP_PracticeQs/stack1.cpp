#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<float> nums;
    nums.push(3.14);
    nums.push(3.99);
    nums.push(1.23);
    nums.push(6.67);

    while(!nums.empty()){
        cout<<nums.top()<<endl;
        nums.pop();
    }
    return 0;
}