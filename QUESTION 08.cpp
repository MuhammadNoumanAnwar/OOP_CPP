#include <iostream>
#include <fstream>
using namespace std;

class Book {
public:
    void mergeChapters(const string &chapter1, const string &chapter2, const string &bookFile) {
        ifstream fin1(chapter1.c_str());
        ifstream fin2(chapter2.c_str());
        ofstream fout(bookFile.c_str(), ios::app);

        if (!fin1 || !fin2) {
            cout << "One or both chapter files not found!" << endl;
            return;
        }

        string line;
        while (getline(fin1, line)) {
            fout << line << endl;
        }
        fout << endl;
        while (getline(fin2, line)) {
            fout << line << endl;
        }

        fin1.close();
        fin2.close();
        fout.close();
    }

    void display(const string &filename) {
        ifstream fin(filename.c_str());
        if (!fin) {
            cout << "Book file not found!" << endl;
            return;
        }

        string line;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    }
};

int main() {
    ofstream fout1("chapter1.txt");
    fout1 << "This is Chapter 1 content.";
    fout1.close();

    ofstream fout2("chapter2.txt");
    fout2 << "This is Chapter 2 content.";
    fout2.close();

    Book b;
    b.mergeChapters("chapter1.txt", "chapter2.txt", "book.txt");

    cout << "\nBook Content:\n";
    b.display("book.txt");
}

