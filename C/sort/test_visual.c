#include "./includes/sort.h"

#include <stdio.h>

int test_insertSort() {
  ElemType arr[] = {34, 8, 64, 51, 77, 69, 43, 32, 21};
  int size = sizeof(arr) / sizeof(arr[0]);

  FILE *file = fopen("utils/sort_steps.txt", "w");
  if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
  }
  printArrayToFile(arr, size, file);
  binaryInsertSort(arr, size);
  fclose(file);

  return 0;
}

int main() { test_insertSort(); }
