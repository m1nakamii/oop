#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int size = rand() % 10;
  int maxValue = 100;
  int *arr = genRandArray(size, maxValue);
  print(arr);
  //очистка выделенной памяти
  free(arr);
}