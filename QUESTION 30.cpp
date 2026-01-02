#include <iostream>
#include <string>
using namespace std;

class bankaccount {
    private:
        const int accountnumber;  
        double balance;
    public:
        double amount;
        bankaccount(int accno) : accountnumber(accno), balance(0) {}  
        int getaccountnumber() const {
            return accountnumber;
        }
        double getbalance() const {
            return balance;
        }
        void setbalance(int balance) {
            this->balance = balance;
        }
        void deposit(double amount) {
            balance += amount;
        }
        void withdraw(double amount) {
            if(amount <= balance) {
                balance -= amount;
            } else {
                cout << "Insufficient balance" << endl;
            }
        }
        void displaybalance() const {
            cout << "Balance: " << balance << endl;
        }
};
int main() {
    bankaccount b1(1000);  
    b1.setbalance(200000);  
    cout << "Account number: " << b1.getaccountnumber() << endl;
    cout << "Deposit" << endl;
    b1.deposit(40000);  
    cout << "Display balance" << endl;
    b1.displaybalance();
    cout << "Withdraw" << endl;
    b1.withdraw(3000);  
    cout << "Display balance" << endl;
    b1.displaybalance();

    return 0;
}
