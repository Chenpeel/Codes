#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <queue>
template <typename T>
struct BinNode {
  BinNode* left;
  BinNode* right;
  T data;
  BinNode(const T& data, BinNode* left = nullptr, BinNode* right = nullptr)
      : data(data), left(left), right(right) {}
};

template <typename T>
class Binary_Tree {
 private:
  BinNode<T>* root;

 public:
  Binary_Tree() : root(nullptr) {}
  ~Binary_Tree() { destroy(root); }

  Binary_Tree(const Binary_Tree& other) { root = clone(other.root); }
  Binary_Tree& operator=(const Binary_Tree& other);

  BinNode<T>* getRoot() const { return root; }
  void insert(const T& data) { insertNode(root, data); }

 private:
  void destroy(BinNode<T>* node) {
    if (node) {
      destroy(node->left);
      destroy(node->right);
      delete node;
    }
  }

  BinNode<T>* clone(const BinNode<T>* node) {
    if (!node) return nullptr;
    return new BinNode<T>(node->data, clone(node->left), clone(node->right));
  }

  
  // 按照二叉搜索形式简单插入节点
  void insertNode(BinNode<T>*& node, const T& data) {
    if (node == nullptr) {
      node = new BinNode<T>(data);
    } else if (data < node->data) {
      insertNode(node->left, data);
    } else {
      insertNode(node->right, data);
    }
  }
};

template <typename T>
void VisitNode(const BinNode<T>* node){
    std::cout << node->data << " ";
  }
// 先序遍历
template <typename T>
void PreOrder(const BinNode<T>* node) {
  if (node != nullptr) {
    VisitNode(node);
    PreOrder(node->left);
    PreOrder(node->right);
  }
}
// 中序遍历
template <typename T>
void InOrder(const BinNode<T>* node) {
  if (node != nullptr) {
    InOrder(node->left);
    VisitNode(node);
    InOrder(node->right);
  }
}
// 后序遍历
template <typename T>
void PostOrder(const BinNode<T>* node) {
  if (node != nullptr) {
    PostOrder(node->left);
    PostOrder(node->right);
    VisitNode(node);
  }
}
// 层序遍历
template <typename T>
void LevelOrder(const BinNode<T>* node) {
  std::queue<const BinNode<T>*> queue;
  queue.push(node);
  while (!queue.empty()) {
    const BinNode<T>* current = queue.front();
    queue.pop();
    if (current) {
      VisitNode(current);
      queue.push(current->left);
      queue.push(current->right);
    }
  }
}

template <typename T>
Binary_Tree<T>& Binary_Tree<T>::operator=(const Binary_Tree& other) {
  if (this != &other) {
    destroy(root);
    root = clone(other.root);
  }
  return *this;
}

template <typename T>
using BiTree = Binary_Tree<T>;

#endif
