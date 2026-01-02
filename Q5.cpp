//5. Write a program that creates a 5x5 2D array to represent a square matrix. The matrix should be initialized
//as follows:
//o Elements on the main diagonal should have a value of 1.
//o Elements above the main diagonal should have a value equal to their column index.
//o Elements below the main diagonal should have a value equal to their row
//index. Then:
//o Print the matrix in matrix form.
//o Calculate and print the sum of all elements in the matrix.
//o Transpose the matrix in place (swap rows and columns) and print the transposed matrix.
#include <iostream>
using namespace std;
int main() {
    int matrix[5][5];
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                matrix[i][j] = 1;  
            } else if (j > i) {
                matrix[i][j] = j; 
            } else {
                matrix[i][j] = i;  
            }
        }
    }
    cout << "Original Matrix:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
            sum += matrix[i][j];
        }
        cout << endl;
    }
    cout << "Sum of all elements: " << sum << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


