#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string name;
    float cgpa;

public:
    static int studentCount;

    // Default constructor
    Student() {
        id = 0;
        name = "Not Assigned";
        cgpa = 0.0;
        studentCount++;
    }

    // Parameterized constructor
    Student(int i, string n, float c) {
        id = i;
        name = n;
        cgpa = c;
        studentCount++;
    }

    // Copy constructor
    Student(const Student &obj) {
        id = obj.id;
        name = obj.name;
        cgpa = obj.cgpa;
        studentCount++;
    }

    // Setter
    void setCGPA(float c) {
        cgpa = c;
    }

    // Getter
    float getCGPA() const {
        return cgpa;
    }

    // Display function
    void display() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "------------------" << endl;
    }

    // Static function
    static int getStudentCount() {
        return studentCount;
    }
};

// Initialize static member
int Student::studentCount = 0;

int main() {
    Student s1;
    Student s2(101, "Marium", 3.7);
    Student s3 = s2;   // Copy constructor

    s1.display();
    s2.display();
    s3.display();

    cout << "Total Students: " << Student::getStudentCount() << endl;

    return 0;
}
