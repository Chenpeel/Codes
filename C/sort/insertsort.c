#include "includes/sort.h"
// 从小到大

// 直接插入排序
void insertSort(ElemType arr[], int size) {
  int i, j;
  ElemType tmp;
  for (i = 1; i < size; i++) {
    if (arr[i - 1] > arr[i]) {             // 后一元素 比 之前元素 小
      tmp = arr[i];                        // 记录后一元素准备前移
      for (j = i - 1; tmp < arr[j]; --j) { // 哨兵值 与 前面的元素 逐一比较
        arr[j + 1] = arr[j];               // 前面元素后移
      }
      arr[j] = tmp; // 前移到了合适的位置
    }
    // 重复
  }
}
// 分析：
// 时间复杂度 O(n^2)
// 空间复杂度 O(1)
//
// 最快时间O(n)

// 折半插入排序
void binaryInsertSort(ElemType arr[], int size) {
  int i, j;
  int left, right, mid;
  ElemType tmp;

  for (i = 1; i < size; i++) {
    tmp = arr[i];
    left = 0;
    right = i - 1;

    // 使用二分查找确定插入位置
    while (left <= right) {
      mid = (left + right) / 2;
      if (arr[mid] > tmp) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    // 将元素后移，为插入元素腾出位置
    for (j = i - 1; j >= left; j--) {
      arr[j + 1] = arr[j];
    }

    // 插入元素
    arr[left] = tmp;
  }
}
