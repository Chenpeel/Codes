#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include <iostream>

#include "binary_tree.hpp"

// 二叉搜索树
template <typename T>
class Binary_Search_Tree {
 private:
  BinNode<T>* root;

 public:
  Binary_Search_Tree() : root(nullptr) {}
  ~Binary_Search_Tree() { destroy(root); }
  Binary_Search_Tree(const Binary_Search_Tree& other) {
    root = clone(other.root);
  }
  BinNode<T>* getRoot() const { return root; }
  Binary_Search_Tree& operator=(const Binary_Search_Tree& other);

  void insert(const T& data) { insertNode(root, data); }
  void remove(const T& data) {
    if (root) root = removeNode(root, data);
  }

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

  void insertNode(BinNode<T>*& node, const T& data) {
    if (node == nullptr) {
      node = new BinNode<T>(data);
    } else if (data < node->data) {
      insertNode(node->left, data);
    } else {
      insertNode(node->right, data);
    }
  }

  BinNode<T>* findMin(BinNode<T>* node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  BinNode<T>* removeNode(BinNode<T>* node, const T& data) {
    if (node == nullptr) {
      return nullptr;
    }
    if (data < node->data) {
      node->left = removeNode(node->left, data);
    } else if (data > node->data) {
      node->right = removeNode(node->right, data);
    } else {
      if (node->left == nullptr) {
        BinNode<T>* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        BinNode<T>* temp = node->left;
        delete node;
        return temp;
      } else {
        BinNode<T>* minRight = findMin(node->right);
        node->data = minRight->data;
        node->right = removeNode(node->right, minRight->data);
      }
    }
    return node;
  }
};

template <typename T>
Binary_Search_Tree<T>& Binary_Search_Tree<T>::operator=(
    const Binary_Search_Tree& other) {
  if (this != &other) {
    destroy(root);
    root = clone(other.root);
  }
  return *this;
}

template <typename T>
using BST = Binary_Search_Tree<T>;

#endif
