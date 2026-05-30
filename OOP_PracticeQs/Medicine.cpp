#include<iostream>
using namespace std;

class Medicine{
    protected:
    string name;
    int price;

    public:
    Medicine(string n, int p): name(n),price(p){}
    virtual void displayDetails() = 0;
    virtual ~Medicine(){}
};

class PrescriptionMedicine: virtual public Medicine{
    protected:
    string doctorName;
    string patientName;
    string prescriptionDate;

    public:
    PrescriptionMedicine(string n, int p, string d, string pn, string date):Medicine(n,p),doctorName(d),patientName(pn),prescriptionDate(date){}
    virtual void displayDetails() override {
        cout<<"Medicine name: "<<name<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Doctor's name: "<<doctorName<<endl;
        cout<<"Patient's name: "<<patientName<<endl;
        cout<<"Prescription date: "<<prescriptionDate<<endl;
    }
    virtual ~PrescriptionMedicine(){}

};

class OTC_Medicine: virtual public Medicine{
    protected:
    int maxDailyDosage;
    int ageRestriction;

    public:
    OTC_Medicine(string n, int p, int max, int age):Medicine(n,p),maxDailyDosage(max),ageRestriction(age){}
    virtual void displayDetails() override {
        cout<<"Medicine name: "<<name<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Max Daily Dosage: "<<maxDailyDosage<<endl;
        cout<<"Age Restriction: "<<ageRestriction<<endl;
    }
    virtual ~OTC_Medicine(){}

};

class HybridMedicine: public PrescriptionMedicine, public OTC_Medicine{
    public:
    HybridMedicine(string n, int p, string d, string pn, string date, int max, int age):
    Medicine(n,p),PrescriptionMedicine(n,p,d,pn,date),OTC_Medicine(n,p,max,age){}
    virtual void displayDetails() override {
        PrescriptionMedicine::displayDetails();
        OTC_Medicine::displayDetails();
    }
    virtual ~HybridMedicine(){}

};


int main(){
    Medicine* medicines[3];
    medicines[0] = new PrescriptionMedicine("Regix",50,"Dr Kaydee","Marium","29-05-2026");
    medicines[1] = new OTC_Medicine("Risek",30,3,14);
    medicines[2] = new HybridMedicine("No-spa",80,"Dr Amna","Seema","02-05-2026",2,16);

    for (int i = 0; i < 3; i++)
    {
        medicines[i]->displayDetails();
    }
    for (int i = 0; i < 3; i++)
    {
        delete medicines[i];
    }

    return 0;
}