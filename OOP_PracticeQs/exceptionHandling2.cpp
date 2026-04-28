#include<iostream>
using namespace std;
class BankAccount{
    private:
    int balance;
    public:
    BankAccount(int b):balance(b){}
    void withdraw(int amount){
        if(amount>balance)
        throw string("Insufficient Funds!");
        balance-=amount;
    }
    void showBalance(){
        cout<<"Current Balance: "<<balance;
    }
};
int main(){
    BankAccount marium(5000);
    try {
        marium.withdraw(10000);
    }
    catch(string e){
        cout<<"Error: "<<e;
    }
    marium.showBalance();
    return 0;
}