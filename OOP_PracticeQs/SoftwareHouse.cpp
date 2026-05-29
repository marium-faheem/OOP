#include<iostream>
using namespace std;

class Worker{
    protected:
    int workerID;
    string workerName;
    int basePay;

    public:
    Worker(int id, string name, int pay): workerID(id), workerName(name), basePay(pay){}
    virtual void showDetails() = 0;
    virtual int computePay (){ return basePay; }
    friend int operator+(Worker& w1, Worker& w2);
    virtual ~Worker(){}
};

int operator+(Worker& w1, Worker& w2){
    return w1.computePay() + w2.computePay();
}

class FullTimeDeveloper : virtual public Worker{
    protected:
    string teamName;
    int performanceBonus;
    int yearsExperience;

    public:
    FullTimeDeveloper(int id, string name, int pay, string team, int bonus, int exp): Worker(id, name, pay), teamName(team), performanceBonus(bonus), yearsExperience(exp){}
    int computePay() override { return basePay + performanceBonus; }
    void showDetails() override {
        cout<<"Team Name: "<<teamName<<endl;
        cout<<"Performance Bonus: "<<performanceBonus<<endl;
        cout<<"Years of Experience: "<<yearsExperience<<endl;
    }
    virtual ~FullTimeDeveloper(){}
};

class FreelanceDeveloper : virtual public Worker{
    protected:
    int projectCount;
    int ratePerProject;

    public:
    FreelanceDeveloper(int id, string name, int pay, int count, int rate): Worker(id, name, pay),projectCount(count),ratePerProject(rate){}
    int computePay() override { return projectCount * ratePerProject; }
    void showDetails() override {
        cout<<"Project Count: "<<projectCount<<endl;
        cout<<"Rate per Project: "<<ratePerProject<<endl;
    }
    virtual ~FreelanceDeveloper(){}
};

class TechnicalLead: public FullTimeDeveloper, public FreelanceDeveloper{
    protected:
    int leaderAllowance;

    public:
    TechnicalLead(int id, string name, int pay, string team, int bonus, int exp, int count, int rate, int allowance):Worker(id,name,pay),FullTimeDeveloper(id,name,pay,team,bonus,exp),FreelanceDeveloper(id,name,pay,count,rate),leaderAllowance(allowance){}
    int computePay() override { 
        return  FullTimeDeveloper::computePay() + FreelanceDeveloper::computePay() + leaderAllowance;
    }
    void showDetails() override {
        FullTimeDeveloper::showDetails();
        FreelanceDeveloper::showDetails();
        cout<<"Leader Allowance: "<<leaderAllowance<<endl;
    }
    virtual ~TechnicalLead(){}

};

int main(){
    Worker* workers[3];
    workers[0] = new FullTimeDeveloper(1,"Marium",50000,"Backend",10000,2);
    workers[1] = new FreelanceDeveloper(2,"Memoona",0,5,12000);
    workers[2] = new TechnicalLead(3,"Amna",60000,"Lead",15000,5,3,10000,20000);
    for (int i = 0; i < 3; i++)
    {
        workers[i] -> showDetails();
        workers[i] -> computePay();
    }
    int total = *workers[0] + *workers[1];
    cout<<"Combined Pay: "<<total<<endl;
    for(int i = 0; i < 3; i++){
        delete workers[i];
    }
    return 0;
}