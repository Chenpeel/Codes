
#include "../../random.h"
#include "./doubly_linked_list.hpp"
#include "./sequeue_list.hpp"
#include "./singly_linked_list.hpp"
#include "circular_linked_list.hpp"

int main() {
  /*
  // 线性表测试
  Sequeue_List<int> sqlist;
  for(int i = 1; i< 55; i++){
      sqlist.AddElem(random_num());
  }
  sqlist.Print();
  sqlist.Insert(30,random_num());
  sqlist.Print();
  sqlist.DeleteElem(22);
  sqlist.Print();
  int rdnum=random_num();
  if(sqlist.GetElem(rdnum)) cout << sqlist.GetElem(rdnum) << endl;
  */

  /*
  // 单链表测试
  Singly_Linked_List<float> slist;
  while(slist.GetSize()<25)
  {
      slist.InsertFront(rd_float()*100);
      slist.InsertBack(rd_float()*100);
      continue;
  }
  slist.InsertAtI(2,10.0);
  slist.Print();
  cout << slist.GetSize()<<endl;
  */
  /*
  // 双向链表测试

  DoublyLinkedList<int> list1, list2;

  // 初始化链表
  for (int i = 0; i < 5; i++) {
      InsertBack(list1,i);
  }

  for (int i = 5; i < 10; i++) {
      InsertBack(list2,i);
  }

  // 打印链表
  Print(list1);
  Print(list2);

  // 获取大小
  std::cout << "List1 size: " << GetSize(list1) << std::endl;
  std::cout << "List2 size: " << GetSize(list2) << std::endl;

  // 插入节点
  InsertAt(list1, 0, -1);
  InsertAt(list2, 6, 15);

  // 打印链表
  Print(list1);
  Print(list2);

  // 删除节点
  DeleteAt(list1, 3);
  DeleteAt(list2, 4);

  // 打印链表
  Print(list1);
  Print(list2);

  // 合并链表
  DoublyLinkedList<int> mergedList = Merge(list1, list2);
  Print(mergedList);
  */

  /*
  //循环链表
  CircularLinkedList<int> list1, list2;

  // 初始化链表
  for (int i = 0; i < 5; i++) {
    InsertBack(list1, i);
  }

  for (int i = 5; i < 10; i++) {
    InsertBack(list2, i);
  }

  // 打印链表
  Print(list1);
  Print(list2);

  // 获取大小
  std::cout << "List1 size: " << GetSize(list1) << std::endl;
  std::cout << "List2 size: " << GetSize(list2) << std::endl;

  // 插入节点
  InsertAt(list1, 0, -1);
  InsertAt(list2, 6, 15);

  // 打印链表
  Print(list1);
  Print(list2);

  // 删除节点
  DeleteAt(list1, 3);  // 删除第3个节点
  DeleteAt(list2, 4);

  // 打印链表
  Print(list1);
  Print(list2);

  // 合并链表
  CircularLinkedList<int> mergedList = Merge(list1, list2);
  Print(mergedList);
  */
  return 0;
}