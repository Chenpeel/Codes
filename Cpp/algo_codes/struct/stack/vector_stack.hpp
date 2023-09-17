#ifndef VECTOR_STACK_HPP
#define VECTOR_STACK_HPP

#include <iostream>
#include <vector>

template <typename T>
class Vector_Stack {
 private:
  std::vector<T> stack;

 public:
  Vector_Stack() {}

  void InitStack() { stack.clear(); }

  void DestoryStack() { stack.clear(); }

  void ClearStack() { stack.clear(); }

  bool StackEmpty() const { return stack.empty(); }

  int StackLength() const { return stack.size(); }

  T GetTop() const {
    if (stack.empty()) {
      std::cout << "[warning]: Empty stack" << std::endl;
      return T();
    }
    return stack.back();
  }

  void Push(const T& element) { stack.push_back(element); }

  T Pop() {
    if (stack.empty()) {
      std::cout << "[error]: Empty stack" << std::endl;
      return T();
    }
    T element = stack.back();
    stack.pop_back();
    return element;
  }

  void LOG() const {
    std::cout << "Length: " << StackLength() << std::endl
              << "base -> top:" << std::endl;
    for (const T& element : stack) {
      std::cout << element << " ";
    }
    std::cout << std::endl;
  }

  void Conversion(long num, int R) {
    long temp = num;
    if (R <= 1) {
      std::cout << "R vaule is illegal" << std::endl;
      return;
    }
    InitStack();
    while (temp) {
      Push(temp % R);
      temp /= R;
    }
    std::cout << num << "(10) 的 " << R << " 进制为: ";
    while (!StackEmpty()) {
      std::cout << Pop();
    }
    std::cout << std::endl;
    DestoryStack();
  }
};

#endif