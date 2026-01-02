#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;

public:
    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

    virtual void displayInfo() const { cout << "Name: " << name << ", ID: " << id << endl; }
    virtual void updateInfo(string newAddr) { address = newAddr; }
};

class Student : public Person {
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string addr, string phone, string mail, double gpa, int year)
        : Person(n, i, addr, phone, mail), GPA(gpa), enrollmentYear(year) {}

    void displayInfo() const override { cout << "Student: " << name << ", GPA: " << GPA << endl; }
};

class Professor : public Person {
    string department;
    vector<string> coursesTaught;
    double salary;

public:
    Professor(string n, string i, string addr, string phone, string mail, string dept, double sal)
        : Person(n, i, addr, phone, mail), department(dept), salary(sal) {}

    void displayInfo() const override { cout << "Professor: " << name << ", Department: " << department << endl; }
};

class Staff : public Person {
    string department, position;
    double salary;

public:
    Staff(string n, string i, string addr, string phone, string mail, string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override { cout << "Staff: " << name << ", Position: " << position << endl; }
};

class Course {
    string courseId, courseName, instructor;
    int credits;
    vector<Student*> enrolledStudents;

public:
    Course(string id, string name, int cr, string inst)
        : courseId(id), courseName(name), credits(cr), instructor(inst) {}

    void registerStudent(Student* s) { enrolledStudents.push_back(s); }
    void displayCourse() const { cout << "Course: " << courseName << ", Instructor: " << instructor << endl; }
};

int main() {
    Student s("USMAN", "S001", "XYZ Street", "9876543210", "XYZ@mail.com", 3.8, 2022);
    Professor p("NOUMAN", "P001", "XYZ Avenue", "1111119", "XYZ@mail.com", "CS", 85000);
    Staff staff("HAMZA", "ST001", "XYZ Road", "71111118", "XYZ@mail.com", "Admin", "Clerk", 45000);
    
    Course c("CS101", "Data Structures", 3, "HAMZA");
    c.registerStudent(&s);

    s.displayInfo();
    p.displayInfo();
    staff.displayInfo();
    c.displayCourse();

    return 0;
}
