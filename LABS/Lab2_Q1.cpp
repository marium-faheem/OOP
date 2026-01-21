#include<iostream>
using namespace std;
class Student{
    public:
        string name;
        int roll_no;
        int semester;
        char section;
        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Roll No: "<<roll_no<<endl;
            cout<<"Semester: "<<semester<<endl;
            cout<<"Section: "<<section<<endl;
            cout<<"---------------------"<<endl;
}
};
int main(){
    Student s1 = {"Ali",101,1,'A'};
    Student s2 = {"Sara",102,1,'B'};
    Student s3 = {"Ahmed",103,2,'A'};
    Student s4 = {"Zainab",104,2,'C'};
    cout<<"Students belonging to Section A:\n";
    cout<<"---------------------"<<endl;
    if(s1.section == 'A'){
        s1.display();
    }
    if(s2.section == 'A'){
        s2.display();
    }
    if(s3.section == 'A'){
        s3.display();
    }
    if(s4.section == 'A'){
        s4.display();
    }
    return 0;
}