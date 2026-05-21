#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ofstream createFile("input.txt");
    createFile<<"Hello World!"<<endl;
    createFile<<"This is Marium Faheem"<<endl;
    createFile<<"At your service."<<endl;
    createFile.close();

    ifstream sourceFile("input.txt");

    ofstream destFile("output.txt");

    string line;
    while(getline(sourceFile, line)){
        destFile<<line<<endl;
    }

    sourceFile.close();
    destFile.close();

    cout<<"Copy completed.";
    return 0;
}