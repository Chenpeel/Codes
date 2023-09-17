#include "linked_stack.hpp"
#include "sequeue_stack.hpp"

int main() {
  Sequeue_Stack<int> sqstack;  // Create a stack with initial size 5

  sqstack.Push(1);
  sqstack.Push(2);
  sqstack.Push(3);
  sqstack.Push(4);
  sqstack.Push(5);

  sqstack.LOG();  // Print the stack

  sqstack.Push(6);  // The stack should automatically resize

  sqstack.LOG();  // Print the stack after resizing

  int top = sqstack.GetTop();  // Get the top element of the stack
  std::cout << "Top element: " << top << std::endl;

  sqstack.Pop();  // Pop an element from the stack

  sqstack.LOG();  // Print the stack after popping an element

  sqstack.Conversion(255, 16);  // Convert number 255 to base 16

  std::cout<<"--------------------"<<std::endl;
  Linked_Stack<int> lkstack;

  lkstack.Push(5);
  lkstack.Push(10);
  lkstack.Push(20);
  lkstack.Print();

  int topElement = lkstack.GetTop();
  std::cout << "Top element: " << topElement << std::endl;

  int poppedElement = lkstack.Pop();
  std::cout << "Popped element: " << poppedElement << std::endl;

  lkstack.Print();

  int num = 123;
  int base = 2;
  lkstack.Conversion(num, base);
  return 0;
}