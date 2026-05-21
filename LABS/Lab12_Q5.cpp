#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    // Create a text file
    ofstream outfile("STORY.txt");
    outfile << "The rose is red.\n";
    outfile << "A girl is playing there.\n";
    outfile << "There is a playground.\n";
    outfile << "An airplane is in the sky.\n";
    outfile << "Numbers are not allowed in password.\n";
    outfile.close();
    
    // Count lines NOT starting with 'A'
    ifstream infile("STORY.txt");
    string line;
    int count = 0;
    
    while(getline(infile, line)){
        if(line[0] != 'A' && line[0] != 'a'){  // NOT starting with A or a
            count++;
        }
    }
    infile.close();
    
    cout << "Lines NOT starting with 'A': " << count << "\n";
    
    return 0;
}