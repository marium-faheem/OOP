//Ask the user how many students there are. 
//Dynamically allocate an array of that size, take marks as input for each student, print all the marks, then delete the array.
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"How many students?";
    cin>>n;
    int *marks = new int[n];
    for(int i=0; i<n; i++){
        cout<<"Enter marks of student#"<<i+1<<":";
        cin>>marks[i];
    }
    for(int i=1; i<=n; i++){
        cout<<"Marks of student#"<<i<<":";
        cout<<marks[i]<<endl;
    }
    delete[] marks;
    return 0;
}