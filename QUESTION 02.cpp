#include <iostream>
#include <fstream>
#include <exception>
#include <string>
using namespace std;

template <typename T>
void readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("FileNotFoundException");
    }

    T* data = new T[100];  
    int index = 0;
    T value;
    while (file >> value) {
        data[index++] = value;
    }

    file.close();

    cout << "Data read from file: ";
    for (int i = 0; i < index; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    delete[] data;  
}

int main() {
    try {
        readFromFile<int>("data.txt");
    } catch (const runtime_error& e) {
        cout << "Error: Unable to open file." << endl;
    }

    return 0;
}
