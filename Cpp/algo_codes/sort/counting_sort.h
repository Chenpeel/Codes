#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include <iostream>
// 计数排序
template <typename T>
void counting_sort(T arr[], int n) {
  if (n <= 1) return;
  T max = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  T count[max + 1] = {0};
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  T output[n];

  for (int i = n - 1; i >= 0; i--) {
    output[--count[arr[i]]] = arr[i];
  }

  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

#endif