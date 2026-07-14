#include "./includes/sort.h"

// 希尔排序
void shellsort(ElemType arr[], int size) {
  int gap, i, j;
  ElemType tmp;
  for (gap = size / 2; gap > 0; gap /= 2) {
    for (i = gap; i < size; i++) {
      tmp = arr[i];
      for (j = i - gap; j >= 0 && tmp < arr[j]; j -= gap) {
        arr[j + gap] = arr[j];
      }
      arr[j + gap] = tmp;
    }
  }
}

// 分析
// 空间复杂度 O(1)
// n在一定范围内 时间复杂度为 O(n^1.3) 最差为O(n^2)
