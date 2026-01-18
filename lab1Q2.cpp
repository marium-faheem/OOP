#include<iostream>
using namespace std;
int main(){
	int a=5,b=10,c=15;
	int *ptra=&a;
	int *ptrb=&b;
	int *ptrc=&c;
	cout<<"Values before swapping:";
	cout<<"\na="<<a;
	cout<<"\nb="<<b;
	cout<<"\nc="<<c;
	int temp ;
	temp = *ptra;
	*ptra = *ptrb;
	*ptrb = *ptrc;
	*ptrc = temp;
	cout<<"\nValues after swapping:";
	cout<<"\na="<<a;
	cout<<"\nb="<<b;
	cout<<"\nc="<<c;
    return 0;
}