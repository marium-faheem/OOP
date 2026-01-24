#include <iostream>
using namespace std;
class BankAccount{
    private:
        float balance;
    public: 
    BankAccount(){
            balance=0;
        }
    void deposit(float ammount){
        balance+=ammount;
    }
    void withdraw(float ammount){
        if (balance>=ammount) balance-=ammount;
        else cout<<"Withdrawal unsuccessful!\nInsufficient balance.";
    }
    void display(){
        cout<<"Balance: "<<balance<<endl;
    }
};
int main(){
    int choice;
    float m;
    BankAccount acc;
    cout<<"Welcome to abc banking system!\n";
    cout<<"Press (1.Deposit 2.Withdraw): ";
    cin>>acc.choice;
    if(acc.choice==1){
        cout<<"Enter ammount to Deposit: ";
        cin>>acc.m;
        acc.deposit(acc.m);
    }
    else if(acc.choice==2){
        cout<<"Enter ammount to Withdraw: ";
        cin>>acc.m;
        acc.withdraw(acc.m);
    }
    else{
        cout<<"Invalid Choice.";
    }
    acc.display();
    return 0;
}