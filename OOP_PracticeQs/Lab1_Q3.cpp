#include"TempConversion.h"
int main(){
    float temp;
    cout<<"Enter temperature (Farenheit):";
    cin>>temp;
    cout<<"Temperature in Celsius:";
    float C = conversion(temp);
    cout<<C;
    return 0;
}