#include <iostream>
using namespace std;

void reverse(int* arr, int n) {
    int *p = arr, *q = arr + n - 1, temp;
    while (p < q) {
        temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
}

int diff(int* arr, int n) {
    int *p = arr, max = *p, min = *p;
    for (; p < arr + n; p++) {
        if (*p > max) max = *p;
        if (*p < min) min = *p;
    }
    return max - min;
}

int main() {
    int n = 5, * arr = new int[n]{ 7, 2, 8, 1, 5 };
    
    for (int i = 0; i < n; i++) cout << *(arr + i) << " ";
    cout << endl;
    
    cout << "Difference: " << diff(arr, n) << endl;

    reverse(arr, n);

    for (int i = 0; i < n; i++) cout << *(arr + i) << " ";
    cout << endl;

    delete[] arr;
}

