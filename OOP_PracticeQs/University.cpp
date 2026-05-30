#include<iostream>
using namespace std;

class UniversityPerson{
    protected:
    int personID;
    string personName;
    int baseSalary;

    public:
    UniversityPerson(int id, string name, int sal):personID(id),personName(name),baseSalary(sal){}
    virtual void showDetails() = 0;
    virtual int computePay() { return baseSalary; }
    friend int operator+(UniversityPerson& a, UniversityPerson& b); //[DECIDE 1]declaring operator+ as friend function because both operands are symmetric
    //returning an integer because we can't return an object because it can't be created at first place since its a base class
    virtual ~UniversityPerson(){} //[DECIDE 2] virtual destructor because we have to free memory using this base class' pointer 
};

int operator+(UniversityPerson& a, UniversityPerson& b){
    return a.computePay() + b.computePay(); 
} 

class FullTimeProfessor: virtual public UniversityPerson{
    protected:
    string department;
    int researchGrant;
    int yearsOfService;

    public:
    FullTimeProfessor(int id, string name, int sal, string depart, int grant, int yos):UniversityPerson(id,name,sal),department(depart),researchGrant(grant),yearsOfService(yos){}
    void showDetails() override {
        cout<<"===Full Time Professor==="<<endl;
        cout<<"Person Name: "<<personName<<endl;
        cout<<"Person ID: "<<personID<<endl;
        cout<<"Base Salary: "<<baseSalary<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<"Research Grant: "<<researchGrant<<endl;
        cout<<"Years of Service: "<<yearsOfService<<endl;
    }
    int computePay() override { return (baseSalary + researchGrant); }
    virtual ~FullTimeProfessor(){}
};

class VisitingLecturer: virtual public UniversityPerson{
    protected:
    int lectureCount;
    int ratePerLecture;

    public:
    VisitingLecturer(int id, string name, int sal, int count, int rate):UniversityPerson(id,name,sal),lectureCount(count),ratePerLecture(rate){}
    void showDetails() override {
        cout<<"===Visiting Lecturer==="<<endl;
        cout<<"Person Name: "<<personName<<endl;
        cout<<"Person ID: "<<personID<<endl;
        cout<<"Base Salary: "<<baseSalary<<endl;
        cout<<"Lecture Count: "<<lectureCount<<endl;
        cout<<"Rate per Lecture: "<<ratePerLecture<<endl;
    }
    int computePay() override { return (lectureCount * ratePerLecture); }
    virtual ~VisitingLecturer(){}
};
//[DECIDE 3] Public access speicifier is used while inheriting to maintain IS-A relationship with base class
//Full Time Professor IS-A University Person
//Visiting Lecturer IS-A University Person

class DepartmentHead: public FullTimeProfessor, public VisitingLecturer{
    protected:
    int administrativeAllowance;

    public:
    DepartmentHead(int id, string name, int sal, string depart, int grant, int yos, int count, int rate, int allowance):
    UniversityPerson(id,name,sal),
    FullTimeProfessor(id,name,sal,depart,grant,yos),
    VisitingLecturer(id,name,sal,count,rate),
    administrativeAllowance(allowance){}

    void showDetails() override {
        cout<<"===Department Head==="<<endl;
        FullTimeProfessor::showDetails();
        VisitingLecturer::showDetails();
        cout<<"Administrative Allowance: "<<administrativeAllowance<<endl;
    }
    int computePay() override { 
        return (FullTimeProfessor::computePay() +
        VisitingLecturer::computePay() + administrativeAllowance);
    }
    virtual ~DepartmentHead(){}
    //[DECIDE 4] Virtual inheritance is used in this class because of diamond problem as it is inheriting from 2 classes who's inheriting from the same base class
};

int main(){
    UniversityPerson* persons[3];
    persons[0] = new FullTimeProfessor(1,"Imran",80000,"CS",50000,5);
    persons[1] = new VisitingLecturer(2,"Mehwish",60000,20,10000);
    persons[2] = new DepartmentHead(3,"Maaz",92000,"Electronics",40000,9,12,8000,14000);

    for (int i = 0; i < 3; i++)
    {
        persons[i]->showDetails(); //[DECIDE 5] run-time polymorphism as it decide during run time which specific class' function to call by checking which class is assigned to persons pointer
        cout<<persons[i]->computePay();
    }

    int total = *persons[1] + *persons[2];
    cout<<"Total pay of ID:1 & ID:2 = "<<total<<endl;

    for (int i = 0; i < 3; i++)
    {
        delete persons[i];
    }
    
    return 0;
}