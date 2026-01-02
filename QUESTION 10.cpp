#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int id;
    string name;
    float gpa;

public:
    void input() {
        cout << "Enter ID, Name, GPA: ";
        cin >> id >> name >> gpa;
    }

    void writeToFile(ofstream &fout) {
        fout << id << " " << name << " " << gpa << endl;
    }

    void readFromFile(ifstream &fin) {
        fin >> id >> name >> gpa;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
    }
};

int main() {
    Student s;
    ofstream fout("students.txt", ios::out);

    for (int i = 0; i < 5; i++) {
        s.input();
        s.writeToFile(fout);
    }
    fout.close();

    ofstream fout_append("students.txt", ios::app);
    cout << "Enter Additional Student:\n";
    s.input();
    s.writeToFile(fout_append);
    fout_append.close();

    ifstream fin("students.txt");
    cout << "\nAll Students:\n";
    while (fin.peek() != EOF) {
        s.readFromFile(fin);
        if (fin)
            s.display();
    }
    fin.close();
}

