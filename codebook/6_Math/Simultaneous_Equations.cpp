#include "Fraction.cpp"
struct Matrix {
  int m, n;
  vector<vector<fraction>> A;

  Matrix(int rows, int cols) : m(rows), n(cols), A(rows, vector<fraction>(cols)) {}
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
        fraction fac = A[i][col];
        if (fac.is_zero()) continue;
        for (int j = 0; j < n; ++j)
          A[i][j] = A[i][j] - fac * A[row][j];
      }
      ++row;
    }
  }
  fraction det() { // make sure n == m
    fraction dv(1);
    int sign = 1;
    for (int col = 0; col < n; ++col) {
      int pivot = -1;
      for (int i = col; i < n; ++i)
        if (!A[i][col].is_zero()) {
          pivot = i;
          break;
        }
      if (pivot == -1)
        return fraction(0); // det = 0
      if (pivot != col) {
        swap(A[pivot], A[col]);
        sign = -sign;
      }
      fraction piv = A[col][col];
      dv = dv * piv;
      for (int i = col + 1; i < n; ++i) {
        fraction fac = A[i][col] / piv;
        for (int j = col; j < n; ++j)
          A[i][j] = A[i][j] - fac * A[col][j];
      }
    }
    if (sign == -1) dv = dv * fraction(-1);
    return dv;
  }
};
