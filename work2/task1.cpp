#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
  srand(time(0));

  int N;
  cout << "Введите размер N для матрицы: ";
  cin >> N;

  // Создаем двумерный динамический массив и проверяем успешное выделение памяти
  int **matrix = new int *[N];
  for (int i = 0; i < N; i++) {
    matrix[i] = new int[N];
    if (!matrix[i]) {
      cerr << "Ошибка выделения памяти." << endl;
      return 1; // Возвращаем ненулевой код ошибки
    }
  }

  // Заполняем матрицу случайными числами и выводим ее
  cout << "Как выглядит матрица:" << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      matrix[i][j] = rand() % 100; // Диапазон случайных чисел можно изменить
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }

  // Создаем одномерный массив D
  int *D = new int[N * N];
  if (!D) {
    cerr << "Ошибка выделения памяти." << endl;
    return 1; // Возвращаем ненулевой код ошибки
  }

  // a) по правым диагоналям, начиная с правого верхнего элемента
  int index = 0;
  for (int k = 0; k < 2 * N - 1; k++) {
    if (k < N) {
      for (int i = 0; i <= k; i++) {
        int j = k - i;
        if (i < N && j < N) {
          D[index++] = matrix[i][j];
        }
      }
    } else {
      for (int i = N - 1; i >= k - N + 1; i--) {
        int j = k - i;
        if (i < N && j < N) {
          D[index++] = matrix[i][j];
        }
      }
    }
  }

  // Выводим одномерный массив D (по правым диагоналям)
  cout << "Массив D (по правым диагоналям): ";
  for (int i = 0; i < N * N; i++) {
    cout << D[i] << " ";
  }
  cout << endl;

  // Сбрасываем index в ноль перед заполнением следующего массива
  index = 0;

  // b) по левым диагоналям, начиная с левого верхнего элемента
  for (int k = 0; k < 2 * N - 1; k++) {
    if (k < N) {
      for (int i = 0; i <= k; i++) {
        int j = k - i;
        if (i < N && j < N) {
          D[index++] = matrix[j][i]; // Обратная последовательность
        }
      }
    } else {
      for (int i = N - 1; i >= k - N + 1; i--) {
        int j = k - i;
        if (i < N && j < N) {
          D[index++] = matrix[j][i];
        }
      }
    }
  }

  // Выводим одномерный массив D (по левым диагоналям)
  cout << "Массив D (по левым диагоналям): ";
  for (int i = 0; i < N * N; i++) {
    cout << D[i] << " ";
  }
  cout << endl;

  // Сбрасываем index в ноль перед заполнением следующего массива
  index = 0;

  // c) по спирали, начиная с центрального элемента
  int row = N / 2;
  int col = N / 2;
  int step = 1;
  D[index++] = matrix[row][col]; // Центральный элемент

  while (index < N * N) {
    // Двигаемся вправо
    for (int i = 0; i < step; i++) {
      col++;
      if (row >= 0 && row < N && col >= 0 && col < N) {
        D[index++] = matrix[row][col];
      }
    }

    // Двигаемся вниз
    for (int i = 0; i < step; i++) {
      row++;
      if (row >= 0 && row < N && col >= 0 && col < N) {
        D[index++] = matrix[row][col];
      }
    }

    step++;

    // Двигаемся влево
    for (int i = 0; i < step; i++) {
      col--;
      if (row >= 0 && row < N && col >= 0 && col < N) {
        D[index++] = matrix[row][col];
      }
    }

    // Двигаемся вверх
    for (int i = 0; i < step; i++) {
      row--;
      if (row >= 0 && row < N && col >= 0 && col < N) {
        D[index++] = matrix[row][col];
      }
    }

    step++;
  }

  // Выводим одномерный массив D (по спирали, начиная с центрального элемента)
  cout << "Массив D (по спирали, начиная с центрального элемента): ";
  for (int i = 0; i < N * N; i++) {
    cout << D[i] << " ";
  }
  cout << endl;

  // Сбрасываем index в ноль перед заполнением последнего массива
  index = 0;

  // d) по спирали, начиная с левого верхнего элемента
  row = N / 2;
  col = N / 2;
  step = 1;

  // d) По спирали, начиная с левого верхнего элемента
  int startRow = 0;
  int endRow = N - 1;
  int startCol = 0;
  int endCol = N - 1;

  while (startRow <= endRow && startCol <= endCol) {
    // Двигаемся вправо
    for (int j = startCol; j <= endCol; j++) {
      D[index++] = matrix[startRow][j];
    }
    startRow++;

    // Двигаемся вниз
    for (int i = startRow; i <= endRow; i++) {
      D[index++] = matrix[i][endCol];
    }
    endCol--;

    // Двигаемся влево (если не достигли того же столбца)
    if (startRow <= endRow) {
      for (int j = endCol; j >= startCol; j--) {
        D[index++] = matrix[endRow][j];
      }
      endRow--;
    }

    // Двигаемся вверх (если не достигли той же строки)
    if (startCol <= endCol) {
      for (int i = endRow; i >= startRow; i--) {
        D[index++] = matrix[i][startCol];
      }
      startCol++;
    }
  }

  // Выводим одномерный массив D (по спирали, начиная с левого верхнего
  // элемента)
  cout << "Массив D (по спирали, начиная с левого верхнего элемента): ";
  for (int i = 0; i < N * N; i++) {
    cout << D[i] << " ";
  }
  cout << endl;

  // Освобождаем выделенную память
  for (int i = 0; i < N; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
  delete[] D;

  return 0;
}