#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **genRandMatrix(int size, int maxValue) {
  int **matrix = (int **)malloc(size * sizeof(int *));
  srand(
      time(NULL)); // Инициализируем генератор случайных чисел текущим временем

  for (int i = 0; i < size; i++) {
    int rowSize = rand() % 10 + 1; // Произвольный размер строки (от 1 до 10)
    matrix[i] = (int *)malloc(rowSize * sizeof(int));

    for (int j = 0; j < rowSize; j++) {
      matrix[i][j] = rand() % maxValue + 1; // Случайное число от 1 до maxValue
    }
  }

  return matrix;
}

void printMatrix(int **matrix, int size) {
  for (int i = 0; i < size; i++) {
    int rowSize = 0;
    while (matrix[i][rowSize] != 0) {
      rowSize++;
    }

    printf("%d: ", rowSize);

    for (int j = 0; j < rowSize; j++) {
      printf("%d ", matrix[i][j]);
    }

    printf("\n");
  }
}