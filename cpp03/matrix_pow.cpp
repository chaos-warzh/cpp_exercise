//
// Created by DELL on 2024/11/15.
//

#include <iostream>

using namespace std;

#define MOD ((int)(1e9 + 7))

class Matrix {
  public:
  int size = 5;
  long long mat[5][5];

  Matrix(int n): size(n) {
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        mat[i][j] = 0;
  }

  Matrix(const Matrix &other): size(other.size) {
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        mat[i][j] = other.mat[i][j];
  }

  Matrix operator*(const Matrix &b) const {
    Matrix res(size);
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        res.mat[i][j] = 0;
        for (int k = 0; k < size; k++) {
          res.mat[i][j] += (mat[i][k] * b.mat[k][j]) % MOD;
          res.mat[i][j] %= MOD;
        }
      }
    }
    return res;
  }

  static Matrix input(int n) {
    Matrix matrix(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> matrix.mat[i][j];
      }
    }
    return matrix;
  }

  void print() const {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        cout << mat[i][j] << " ";
      }
      cout << endl;
    }
  }

  static Matrix identity(int sz) {
    Matrix res(sz);
    for (int i = 0; i < sz; i++)
      res.mat[i][i] = 1;
    return res;
  }
};

Matrix matrix_pow(Matrix &matrix, int p) {
  Matrix res = Matrix::identity(matrix.size);

  while (p) {
    if (p & 1) {
      res = res * matrix;
    }
    matrix = matrix * matrix;
    p >>= 1;
  }
  return res;
}

int main() {
  int n, p;
  cin >> n >> p;

  Matrix matrix = Matrix::input(n);
  Matrix result = matrix_pow(matrix, p);
  result.print();

  return 0;
}