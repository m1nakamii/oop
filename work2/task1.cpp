#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  srand(time(0));
  int N;
  cout << "Введите размер массива N: ";
  cin >> N;

  // Создаем динамический двумерный массив размером N×N и заполняем его
  // случайными целыми числами
  vector<vector<int>> matrix(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      matrix[i][j] = rand() % 100; // Генерируем случайное число от 0 до 99
    }
  }

  // a) По правым диагоналям, начиная с правого верхнего элемента
  vector<int> D;
  for (int k = 0; k < N; ++k) {
    for (int i = 0, j = k; i <= k; ++i, --j) {
      D.push_back(matrix[i][j]);
    }
  }

  // b) По левым диагоналям, начиная с левого верхнего элемента
  for (int k = 1; k < N; ++k) {
    for (int i = k, j = N - 1; i < N; ++i, --j) {
      D.push_back(matrix[i][j]);
    }
  }

  // c) По спирали, начиная с центрального элемента
  int row_start = N / 2, col_start = N / 2;
  int step = 1;
  D.push_back(matrix[row_start][col_start]);

  while (step < N) {
    for (int i = 0; i < step; ++i) {
      col_start++;
      D.push_back(matrix[row_start][col_start]);
    }

    for (int i = 0; i < step; ++i) {
      row_start++;
      D.push_back(matrix[row_start][col_start]);
    }

    step++;

    for (int i = 0; i < step; ++i) {
      col_start--;
      D.push_back(matrix[row_start][col_start]);
    }

    for (int i = 0; i < step; ++i) {
      row_start--;
      D.push_back(matrix[row_start][col_start]);
    }

    step++;
  }

  // d) По спирали, начиная с левого верхнего элемента
  row_start = 0;
  col_start = 0;
  step = N - 1;

  while (step > 0) {
    for (int i = 0; i < step; ++i) {
      col_start++;
      D.push_back(matrix[row_start][col_start]);
    }

    for (int i = 0; i < step; ++i) {
      row_start++;
      D.push_back(matrix[row_start][col_start]);
    }

    step--;

    for (int i = 0; i < step; ++i) {
      col_start--;
      D.push_back(matrix[row_start][col_start]);
    }

    for (int i = 0; i < step; ++i) {
      row_start--;
      D.push_back(matrix[row_start][col_start]);
    }

    step--;
  }

  // Выводим элементы массива D
  cout << "Элементы массива D:" << endl;
  for (int i = 0; i < D.size(); ++i) {
    cout << D[i] << " ";
  }
  cout << endl;

  return 0;
}