#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber, accountHolderName, accountType;
    double balance;

public:
    Account(string accNum, string holder, double bal, string type = "")
        : accountNumber(accNum), accountHolderName(holder), balance(bal), accountType(type) {}

    virtual void deposit(double amount) { balance += amount; }
    virtual bool withdraw(double amount) { 
        if (amount > balance) return false; 
        balance -= amount; 
        return true; 
    }
    virtual double calculateInterest() const { return 0.0; }
    virtual void printStatement() const { cout << "Account: " << accountNumber << ", Balance: " << balance << endl; }
};

class SavingsAccount : public Account {
    double interestRate, minimumBalance;

public:
    SavingsAccount(string accNum, string holder, double bal, double rate, double minBal)
        : Account(accNum, holder, bal, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    double calculateInterest() const override { return balance * interestRate / 100; }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(string accNum, string holder, double bal)
        : Account(accNum, holder, bal, "Checking") {}
};

class FixedDepositAccount : public Account {
    double fixedInterestRate;
    int maturityDate;

public:
    FixedDepositAccount(string accNum, string holder, double bal, double rate, int maturity)
        : Account(accNum, holder, bal, "FixedDeposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    double calculateInterest() const override { return balance * fixedInterestRate / 100; }
};

int main() {
    SavingsAccount sa("12345", "usman", 5000, 5, 1000);
    CheckingAccount ca("67890", "nouman", 3000);
    FixedDepositAccount fda("22442", "hamza", 10000, 7, 5);

    sa.deposit(1000);
    ca.withdraw(500);
    cout << "Savings Interest: " << sa.calculateInterest() << endl;
    cout << "Fixed Deposit Interest: " << fda.calculateInterest() << endl;
    sa.printStatement();
    ca.printStatement();
    fda.printStatement();

    return 0;
}
