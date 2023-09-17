#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include <iostream>

template <typename T>
void bubble_sort(T arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;

    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }

    if (!swapped) break;
  }
}

#endif
