#include "Member.h"
#include <iostream>
using namespace std;

Member::Member(string name, int id) : name(name), memberID(id) {}

string Member::getName() const {
    return name;
}

int Member::getID() const {
    return memberID;
}

class Student : public Member {
public:
    Student(string name, int id) : Member(name, id) {}

    int maxBooksAllowed() const override {
        return 5;
    }

    int borrowingDaysLimit() const override {
        return 14;
    }
};

class Faculty : public Member {
public:
    Faculty(string name, int id) : Member(name, id) {}

    int maxBooksAllowed() const override {
        return 10;
    }

    int borrowingDaysLimit() const override {
        return 30;
    }
};

class Guest : public Member {
public:
    Guest(string name, int id) : Member(name, id) {}

    int maxBooksAllowed() const override {
        return 2;
    }

    int borrowingDaysLimit() const override {
        return 7;
    }
};

int main() {
    Student student("Areeb", 2502);
    Faculty faculty("Ms Alishba", 3502);
    Guest guest("Ali", 4502);

    cout << "Student: " << student.getName() << ", ID: " << student.getID() << ", Max Books: " << student.maxBooksAllowed() << ", Borrowing Days: " << student.borrowingDaysLimit() << endl;
    cout << "Faculty: " << faculty.getName() << ", ID: " << faculty.getID() << ", Max Books: " << faculty.maxBooksAllowed() << ", Borrowing Days: " << faculty.borrowingDaysLimit() << endl;
    cout << "Guest: " << guest.getName() << ", ID: " << guest.getID() << ", Max Books: " << guest.maxBooksAllowed() << ", Borrowing Days: " << guest.borrowingDaysLimit() << endl;

    return 0;
}
