#include <iostream>
#include <cstring>
using namespace std;

void sortStrings(char* arr, int n, int len) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr + i * len, arr + j * len) > 0) {
                for (int k = 0; k < len; k++) {
                    char temp = *(arr + i * len + k);
                    *(arr + i * len + k) = *(arr + j * len + k);
                    *(arr + j * len + k) = temp;
                }
            }
        }
    }
}

char* concatenate(char* arr, int n, int len) {
    int total_len = n * len;
    char* result = new char[total_len];
    result[0] = '\0';

    for (int i = 0; i < n; i++) strcat(result, arr + i * len);
    return result;
}

int main() {
    int n = 3, len = 10;
    char* arr = new char[n * len];

    strcpy(arr, "apple");
    strcpy(arr + len, "banana");
    strcpy(arr + 2 * len, "cherry");

    sortStrings(arr, n, len);
    for (int i = 0; i < n; i++) cout << (arr + i * len) << " ";
    cout << endl;

    char* concatenated = concatenate(arr, n, len);
    cout << concatenated << endl;

    delete[] arr;
    delete[] concatenated;
}

