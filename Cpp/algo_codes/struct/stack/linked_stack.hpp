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

  void InitStack() {
    top = nullptr;
    length = 0;
  }

  void DestroyStack() {
    clear();
    std::cout << "Stack has been destroyed" << std::endl;
  }

  void ClearStack() { clear(); }

  bool StackEmpty() const { return (top == nullptr); }

  int StackLength() const { return length; }

  T GetTop() const {
    if (StackEmpty()) {
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