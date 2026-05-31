#include<iostream>
#include <queue>
using namespace std;

int main(){
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

cout << q.front() << endl;  // 10

cout << q.back() << endl;   // 30

q.pop();

// empty check:
if(q.empty()){
    cout << "queue empty!" << endl;
}

return 0;
}