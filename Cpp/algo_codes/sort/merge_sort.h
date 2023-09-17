#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>

template <typename T>
void recursion(T arr[], int l, int r) {

  if (l >= r) return;

  int m = l + (r - l) / 2;

  recursion(arr, l, m);
  recursion(arr, m+1, r);
  merge(arr, l, m, r);
}

template <typename T>  
void merge(T arr[], int l, int m, int r) {
  
  // 排序并合并两个有序数组 arr[l...m] 和 arr[m+1...r]

  int n1 = m - l + 1;
  int n2 = r - m;

  T L[n1], R[n2]; // 临时数组

  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  int i = 0;
  int j = 0;
  int k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++; k++;
  }

  while (j < n2) { 
    arr[k] = R[j];
    j++; k++;
  }
}
void merge_sort(int arr[], int n) {
  recursion(arr, 0, n-1); 
}
#endif