#include<iostream>
#include<fstream>
using namespace std;

class Participant{
public:
    int id;
    string name;
    int score;
    
    void addToFile(int i, string n, int s){
        ofstream file("participant.txt", ios::app);
        file << i << " " << n << " " << s << "\n";
        file.close();
        cout << "Added!\n";
    }
    
    void findByID(int searchID){
        ifstream file("participant.txt");
        int id;
        string name;
        int score;
        
        while(file >> id >> name >> score){
            if(id == searchID){
                cout << id << " " << name << " " << score << "\n";
                return;
            }
        }
        file.close();
    }
    
    void maxScore(){
        ifstream file("participant.txt");
        int id, maxScore = 0;
        string name, topName = "";
        int score;
        
        while(file >> id >> name >> score){
            if(score > maxScore){
                maxScore = score;
                topName = name;
            }
        }
        cout << "Highest: " << topName << " with " << maxScore << "\n";
        file.close();
    }
};

int main(){
    Participant p;
    
    p.addToFile(1, "Marium", 85);
    p.addToFile(2, "Zaid", 90);
    p.addToFile(3, "Memoona", 78);
    
    p.findByID(2);
    p.maxScore();
    
    return 0;
}