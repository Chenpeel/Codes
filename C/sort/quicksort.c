#include "./includes/sort.h"

void quicksort(ElemType arr[], int start, int end) {
  if (start < end) {
    ElemType pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
      if (arr[j] <= pivot) {
        i++;
        swap(&arr[j], &arr[i]);
      }
    }
    swap(&arr[i + 1], &arr[end]);
    quicksort(arr, start, i);
    quicksort(arr, i + 2, end);
  }
}

// 分析
// 最好空间复杂度 O(log(n)) 最差 O(n)
// 平均时间复杂度 O(n log(n)) 最差 O(n^2)
