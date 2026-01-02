//Create a program that simulates an ATM system for five users, each identified by a User ID (0 to 4) with initial
//balances stored in an array {1000, 1500, 2000, 2500, 3000}. Prompt the user to enter a valid User ID and display a
//menu with options to check balance, deposit money, withdraw money, or exit. Based on the choice, perform the
//action: display the balance, update the balance after a deposit, or deduct the amount if a withdrawal is possible
//(otherwise, show an error message for insufficient funds). The menu should continue to appear after each transaction
//until the user selects the exit option, which should terminate the program with a goodbye message. Handle invalid
//User IDs and menu selections with appropriate error messages.
#include <iostream>
using namespace std;
int main() {
    float array[] = {1000, 1500, 2000, 2500, 3000}; 
    int id, choice;
    float amount;
	cout << "1000, 1500, 2000, 2500, 3000" << endl;
    while (1) {
        cout << "Enter user id (0 to 4): " << endl;
        cin >> id;

        if (id >= 0 && id <= 4) {
            cout << "1 Check Balance" << endl 
                 << "2 Deposite Money" << endl 
                 << "3 Withdraw Money" << endl 
                 << "4 Exit" << endl;
            cin >> choice;

            if (choice == 1) {
                cout << "Your Balance: " << array[id] << endl;
            } 
            else if (choice == 2) {
                cout << "Enter Amount to be deposited: ";
                cin >> amount;
                array[id] = array[id] + amount;
                cout << "Amount Added" << endl;
            } 
            else if (choice == 3) {
                cout << "Enter Amount to be Withdrawn: ";
                cin >> amount;
                if (array[id] >= amount) {
                    array[id] = array[id] - amount;
                    cout << "Amount Withdrawn" << endl;
                } else {
                    cout << "Insufficient funds....." << endl;
                }
            } 
            else if (choice == 4) {
                cout << "goodbye...." << endl;
                break;
            } 
            else {
                cout << "Invalid Choice" << endl;
            }
        } 
        else {
            cout << "Invalid User ID" << endl;
        }
    }

    return 0;
}

