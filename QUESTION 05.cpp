//Q1. You are tasked to develop a reusable array class where accessing an invalid index must
//throw an exception.
//Requirements:
//? Create a class template SafeArray<T>.
//? Add methods:
//? void set(int index, T value)
//? T get(int index)
//? Throw an OutOfBoundsException if:
//? Index < 0
//? Index >= size
//? Catch the exception in main() and print "Invalid array index access.".
//? The class should be able to work with different types (int, double, string).
#include <iostream>
using namespace std;

template <typename T>
class SafeArray {
private:
    T* arr;
    int size;

public:
    SafeArray(int size) : size(size) {
        arr = new T[size];
    }

    ~SafeArray() {
        delete[] arr;
    }

    void set(int index, T value) {
        if (index < 0 || index >= size) {
            throw out_of_range("OutOfBoundsException");
        }
        arr[index] = value;
    }

    T get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("OutOfBoundsException");
        }
        return arr[index];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    try {
        SafeArray<int> arr(5);
        arr.set(2, 10);
        cout << "Value at index 2: " << arr.get(2) << endl;
        arr.get(6);  // This will throw an exception
    } catch (const out_of_range& e) {
        cout << "Invalid array index access." << endl;
    }

    return 0;
}
