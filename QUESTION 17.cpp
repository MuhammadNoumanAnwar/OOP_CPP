#include<iostream>
using namespace std;
class BankAccount{
    private:
        double balance;
    public:
        BankAccount(double b){
            balance=b;
        }
        void displayBalance(){
            cout<<"Current Balance: "<<balance<<endl;
        }
        friend double checkLoanEligibility(BankAccount acc, double loanAmount);
};
double checkLoanEligibility(BankAccount acc, double loanAmount){
    if(acc.balance<(0.3*loanAmount)){
        return true;
    }
    return false;
}
int main(){
    BankAccount acc(5000);
    acc.displayBalance();
    double loanAmount=12000;
    if(checkLoanEligibility(acc,loanAmount)){
        cout<<"User is eligible for the loan"<<endl;
    }
    else{
        cout<<"User is not eligible for the loan."<<endl;
    }
    return 0;
}