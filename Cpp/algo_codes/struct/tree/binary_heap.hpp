#ifndef BINARY_HEAP_HPP
#define BINARY_HEAP_HPP

#include <iostream>
#include <stdexcept>  // For exceptions
#include <vector>

template <typename T>
class MaxHeap {
 private:
  std::vector<T> heap;

  void heapifyUp(int index) {
    int parentIndex = (index - 1) / 2;
    while (index > 0 && heap[index] > heap[parentIndex]) {
      std::swap(heap[index], heap[parentIndex]);
      index = parentIndex;
      parentIndex = (index - 1) / 2;
    }
  }

  void heapifyDown(int index) {
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int largestIndex = index;

    if (leftChildIndex < heap.size() &&
        heap[leftChildIndex] > heap[largestIndex]) {
      largestIndex = leftChildIndex;
    }

    if (rightChildIndex < heap.size() &&
        heap[rightChildIndex] > heap[largestIndex]) {
      largestIndex = rightChildIndex;
    }

    if (largestIndex != index) {
      std::swap(heap[index], heap[largestIndex]);
      heapifyDown(largestIndex);
    }
  }

 public:
  MaxHeap() {}  // Default constructor
  std::vector<T>* getHeap() const { return heap; }
  // Function to insert an element into the heap.
  void insert(T value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
  }

  // Function to remove and return the maximum element from the heap.
  T extractMax() {
    if (isEmpty()) {
      throw std::runtime_error("Heap is empty.");
    }

    T maxValue = heap[0];
    std::swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    heapifyDown(0);

    return maxValue;
  }

  // Function to get the maximum element in the heap without removing it.
  T getMax() {
    if (isEmpty()) {
      throw std::runtime_error("Heap is empty.");
    }

    return heap[0];
  }

  // Function to check if the heap is empty.
  bool isEmpty() const { return heap.empty(); }

  // Function to get the size of the heap.
  size_t size() const { return heap.size(); }
};

#endif  // BINARY_HEAP_HPP
