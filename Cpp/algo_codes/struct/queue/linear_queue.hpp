#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

template <typename T>
class Linear_Queue {
 private:
  struct Node {
    T data;
    Node* next;
  };

  Node* front;
  Node* rear;
  int size;

 public:
  Linear_Queue() : front(nullptr), rear(nullptr), size(0) {}

  ~Linear_Queue() {
    Node* current = front;
    while (current != nullptr) {
      Node* next = current->next;
      delete current;
      current = next;
    }
  }

  bool IsEmpty() const { return size == 0; }

  int GetSize() const { return size; }

  void push(const T& data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    if (IsEmpty()) {
      front = rear = new_node;
    } else {
      rear->next = new_node;
      rear = new_node;
    }
    size++;
  }

  void pop() {
    if (IsEmpty()) {
      std::cout << "Queue is empty!" << std::endl;
      return T();
    }
    T res = front->data;
    Node* del_node = front;
    front = front->next;
    delete del_node;
    size--;
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