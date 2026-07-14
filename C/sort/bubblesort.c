#include "./includes/sort.h"
void bubblesort(ElemType arr[], int size) {
  for (int i = 0; i < size; i++) {
    int flag = 0;
    for (int j = size - 1; j > 1; j--) {
      if (arr[j - 1] > arr[j]) {
        swap(&arr[j - 1], &arr[j]);
        flag = !flag;
      }
    }
    if (flag == 0)
      return;
  }
}
// 分析
// 冒泡排序是稳定的排序算法
// 空间复杂度 O(1)
// 时间复杂度 最好情况O(n) , 最差O(n^2)
//
