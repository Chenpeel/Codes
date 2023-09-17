#include <iostream>

#include "./random.h"
#include "./struct/liner_list/singly_linked_list.hpp"

// 反转的递归实现
template <typename T>
Node<T>* reverse_singly_linked_list(Node<T>* head) {
  if (!head || !head->next) {
    return head;
  }
  Node<T>* new_head = reverse_singly_linked_list(head->next);
  head->next->next = head;
  head->next = nullptr;
  return new_head;
}

int main() {
  Singly_Linked_List<int> list;
  // 插入一些元素
  for (int i = 0; i < 10; i++) InsertBack(list, rd_int());

  cout << "初始状态:" << endl;
  Print(list);

  // 反转
  Node<int>* rev_head = reverse_singly_linked_list(list.head);

  cout << "反转之后:" << endl;
  PrintNode(rev_head);

  return 0;
}