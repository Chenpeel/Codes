#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

#include <iostream>

template <typename T>
class Circular_Queue {
 private:
  struct Node {
    T data;
    Node* next;
  };

  Node* front;
  Node* rear;
  int size;
  int capacity;

 public:
  Circular_Queue(int capacity)
      : front(nullptr), rear(nullptr), size(0), capacity(capacity) {}

  ~Circular_Queue() {
    Node* current = front;
    while (current != nullptr) {
      Node* next = current->next;
      delete current;
      current = next;
    }
  }

  bool IsEmpty() const { return size == 0; }

  bool IsFull() const { return size == capacity; }

  int GetSize() const { return size; }

  void Enqueue(const T& data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    if (IsEmpty()) {
      front = rear = new_node;
    } else if (IsFull()) {
      Node* del_node = front;
      front = front->next;
      rear->next = new_node;
      rear = new_node;
      delete del_node;
    } else {
      rear->next = new_node;
      rear = new_node;
    }
    size = std::min(size + 1, capacity);
  }

  T Dequeue() {
    if (IsEmpty()) {
      std::cout << "Queue is empty!" << std::endl;
      return T();
    }
    T res = front->data;
    Node* del_node = front;
    front = front->next;
    delete del_node;
    size = std::max(size - 1, 0);
    return res;
  }

  void Print() {
    if (IsEmpty()) {
      std::cout << "Empty Queue" << std::endl;
      return;
    }
    Node* print_node = front;
    std::cout << "Front -> [";
    while (print_node) {
      std::cout << print_node->data;
      if (print_node->next) {
        std::cout << ", ";
      }
      print_node = print_node->next;
    }
    std::cout << "] <- Rear" << std::endl;
  }
};

#endif