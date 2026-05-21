#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;

    int length = s.length();
    cout<<"Length of string: "<<length<<endl;

    ofstream outFile("filing.txt");
    outFile<<s;
    outFile.close();

    ifstream inFile("filing.txt");
    while(getline(inFile, s)){
        cout<<"Read from file: "<<s<<endl;
    }
    inFile.close();
    
    return 0;
}