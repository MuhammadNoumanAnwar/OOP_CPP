#include <iostream>
#include <fstream>
using namespace std;

class FileEditor {
public:
    void createFile() {
        ofstream fout("info.txt", ios::out);
        fout << "C++ is a powerful programming language.";
        fout.close();
    }

    void editFile() {
        fstream fio("info.txt", ios::in | ios::out);

        cout << "Initial get pointer: " << fio.tellg() << endl;
        cout << "Initial put pointer: " << fio.tellp() << endl;

        fio.seekg(6);
        string word;
        fio >> word;
        cout << "Word at position 6: " << word << endl;

        fio.seekp(6);
        fio << "dynamic";

        cout << "After replacement get pointer: " << fio.tellg() << endl;
        cout << "After replacement put pointer: " << fio.tellp() << endl;

        fio.seekg(0);
        string line;
        getline(fio, line);
        cout << "\nUpdated Content:\n" << line << endl;

        fio.close();
    }
};

int main() {
    FileEditor f;
    f.createFile();
    f.editFile();
}

