#include <iostream>
#include <fstream>
using namespace std;

class Replacer {
public:
    void searchAndReplace(const string &filename, const string &searchWord, const string &replaceWord) {
        fstream file(filename.c_str(), ios::in | ios::out);
        if (!file) {
            cout << "File not found!" << endl;
            return;
        }

        string content;
        char ch;
        while (file.get(ch)) {
            content += ch;
        }

        file.clear();
        file.seekg(0, ios::beg);

        size_t pos = 0;
        while ((pos = content.find(searchWord, pos)) != string::npos) {
            file.seekp(pos, ios::beg);
            file.write(replaceWord.c_str(), replaceWord.length());
            if (replaceWord.length() < searchWord.length()) {
                for (size_t i = replaceWord.length(); i < searchWord.length(); i++) {
                    file.put(' ');
                }
            }
            pos += searchWord.length();
        }

        file.close();
    }

    void display(const string &filename) {
        ifstream fin(filename.c_str());
        if (!fin) {
            cout << "Cannot open file!" << endl;
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
    
    ofstream fout("data.txt");
    fout << "AI is the future. AI will transform the world. Embrace AI now.";
    fout.close();

    string searchWord, replaceWord;
    cout << "Enter Search Word: ";
    cin >> searchWord;
    cout << "Enter Replacement Word: ";
    cin >> replaceWord;

    Replacer r;
    r.searchAndReplace("data.txt", searchWord, replaceWord);

    cout << "\nUpdated File Content:\n";
    r.display("data.txt");
}

