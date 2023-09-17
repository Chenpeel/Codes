#ifndef QUICK_SORT_H
#define QUICK_SORT_U

#include <iostream>

template <typename T>
void quick_sort_recursive(T arr[], int start, int end) {
  if (start >= end) return;
  T mid = arr[end];
  int left = start, right = end - 1;
  while (left < right) {
    while (arr[left] < mid && left < right) left++;
    while (arr[right] >= mid && left < right) right--;
    std::swap(arr[left], arr[right]);
  }
  if (arr[left] >= arr[end])
    std::swap(arr[left], arr[end]);
  else
    left++;
  quick_sort_recursive(arr, start, left - 1);
  quick_sort_recursive(arr, left + 1, end);
}
template <typename T>
void quick_sort(T arr[], int len) {
  quick_sort_recursive(arr, 0, len - 1);
}
#endif