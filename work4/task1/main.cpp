#include <iostream>
using namespace std;

// Шаблонный класс Матрица
template <typename T> class Matrix {
private:
  T **M; // Указатель на указатель для матрицы
  int m; // Количество строк
  int n; // Количество столбцов

public:
  // Конструкторы
  Matrix() {
    n = m = 0;
    M = nullptr;
  }

  Matrix(int _m, int _n) {
    m = _m;
    n = _n;
    // Выделить память для матрицы
    M = new T *[m];
    for (int i = 0; i < m; i++) {
      M[i] = new T[n];
      // Заполнить матрицу нулями
      for (int j = 0; j < n; j++)
        M[i][j] = 0;
    }
  }

  // Конструктор копирования
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

  // Деструктор
  ~Matrix() {
    if (n > 0) {
      for (int i = 0; i < m; i++)
        delete[] M[i];
    }
    if (m > 0)
      delete[] M;
  }

  // Методы доступа
  T GetMij(int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n)
      return 0;
    return M[i][j];
  }

  void SetMij(int i, int j, T value) {
    if (i >= 0 && i < m && j >= 0 && j < n)
      M[i][j] = value;
  }

  // Метод, выводящий матрицу
  void Print(const char *ObjName) {
    cout << "Object: " << ObjName << endl;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        cout << M[i][j] << "\t";
      cout << endl;
    }
    cout << "---------------------" << endl << endl;
  }

  // Оператор копирования
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
  // Тестирование класса Matrix
  Matrix<int> M(3, 4);
  M.Print("M");

  // Заполнить матрицу значениями по формуле
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      M.SetMij(i, j, i + j);
    }
  }

  M.Print("M");

  Matrix<int> M1 = M; // Вызов конструктора копирования
  M1.Print("M1");

  Matrix<int> M2;
  M2 = M; // Вызов оператора копирования - проверка
  M2.Print("M2");

  Matrix<int> M3;
  M3 = M2 = M1 = M; // Вызов оператора копирования в виде "цепочки"
  M3.Print("M3");

  return 0;
}