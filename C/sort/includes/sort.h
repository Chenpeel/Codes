#ifndef SORT_H
#define SORT_H
#include <stdio.h>
typedef int ElemType;
void swap(ElemType *a, ElemType *b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}
void printArrayToFile(ElemType arr[], int size, FILE *file) {
  for (int i = 0; i < size; i++) {
    fprintf(file, "%d ", arr[i]);
  }
  fprintf(file, "\n");
}
void insertSort(ElemType arr[], int size);
void binaryInsertSort(ElemType arr[], int size);
void shellsort(ElemType arr[], int size);
void bubblesort(ElemType arr[], int size);
void quicksort(ElemType arr[], int start, int end);
#endif
