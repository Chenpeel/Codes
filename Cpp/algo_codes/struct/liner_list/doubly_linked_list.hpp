#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>
#include <sstream>

// 双向链表节点
template <typename T>
struct DNode {
  T data;
  DNode* prev;
  DNode* next;
};

// 双向链表类
template <typename T>
class DoublyLinkedList {
 public:
  DNode<T>* head;
  DNode<T>* tail;
  int size;

  DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

  ~DoublyLinkedList() {
    DNode<T>* current = head;
    while (current != nullptr) {
      DNode<T>* temp = current;
      current = current->next;
      delete temp;
    }
  }
};

// 打印链表
template <typename T>
void Print(const DoublyLinkedList<T>& list) {
  DNode<T>* current = list.head;
  
  std::stringstream ss;
  ss << "[";

  while (current != nullptr) {
    ss << current->data << ", ";
    current = current->next;
  }

  std::string result = ss.str();
  if (result.length() > 2) {
    result = result.substr(0, result.length() - 2);
  }

  result += "]";
  std::cout << result << std::endl;
}

// 获取链表大小
template <typename T>
int GetSize(const DoublyLinkedList<T>& list) {
  return list.size;
}

// 判断链表是否为空
template <typename T>
bool IsEmpty(const DoublyLinkedList<T>& list) {
  return list.size == 0;
}

// 头部插入节点
template <typename T>  
void InsertFront(DoublyLinkedList<T>& list, const T& data) {
  DNode<T>* new_DNode = new DNode<T>();
  new_DNode->data = data;
  new_DNode->prev = nullptr;
  new_DNode->next = list.head;
  
  if (list.head != nullptr) {
    list.head->prev = new_DNode;
  }
  else {
    list.tail = new_DNode; 
  }

  list.head = new_DNode;
  list.size++;
}

// 尾部插入节点
template <typename T>
void InsertBack(DoublyLinkedList<T>& list, const T& data) {
  DNode<T>* new_DNode = new DNode<T>();
  new_DNode->data = data;
  new_DNode->prev = list.tail;
  new_DNode->next = nullptr;

  if (list.tail != nullptr) {
    list.tail->next = new_DNode;
  }
  else {
    list.head = new_DNode;
  }

  list.tail = new_DNode;
  list.size++;
}

// 指定位置插入节点
template <typename T>
void InsertAt(DoublyLinkedList<T>& list, int index, const T& data) {
  if (index < 0 || index > list.size) {
    std::cout << "Invalid index" << std::endl;
    return;
  }

  DNode<T>* new_DNode = new DNode<T>();
  new_DNode->data = data;

  if (index == 0) {
    InsertFront(list, data);
    return;
  }

  if (index == list.size) {
    InsertBack(list, data);
    return;
  }

  DNode<T>* current = list.head;
  for (int i = 0; i < index - 1; ++i) {
    current = current->next;
  }

  new_DNode->prev = current;
  new_DNode->next = current->next;
  current->next->prev = new_DNode;
  current->next = new_DNode;

  list.size++;
}

// 删除指定位置的节点
template <typename T>
void DeleteAt(DoublyLinkedList<T>& list, int index) {
  if (index < 0 || index >= list.size) {
    std::cout << "Invalid index" << std::endl;
    return;
  }

  DNode<T>* current = list.head;
  for (int i = 0; i < index; ++i) {
    current = current->next;
  }

  if (current->prev != nullptr) {
    current->prev->next = current->next;
  } else {
    list.head = current->next;
  }

  if (current->next != nullptr) {
    current->next->prev = current->prev;
  } else {
    list.tail = current->prev;
  }

  delete current;
  list.size--;
}

// 合并两个有序链表
template <typename T>
DoublyLinkedList<T> Merge(const DoublyLinkedList<T>& list1, const DoublyLinkedList<T>& list2) {
  
  DoublyLinkedList<T> mergedList;

  DNode<T>* DNode1 = list1.head;
  DNode<T>* DNode2 = list2.head;

  while (DNode1 != nullptr && DNode2 != nullptr) {
    if (DNode1->data < DNode2->data) {
      InsertBack(mergedList, DNode1->data);
      DNode1 = DNode1->next;
    }
    else {
      InsertBack(mergedList, DNode2->data);
      DNode2 = DNode2->next;  
    }
  }

  while (DNode1 != nullptr) {
    InsertBack(mergedList, DNode1->data);
    DNode1 = DNode1->next;
  }

  while (DNode2 != nullptr) {
    InsertBack(mergedList, DNode2->data);
    DNode2 = DNode2->next;
  }

  return mergedList;
}

#endif