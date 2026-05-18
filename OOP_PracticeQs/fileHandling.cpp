#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    
    //writing to a file
    ofstream outFile("fileHandling.txt");
    outFile << s;
    outFile.close();
    
    //reading from a file
    ifstream inFile("fileHandling.txt");
    while(getline(inFile, s)){
        cout<<s<<endl;
    }
    inFile.close();

    int length = s.length();  // Get string length
    cout << "Length of string: " << length <<endl;
    return 0;
}