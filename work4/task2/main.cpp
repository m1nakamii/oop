#include <iostream>
using namespace std;

template <typename T> class Matrix {
private:
  T **M;
  int m;
  int n;

public:
  Matrix() {
    n = m = 0;
    M = nullptr;
  }

  Matrix(int _m, int _n) {
    m = _m;
    n = _n;
    M = new T *[m];
    for (int i = 0; i < m; i++) {
      M[i] = new T[n];
      for (int j = 0; j < n; j++)
        M[i][j] = 0;
    }
  }

  Matrix(const Matrix &_M) {
    m = _M.m;
    n = _M.n;
    M = new T *[m];
    for (int i = 0; i < m; i++) {
      M[i] = new T[n];
      for (int j = 0; j < n; j++)
        M[i][j] = _M.M[i][j];
    }
  }

  ~Matrix() {
    if (n > 0) {
      for (int i = 0; i < m; i++)
        delete[] M[i];
    }
    if (m > 0)
      delete[] M;
  }

  T GetMij(int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n)
      return 0;
    return M[i][j];
  }

  void SetMij(int i, int j, T value) {
    if (i >= 0 && i < m && j >= 0 && j < n)
      M[i][j] = value;
  }

  void Print(const char *ObjName) {
    cout << "Object: " << ObjName << endl;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        cout << M[i][j] << "\t";
      cout << endl;
    }
    cout << "---------------------" << endl << endl;
  }

  Matrix &operator=(const Matrix &_M) {
    if (n > 0) {
      for (int i = 0; i < m; i++)
        delete[] M[i];
    }
    if (m > 0)
      delete[] M;

    m = _M.m;
    n = _M.n;

    M = new T *[m];
    for (int i = 0; i < m; i++) {
      M[i] = new T[n];
      for (int j = 0; j < n; j++)
        M[i][j] = _M.M[i][j];
    }

    return *this;
  }
};

int main() {
  Matrix<double> M(3, 4);
  M.Print("M");

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      M.SetMij(i, j, (i + j) * 0.5);
    }
  }

  M.Print("M");

  Matrix<double> M1 = M;
  M1.Print("M1");

  Matrix<double> M2;
  M2 = M;
  M2.Print("M2");

  Matrix<double> M3;
  M3 = M2 = M1 = M;
  M3.Print("M3");

  return 0;
}