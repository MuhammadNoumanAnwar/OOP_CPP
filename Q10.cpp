#include <iostream>
using namespace std;

void add(int* a, int* b, int* c, int n, int m) {
    for (int* p = c, *x = a, *y = b; p < c + n * m; p++, x++, y++) 
        *p = *x + *y;
}

void subtract(int* a, int* b, int* c, int n, int m) {
    for (int* p = c, *x = a, *y = b; p < c + n * m; p++, x++, y++) 
        *p = *x - *y;
}

void multiply(int* a, int* b, int* c, int n, int m, int p) {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < p; j++) {
            *(c + i * p + j) = 0;
            for (int k = 0; k < m; k++) 
                *(c + i * p + j) += *(a + i * m + k) * *(b + k * p + j);
        }
}

void displayMatrix(int* mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << *(mat + i * m + j) << " ";
        cout << endl;
    }
}

int main() {
    int n = 2, m = 2, p = 2;
    int a[] = { 1, 2, 3, 4 };
    int b[] = { 5, 6, 7, 8 };
    int c[4];

    multiply(a, b, c, n, m, p);
    displayMatrix(c, n, p);
}

