#ifndef FIBONACCI_HEAP_HPP
#define FIBONACCI_HEAP_HPP

#include <iostream>
#include <unordered_map>

template <typename T>
class FibonacciHeap {
 private:
  struct Node {
    T key;
    int degree;
    bool mark;
    Node* parent;
    Node* child;
    Node* prev;
    Node* next;

    Node(T key)
        : key(key),
          degree(0),
          mark(false),
          parent(nullptr),
          child(nullptr),
          prev(this),
          next(this) {}
  };

  Node* minNode;
  int size;

  // 合并两个斐波那契堆，将other合并到this中
  void merge(FibonacciHeap& other) {
    if (other.minNode == nullptr) {
      return;
    }

    Node* thisMin = this->minNode;
    Node* otherMin = other.minNode;

    Node* thisMinNext = thisMin->next;
    Node* otherMinPrev = otherMin->prev;

    thisMin->next = otherMin;
    otherMin->prev = thisMin;

    thisMinNext->prev = otherMinPrev;
    otherMinPrev->next = thisMinNext;

    if (thisMin->key > otherMin->key) {
      this->minNode = otherMin;
    }

    this->size += other.size;
  }

 public:
  FibonacciHeap() : minNode(nullptr), size(0) {}
  Node* getMinNode() const { return minNode; }
  bool empty() const { return size == 0; }

  int getSize() const { return size; }

  void insert(T key) {
    Node* newNode = new Node(key);
    if (minNode == nullptr) {
      minNode = newNode;
    } else {
      Node* minNext = minNode->next;
      minNode->next = newNode;
      newNode->prev = minNode;
      newNode->next = minNext;
      minNext->prev = newNode;

      if (key < minNode->key) {
        minNode = newNode;
      }
    }
    size++;
  }

  T extractMin() {
    if (minNode == nullptr) {
      throw std::runtime_error("Heap is empty.");
    }

    T minKey = minNode->key;

    Node* minChild = minNode->child;
    while (minChild != nullptr) {
      Node* nextChild = minChild->next;
      minChild->prev = minNode->prev;
      minChild->next = minNode->next;
      minChild->next->prev = minChild;
      minChild->prev->next = minChild;

      minChild->parent = nullptr;

      minChild = nextChild;
    }

    if (minNode == minNode->next) {
      delete minNode;
      minNode = nullptr;
    } else {
      Node* nextMin = minNode->next;
      Node* prevMin = minNode->prev;

      nextMin->prev = prevMin;
      prevMin->next = nextMin;

      delete minNode;
      minNode = nextMin;
      consolidate();
    }

    size--;
    return minKey;
  }

 private:
  // 合并相同度数的根节点，保持斐波那契堆的性质
  void consolidate() {
    std::unordered_map<int, Node*> degreeTable;

    Node* currentNode = minNode;
    Node* endNode = minNode;
    do {
      Node* nextNode = currentNode->next;
      int degree = currentNode->degree;

      while (degreeTable.find(degree) != degreeTable.end()) {
        Node* sameDegreeNode = degreeTable[degree];

        if (currentNode->key > sameDegreeNode->key) {
          std::swap(currentNode, sameDegreeNode);
        }

        link(sameDegreeNode, currentNode);
        degreeTable.erase(degree);
        degree++;
      }

      degreeTable[degree] = currentNode;
      currentNode = nextNode;
    } while (currentNode != endNode);

    minNode = nullptr;
    for (const auto& entry : degreeTable) {
      Node* node = entry.second;
      if (minNode == nullptr) {
        minNode = node;
      } else {
        node->prev = minNode->prev;
        node->next = minNode;
        minNode->prev->next = node;
        minNode->prev = node;

        if (node->key < minNode->key) {
          minNode = node;
        }
      }
    }
  }

  // 将两个度数相同的根节点连接在一起
  void link(Node* higherDegreeNode, Node* lowerDegreeNode) {
    higherDegreeNode->prev->next = higherDegreeNode->next;
    higherDegreeNode->next->prev = higherDegreeNode->prev;

    if (lowerDegreeNode->child == nullptr) {
      lowerDegreeNode->child = higherDegreeNode;
      higherDegreeNode->prev = higherDegreeNode;
      higherDegreeNode->next = higherDegreeNode;
    } else {
      Node* lowerChild = lowerDegreeNode->child;
      higherDegreeNode->prev = lowerChild->prev;
      higherDegreeNode->next = lowerChild;
      lowerChild->prev->next = higherDegreeNode;
      lowerChild->prev = higherDegreeNode;
    }

    higherDegreeNode->parent = lowerDegreeNode;
    lowerDegreeNode->degree++;
    higherDegreeNode->mark = false;
  }
};

#endif
