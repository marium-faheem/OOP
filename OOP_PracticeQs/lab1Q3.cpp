#include<iostream>
using namespace std;
int main(){
	float temp;
	cout<<"Enter temperature (Farenheit):";
	cin>>temp;
	cout<<"Temperature in Celsius:";
	float C = (temp-32)/1.8;
	cout<<C;
}