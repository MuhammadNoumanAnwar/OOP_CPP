#include <iostream>
#include <string>
using namespace std;
class Staff {
protected:
    int id;
public:
    Staff(int i) : id(i) {}
    void displayInfo() { cout << "Staff ID: " << id << endl; }
};
class Doctor : public Staff {
    string specialization;
public:
    Doctor(int i, string spec) : Staff(i), specialization(spec) {}
    void prescribeMedication() { cout << "Doctor prescribing medication.\n"; }
};
class Nurse : public Staff {
public:
    Nurse(int i) : Staff(i) {}
    void assistDoctor() { cout << "Nurse assisting doctor.\n"; }
};
class Admin : public Staff {
public:
    Admin(int i) : Staff(i) {}
    void manageSchedule() { cout << "Admin managing schedule.\n"; }
};
int main() {
    Doctor d(1, "Cardiology");
    Nurse n(2);
    Admin a(3);
    d.displayInfo();
    d.prescribeMedication();
    n.displayInfo();
    n.assistDoctor();
    a.displayInfo();
    a.manageSchedule();
    return 0;
}

