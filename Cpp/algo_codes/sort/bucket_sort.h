#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include <iostream>

template <typename T>
void bucket_sort(T arr[], int n) {
  // 找到最小值和最大值
  T minVal = arr[0];
  T maxVal = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < minVal) {
      minVal = arr[i];
    } else if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
  }

  // 计算桶的数量
  int numBuckets = n;

  // 创建桶数组
  T** buckets = new T*[numBuckets];

  // 初始化桶
  for (int i = 0; i < numBuckets; i++) {
    buckets[i] = new T[n];
    int count = 0;  // 当前桶中的元素个数
    buckets[i][0] = count;
  }

  // 将元素放入对应的桶中
  for (int i = 0; i < n; i++) {
    int bucketIndex = (arr[i] - minVal) * numBuckets / (maxVal - minVal + 1);
    T* bucket = buckets[bucketIndex];
    int count = bucket[0];
    bucket[++count] = arr[i];
    bucket[0] = count;
  }

  // 对每个桶中的元素排序
  for (int i = 0; i < numBuckets; i++) {
    T* bucket = buckets[i];
    int count = bucket[0];
    std::sort(bucket + 1, bucket + count + 1);
  }

  // 将元素放回原数组
  int index = 0;
  for (int i = 0; i < numBuckets; i++) {
    T* bucket = buckets[i];
    int count = bucket[0];
    for (int j = 1; j <= count; j++) {
      arr[index++] = bucket[j];
    }
  }

  // 销毁桶
  for (int i = 0; i < numBuckets; i++) {
    delete[] buckets[i];
  }
  delete[] buckets;
}

#endif