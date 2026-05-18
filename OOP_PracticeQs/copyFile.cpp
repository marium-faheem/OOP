#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream createFile("input.txt");
    createFile <<"Hello World"<<endl;
    createFile <<"This is line 2"<<endl;
    createFile <<"Goodbye"<<endl;
    createFile.close();

    ifstream sourceFile("input.txt");

    ofstream destFile("output.txt");

    string line;
    while(getline(sourceFile, line)){
        destFile << line << endl;
    }

    sourceFile.close();
    destFile.close();

    cout<<"Copy Complete"<<endl;

    return 0;
}