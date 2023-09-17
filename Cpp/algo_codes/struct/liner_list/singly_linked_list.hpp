#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>
#include <sstream>

// 定义单向链表节点的结构
template <typename T>
struct Node {
  T data;
  Node* next;
};

// 单向链表类
template <typename T>
class Singly_Linked_List {
 public:
  Node<T>* head; // 链表头指针
  int size; // 链表中节点的数量

  Singly_Linked_List() : head(nullptr), size(0) {} // 构造函数，初始化链表为空
  ~Singly_Linked_List(); // 析构函数，释放链表中节点的内存
};

// 析构函数，释放链表中所有节点的内存
template <typename T>
Singly_Linked_List<T>::~Singly_Linked_List() {
  Node<T>* current = head;
  while (current != nullptr) {
    Node<T>* next = current->next;
    delete current;
    current = next;
  }
}

// 判断链表是否为空
template<typename T>
bool isEmpty(Singly_Linked_List<T>& list){
  return list.size == 0;
}

// 在链表头部插入元素
template <typename T>
void InsertFront(Singly_Linked_List<T>& list, const T& data) {
  Node<T>* new_node = new Node<T>;
  new_node->data = data;
  new_node->next = list.head;
  list.head = new_node;
  list.size++;
}

// 在链表尾部插入元素
template <typename T>
void InsertBack(Singly_Linked_List<T>& list, const T& data) {
  Node<T>* new_node = new Node<T>;
  new_node->data = data;
  new_node->next = nullptr;
  if (list.head == nullptr)
    list.head = new_node;
  else {
    Node<T>* current = list.head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new_node;
  }
  list.size++;
}

// 按照节点指针方式打印链表
template <typename T>
void PrintNode(const Node<T>* head) {
  if (!head) {
    std::cout << "Empty List" << std::endl;
    return;
  }

  const Node<T>* print_node = head;
  std::stringstream ss;
  ss << "[";
  while (print_node) {
    ss << print_node->data << ", ";
    print_node = print_node->next;
  }
  // 规整输出样式
  std::string result = ss.str();
  if (result.length() > 2) {
    result = result.substr(0, result.length() - 2);
  }
  result += "]";
  std::cout << result << std::endl;
}

// 打印链表
template <typename T>
void Print(const Singly_Linked_List<T>& list) {
  if (list.size == 0) {
    std::cout << "Empty List" << std::endl;
    return;
  }

  Node<T>* print_node = list.head;
  std::stringstream ss;
  ss << "[";
  while (print_node) {
    ss << print_node->data << ", ";
    print_node = print_node->next;
  }
  // 规整输出样式
  std::string result = ss.str();
  if (result.length() > 2) {
    result = result.substr(0, result.length() - 2);
  }
  result += "]";
  std::cout << result << std::endl;
}

// 获取链表中第 n 个位置的元素
template <typename T>
T GetElem(const Singly_Linked_List<T>& list, const int n) {
  if (n < 1 || n > list.size) {
    std::cout << "Wrong Position" << std::endl;
    return T();
  }
  Node<T>* current = list.head;
  int i = 1;
  while (current && i < n) {
    current = current->next;
    i++;
  }
  return current->data;
}

// 删除链表中第 n 个位置的节点
template <typename T>
T DeleteNode(Singly_Linked_List<T>& list, const int n) {
  if (n < 1 || n > list.size) {
    std::cout << "Wrong Position" << std::endl;
    return T();
  }
  int i = 1;
  Node<T>* current = list.head;
  while (current && i < n - 1) {
    current = current->next;
    i++;
  }
  if (n == 1) {
    Node<T>* del_node = current;
    T res = del_node->data;
    list.head = del_node->next;
    delete del_node;
    list.size--;
    return res;
  } else {
    Node<T>* del_node = current->next;
    T res = del_node->data;
    current->next = del_node->next;
    delete del_node;
    list.size--;
    return res;
  }
}

// 合并两个有序链表并返回新链表
template <typename T>
Singly_Linked_List<T> Merge_List(const Singly_Linked_List<T>& L1,
                                 const Singly_Linked_List<T>& L2) {
  Singly_Linked_List<T> mergedList;
  typename Singly_Linked_List<T>::Node *p1 = L1.head, *p2 = L2.head,
                                       *p = nullptr;
  mergedList.head = nullptr;
  p = mergedList.head;
  while (p1 && p2) {
    if (p1->data <= p2->data) {
      if (mergedList.head == nullptr) {
        mergedList.head = new typename Singly_Linked_List<T>::Node();
        mergedList.head->data = p1->data;
        p = mergedList.head;
      } else {
        p->next = new typename Singly_Linked_List<T>::Node();
        p = p->next;
        p->data = p1->data;
      }
      p1 = p1->next;
    } else {
      if (mergedList.head == nullptr) {
        mergedList.head = new typename Singly_Linked_List<T>::Node();
        mergedList.head->data = p2->data;
        p = mergedList.head;
      } else {
        p->next = new typename Singly_Linked_List<T>::Node();
        p = p->next;
        p->data = p2->data;
      }
      p2 = p2->next;
    }
  }
  if (p1) p->next = p1;
  if (p2) p->next = p2;
  return mergedList;
}

#endif
