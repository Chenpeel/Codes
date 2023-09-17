#ifndef SPLAY_TREE_HPP
#define SPLAY_TREE_HPP

#include <iostream>
#include <queue>

#include "binary_tree.hpp"

template <typename T>
class Splay_Tree {
 private:
  BinNode<T>* root;

 public:
  Splay_Tree() : root(nullptr) {}
  ~Splay_Tree() { destroy(root); }
  BinNode<T>* getRoot() const { return root; }
  Splay_Tree(const Splay_Tree& other) { root = clone(other.root); }
  Splay_Tree& operator=(const Splay_Tree& other);

  BinNode<T>* getRoot() const { return root; }
  void insert(const T& data) {
    insertNode(root, data);
    splay(data);
  }
  bool find(const T& data) {
    BinNode<T>* foundNode = findNode(root, data);
    if (foundNode) {
      splay(data);
      return true;
    }
    return false;
  }
  void remove(const T& data) {
    if (find(data)) {
      BinNode<T>* leftSubtree = root->left;
      BinNode<T>* rightSubtree = root->right;
      delete root;
      if (!leftSubtree) {
        root = rightSubtree;
      } else {
        root = leftSubtree;
        splay(data);
        root->right = rightSubtree;
      }
    }
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

  BinNode<T>* findNode(BinNode<T>* node, const T& data) const {
    if (!node || node->data == data) {
      return node;
    }

    if (data < node->data) {
      return findNode(node->left, data);
    } else {
      return findNode(node->right, data);
    }
  }

  void leftRotate(BinNode<T>*& node) {
    BinNode<T>* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node = temp;
  }

  void rightRotate(BinNode<T>*& node) {
    BinNode<T>* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node = temp;
  }

  void splay(const T& data) {
    while (root && root->data != data) {
      BinNode<T>* target = findNode(root, data);
      if (!target) return;  // Node not found in the tree
      if (target == root->left || target == root->right) {
        if (target == root->left) {
          rightRotate(root);
        } else {
          leftRotate(root);
        }
      } else {
        BinNode<T>* parent =
            target->data < root->data ? root->left : root->right;
        if (target == parent->left && parent == root->left) {
          rightRotate(root->left);
          rightRotate(root);
        } else if (target == parent->right && parent == root->right) {
          leftRotate(root->right);
          leftRotate(root);
        } else if (target == parent->right && parent == root->left) {
          leftRotate(root->left);
          rightRotate(root);
        } else {
          rightRotate(root->right);
          leftRotate(root);
        }
      }
    }
  }
};

template <typename T>
Splay_Tree<T>& Splay_Tree<T>::operator=(const Splay_Tree& other) {
  if (this != &other) {
    destroy(root);
    root = clone(other.root);
  }
  return *this;
}

#endif
