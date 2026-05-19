#include<iostream>
#include<map>
using namespace std;

class GradeManager{
    private:
    map<string,int> grades;
    public:
    void addStudent(string name, int grade){
        grades[name] = grade;
    }
    void displayAll(){
        for (auto& p : grades){
            cout<<p.first<<": "<<p.second<<endl;
        }
    }
    void retrieve(string name){
        if(grades.find(name)!= grades.end()){
            cout<<grades[name];
        }
    }
    void remove(string name){
        grades.erase(name);
    }
    void modify(string name, int grade){
        grades[name] = grade;
    }
};
int main(){
    GradeManager m;
    m.addStudent("Marium",85);
    m.addStudent("Memoona",90);
    m.addStudent("Zaid",75);
    m.displayAll();
    m.remove("Zaid");
    m.displayAll();
}