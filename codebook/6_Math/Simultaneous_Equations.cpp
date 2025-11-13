#include "Fraction.cpp"
struct Matrix {
    int m, n;
    vector<vector<fraction> > A;

    Matrix(int rows, int cols) : m(rows), n(cols), A(rows, vector<fraction>(cols)) {}

    void print() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j].print();
                cout << "\t";
            }
            cout << "\n";
        }
    }

    // Reduced Row Echelon Form (over rationals)
    void rref() {
        int row = 0;
        for (int col = 0; col < n && row < m; ++col) {
            int pivot = -1;
            for (int i = row; i < m; ++i)
                if (!A[i][col].is_zero()) {
                    pivot = i;
                    break;
                }
            if (pivot == -1) continue;

            swap(A[row], A[pivot]);

            // normalize pivot row
            fraction div = A[row][col];
            for (int j = 0; j < n; ++j)
                A[row][j] = A[row][j] / div;

            // eliminate other rows
            for (int i = 0; i < m; ++i) {
                if (i == row) continue;
                fraction factor = A[i][col];
                if (factor.is_zero()) continue;
                for (int j = 0; j < n; ++j)
                    A[i][j] = A[i][j] - factor * A[row][j];
            }

            ++row;
        }
    }
};

