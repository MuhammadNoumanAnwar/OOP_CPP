#include <iostream>
using namespace std;

class Student
{
public:
    int rollNumber;
    string name;
    float marks;

    void input()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << "Roll No: " << rollNumber << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

class Course
{
public:
    string courseName;
    Student students[5];

    void inputStudents()
    {
        cout << "Enter Course Name: ";
        cin.ignore();
        getline(cin, courseName);
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter details for Student " << i + 1 << ":\n";
            students[i].input();
        }
    }

    void displayStudents()
    {
        cout << "\nCourse: " << courseName << "\nStudents:\n";
        for (int i = 0; i < 5; i++)
        {
            students[i].display();
        }
    }

    float calculateAverageMarks()
    {
        float total = 0;
        for (int i = 0; i < 5; i++)
        {
            total += students[i].marks;
        }
        return total / 5;
    }

    void findTopStudent()
    {
        Student *topStudent = &students[0];
        for (int i = 1; i < 5; i++)
        {
            if (students[i].marks > topStudent->marks)
            {
                topStudent = &students[i];
            }
        }
        cout << "Top Student: ";
        topStudent->display();
    }
};

int main()
{
    Course courses[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter details for Course " << i + 1 << ":\n";
        courses[i].inputStudents();
    }

    for (int i = 0; i < 3; i++)
    {
        courses[i].displayStudents();
        cout << "Average Marks: " << courses[i].calculateAverageMarks() << endl;
        courses[i].findTopStudent();
        cout << "--------------------------\n";
    }

    return 0;
}
