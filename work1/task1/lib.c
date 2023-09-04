#include <stdio.h>
#include <stdlib.h>
int *genRandArray(int size, int maxValue) {
  int *arr = malloc((size + 1) * sizeof(int)); // +1 for storing the size
  if (arr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  arr[0] = size; // Store the size in the first element

  for (int i = 1; i <= size; i++) {
    arr[i] = rand() % (maxValue + 1);
  }
  return arr;
}

void print(int *arr) {
  int size = arr[0];
  printf("%d: ", size);

  for (int i = 1; i <= size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}