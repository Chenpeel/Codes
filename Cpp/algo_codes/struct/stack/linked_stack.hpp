#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include <iostream>

template <typename T>
class Linked_Stack {
 private:
  struct Node {
    T data;
    Node* next;
  };

  Node* top;
  int length;

 public:
  Linked_Stack() : top(nullptr), length(0) {}

  ~Linked_Stack() { clear(); }

  bool empty() const { return (top == nullptr); }

  int length() const { return length; }

  T get_top() const {
    if (empty()) {
      std::cout << "[warning]: Empty stack" << std::endl;
      return T();
    }
    return top->data;
  }

  void Push(const T& element) {
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    length++;
  }

  T Pop() {
    if (StackEmpty()) {
      std::cout << "[error]: Empty stack" << std::endl;
      return T();
    }
    T element = top->data;
    Node* toDelete = top;
    top = top->next;
    delete toDelete;
    length--;
    return element;
  }

  void Print() const {
    std::cout << "Length: " << StackLength() << std::endl
              << "top -> base:" << std::endl;
    Node* current = top;
    while (current) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }

  // 进制转换
  void Conversion(long num, int R) {
    long temp = num;
    if (R <= 1) {
      std::cout << "R value is illegal" << std::endl;
      return;
    }
    InitStack();
    while (temp) {
      Push(temp % R);
      temp /= R;
    }
    std::cout << num << "(10) converted to base " << R << ": ";
    while (!StackEmpty()) {
      std::cout << Pop();
    }
    std::cout << std::endl;
    DestroyStack();
  }

 private:
  void clear() {
    while (!StackEmpty()) {
      Node* toDelete = top;
      top = top->next;
      delete toDelete;
      length--;
    }
  }
};

#endif