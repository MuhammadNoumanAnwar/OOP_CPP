#include <iostream>
using namespace std;

struct Student {
    int student_id;
    char student_name[50];
    double grade;
};

struct School {
    char school_name[50];
    int school_code;
    Student student;
};

int main() {
    School s = { "ABC School", 101, {123, "John Doe", 95.5} };
    cout << sizeof(School) << endl;
    cout << s.school_name << " " << s.school_code << endl;
    cout << s.student.student_id << " " << s.student.student_name << " " << s.student.grade << endl;
}

