#include <iostream>
using namespace std;

class Matrix {
private:
    int data[2][2];

public:
    Matrix(int a[2][2]) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                data[i][j] = a[i][j];
            }
        }
    }

    Matrix operator*(const Matrix& m) {
        int result[2][2] = {0};

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    result[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }

        return Matrix(result);
    }

    friend ostream& operator<<(ostream& out, const Matrix& m) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                out << m.data[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
};

int main() {
    int arr1[2][2] = {{1, 2}, {3, 4}};
    int arr2[2][2] = {{5, 6}, {7, 8}};

    Matrix m1(arr1), m2(arr2);
    Matrix result = m1 * m2;

    cout << "Matrix 1:\n" << m1;
    cout << "Matrix 2:\n" << m2;
    cout << "Resultant Matrix:\n" << result;

    return 0;
}
