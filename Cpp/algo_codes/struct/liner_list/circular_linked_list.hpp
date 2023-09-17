#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP

#include <iostream>
#include <sstream>

// 循环链表节点
template <typename T>
struct CNode {
  T data;
  CNode* next;
};

// 循环链表类
template <typename T>
class CircularLinkedList {
 public:
  CNode<T>* head;
  int size;

  CircularLinkedList() : head(nullptr), size(0) {}

  ~CircularLinkedList() {
    // 析构函数
  }
};

// 获取循环链表大小
template <typename T>
int GetSize(CircularLinkedList<T>& list) {
  return list.size;
}

// 判断循环链表是否为空
template <typename T>
bool IsEmpty(CircularLinkedList<T>& list) {
  return list.size == 0;
}

// 打印循环链表
template <typename T>
void Print(CircularLinkedList<T>& list) {
  if (list.head == nullptr) {
    std::cout << "Empty List" << std::endl;
    return;
  }

  CNode<T>* current = list.head;
  std::stringstream ss;
  ss << "[";
  do {
    ss << current->data << ", ";
    current = current->next;
  } while (current != list.head);

  std::string result = ss.str();
  result = result.substr(0, result.size() - 2);
  result += "]";
  std::cout << result << std::endl;
}

// 头部插入节点
template <typename T>
void InsertFront(CircularLinkedList<T>& list, const T& data) {
  CNode<T>* new_CNode = new CNode<T>();
  new_CNode->data = data;

  if (list.head == nullptr) {
    new_CNode->next = new_CNode;
    list.head = new_CNode;
  } else {
    new_CNode->next = list.head;
    CNode<T>* current = list.head;
    while (current->next != list.head) {
      current = current->next;
    }
    current->next = new_CNode;
    list.head = new_CNode;
  }

  list.size++;
}

// 尾部插入节点
template <typename T>
void InsertBack(CircularLinkedList<T>& list, const T& data) {
  CNode<T>* new_CNode = new CNode<T>();
  new_CNode->data = data;

  if (list.head == nullptr) {
    new_CNode->next = new_CNode;
    list.head = new_CNode;
  } else {
    new_CNode->next = list.head;
    CNode<T>* current = list.head;
    while (current->next != list.head) {
      current = current->next;
    }
    current->next = new_CNode;
  }

  list.size++;
}

// 指定位置插入节点
template <typename T>
void InsertAt(CircularLinkedList<T>& list, int index, const T& data) {
  if (index < 0 || index > list.size) {
    std::cout << "Invalid index" << std::endl;
    return;
  }

  CNode<T>* new_CNode = new CNode<T>();
  new_CNode->data = data;

  if (index == 0) {
    InsertFront(list, data);
    return;
  }

  if (index == list.size) {
    InsertBack(list, data);
    return;
  }

  CNode<T>* current = list.head;
  for (int i = 0; i < index - 1; i++) {
    current = current->next;
  }

  new_CNode->next = current->next;
  current->next = new_CNode;

  list.size++;
}

// 删除指定位置的节点
template <typename T>
void DeleteAt(CircularLinkedList<T>& list, int index) {
  // 索引越界检查
  if (index < 0 || index >= list.size) {
    std::cout << "Invalid index" << std::endl;
    return;
  }

  Node<T>* current = list.head;

  // 删除头节点
  if (index == 0) {
    if (list.size == 1) {  // 只有一个节点
      delete list.head;
      list.head = nullptr;
    } else {
      CNode<T>* last = list.head;
      while (last->next != list.head) {
        last = last->next;
      }
      last->next = list.head->next;
      delete list.head;
      list.head = last->next;
    }
  } else {
    // 找到index-1节点
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }

    // 删除current的下一节点
    CNode<T>* toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;
  }

  list.size--;
}

// 合并两个循环链表
template <typename T>
CircularLinkedList<T> Merge(CircularLinkedList<T>& list1,
                            CircularLinkedList<T>& list2) {
  CircularLinkedList<T> mergedList;

  // 遍历 list1,复制节点到 mergedList
  CNode<T>* current1 = list1.head;
  if (current1 != nullptr) {
    do {
      InsertBack(mergedList, current1->data);  // 调用 free function
      current1 = current1->next;
    } while (current1 != list1.head);
  }

  // 遍历 list2,复制节点到 mergedList
  CNode<T>* current2 = list2.head;
  if (current2 != nullptr) {
    do {
      InsertBack(mergedList, current2->data);  // 调用 free function
      current2 = current2->next;
    } while (current2 != list2.head);
  }

  return mergedList;
}

#endif