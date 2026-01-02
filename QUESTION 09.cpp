#include <iostream>
#include <fstream>
using namespace std;

class Resume {
    string name, email, summary;
    int years;

public:
    void input() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Years of Experience: ";
        cin >> years;
        cin.ignore();
        cout << "Enter Summary: ";
        getline(cin, summary);
    }

    void writeToFile() {
        ofstream fout("resume.txt", ios::trunc);
        fout << "Name: " << name << endl;
        fout << "Email: " << email << endl;
        fout << "Experience: " << years << " years" << endl;
        fout << "Summary: " << summary << endl;
        fout.close();
    }

    void readAndDisplay() {
        ifstream fin("resume.txt");
        string line;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    }
};

int main() {
    Resume r;
    r.input();
    r.writeToFile();
    cout << "\nResume Content:\n";
    r.readAndDisplay();
}

