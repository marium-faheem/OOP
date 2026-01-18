#include<iostream>
using namespace std;
class Teacher {
    public:
    string name;
    string dept;
    string subj;
    double salary;

    void changeDept(string newDept) {
        dept = newDept;
    }
};
class Student {
    public:
    string name;
    int rollNo;
    string course;
    double fees;

    void changeCourse(string newCourse) {
        course = newCourse;
    }
};
int main(){
    Teacher t1;
    t1.name = "Alice";
    t1.dept = "Mathematics";
    t1.subj = "Algebra";
    t1.salary = 50000;
    cout << "Teacher 1 Details:" << endl;
    cout << "Name: " << t1.name << endl;
    cout << "Department: " << t1.dept << endl;
    cout << "Subject: " << t1.subj << endl;
    cout << "Salary: " << t1.salary << endl;
    t1.changeDept("Physics");
    cout << "Updated Department: " << t1.dept << endl;
    Teacher t2;
    t2.name = "Macy";
    t2.dept = "Chemistry";
    t2.subj = "Organic Chemistry";
    t2.salary = 55000;
    cout << "\nTeacher 2 Details:" << endl;
    cout << "Name: " << t2.name << endl;
    cout << "Department: " << t2.dept << endl;
    cout << "Subject: " << t2.subj << endl;
    cout << "Salary: " << t2.salary << endl;
    Student s1;
    s1.name = "Marium";
    s1.rollNo = 168;
    s1.course = "Computer Science";
    s1.fees = 30000;
    cout << "\nStudent 1 Details:" << endl;
    cout << "Name: " << s1.name << endl;
    cout << "Roll No: " << s1.rollNo << endl;
    cout << "Course: " << s1.course << endl;
    cout << "Fees: " << s1.fees << endl;
    s1.changeCourse("Information Technology");
    cout << "Updated Course: " << s1.course << endl;
    Student s2;
    s2.name = "Memoona";
    s2.rollNo = 166;
    s2.course = "Software Engineering";
    s2.fees = 32000;
    cout << "\nStudent 2 Details:" << endl;
    cout << "Name: " << s2.name << endl;
    cout << "Roll No: " << s2.rollNo << endl;
    cout << "Course: " << s2.course << endl;
    cout << "Fees: " << s2.fees << endl;
    return 0;
}