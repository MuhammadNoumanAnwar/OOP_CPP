#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int ID;
    double salary;

public:
    Employee(string name, int ID, double salary)
    {
        cout << "Parameterized constructor" << endl;
        this->name = name;
        this->ID = ID;
        this->salary = salary;
    }
    Employee &increaseSalary(double amount)
    {
        this->salary += amount;
        return *this;
    }
    void displayDetails() const
    {
        cout << "Employee Name: " << name << "\nID: " << ID << "\nSalary: " << salary << endl;
    }
};
int main()
{

    Employee emp1("Usman", 101, 50000);
    emp1.displayDetails();
    cout << "\nIncreasing salary..." << endl;
    emp1.increaseSalary(5000).increaseSalary(3000);
    emp1.displayDetails();

    return 0;
}
