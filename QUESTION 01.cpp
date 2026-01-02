#include <iostream>
#include <stdexcept>
using namespace std;
class InsufficientFundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Withdrawal failed: Insufficient funds.";
    }
};


template<typename T>
class BankAccount {
private:
    T balance;
public:
    BankAccount(T initialBalance = 0) : balance(initialBalance) {}

    void deposit(T amount) {
        if (amount < 0) {
            cout << "Cannot deposit a negative amount." << endl;
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
    }

    void withdraw(T amount) {
        try {
            if (amount > balance) {
                throw InsufficientFundsException();
            }
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
        }
        catch (const InsufficientFundsException& e) {
            cout << e.what() << endl;
        }
    }

    T getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount<double> account(1000.0);  

    int choice;
    double amount;

    do {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                cout << "Current Balance: " << account.getBalance() << endl;
                break;
            case 4:
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
