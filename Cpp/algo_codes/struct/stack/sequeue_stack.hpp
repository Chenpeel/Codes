#ifndef SEQUEUE_STACK_HPP
#define SEQUEUE_STACK_HPP


#include <iostream>

#define init_size 50
#define increment 10

template <typename T>
class Sequeue_Stack {
  private:
    T* stack;
    int stacksize;
    int top;

  public:
    Sequeue_Stack() {
      stack = new T[init_size];
      stacksize = init_size;
      top = 0;
    }

    ~Sequeue_Stack() {
      delete[] stack;
    }

    void ReNew() {
      T* new_stack = new T[stacksize + increment];
      for (int i = 0; i < stacksize; i++) {
        new_stack[i] = stack[i];
      }
      delete[] stack;
      stack = new_stack;
      stacksize += increment;
    }

    void InitStack() {
      top = 0;
    }

    void DestoryStack() {
      delete[] stack;
      stack = nullptr;
      std::cout << "stack has been destroyed" << std::endl;
    }

    void ClearStack() {
      top = 0;
    }

    bool StackEmpty() const {
      return top == 0;
    }

    int StackLength() const {
      return top;
    }

    T GetTop() const {
      if (top == 0) {
        std::cout << "[warning]: Empty stack" << std::endl;
        return T();
      }
      return stack[top - 1];
    }

    void Push(const T& element) {
      if (top >= stacksize) {
        ReNew();
      }
      stack[top++] = element;
    }

    T Pop() {
      if (top == 0) {
        std::cout << "[error]: Empty stack" << std::endl;
        return T();
      }
      return stack[--top];
    }

    void LOG() const {
      std::cout << "Length: " << StackLength() << std::endl << "base -> top:" << std::endl;
      for (int i = 0; i < top; i++) {
        std::cout << stack[i] << " ";
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
      std::cout << num << "(10) 的 " << R << " 进制为: ";
      while (!StackEmpty()) {
        std::cout << Pop();
      }
      std::cout << std::endl;
      DestoryStack();
    }
};

#endif