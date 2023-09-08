#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int size = rand() % 10 + 1; // Произвольное количество строк (от 1 до 10)
  int maxValue = 100;
  int **matrix = genRandMatrix(size, maxValue);

  printMatrix(matrix, size);

  // Очистка памяти
  for (int i = 0; i < size; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}