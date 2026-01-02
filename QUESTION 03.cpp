#include <iostream>
#include <exception>
using namespace std;

template <typename T>
class Matrix {
private:
    T** mat;
    int rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        mat = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new T[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    void set(int row, int col, T value) {
        mat[row][col] = value;
    }

    T get(int row, int col) const {
        return mat[row][col];
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }
};

template <typename T>
Matrix<T> multiply(const Matrix<T>& a, const Matrix<T>& b) {
    if (a.getCols() != b.getRows()) {
        throw runtime_error("DimensionMismatchException");
    }

    Matrix<T> result(a.getRows(), b.getCols());
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < b.getCols(); ++j) {
            T sum = 0;
            for (int k = 0; k < a.getCols(); ++k) {
                sum += a.get(i, k) * b.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

int main() {
    try {
        Matrix<int> mat1(2, 3);
        mat1.set(0, 0, 1);
        mat1.set(0, 1, 2);
        mat1.set(0, 2, 3);
        mat1.set(1, 0, 4);
        mat1.set(1, 1, 5);
        mat1.set(1, 2, 6);

        Matrix<int> mat2(3, 2);
        mat2.set(0, 0, 7);
        mat2.set(0, 1, 8);
        mat2.set(1, 0, 9);
        mat2.set(1, 1, 10);
        mat2.set(2, 0, 11);
        mat2.set(2, 1, 12);

        Matrix<int> result = multiply(mat1, mat2);
        cout << "Matrix multiplication successful" << endl;
    } catch (const runtime_error& e) {
        cout << "Matrix dimensions incompatible for multiplication" << endl;
    }

    return 0;
}
