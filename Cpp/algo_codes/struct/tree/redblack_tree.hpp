/*
红黑树（Red-Black
Tree）：自平衡二叉搜索树通过维持一些特定的性质来保持树的平衡，从而保证在最坏情况下仍然具有较高的性能。
红黑树是由 Rudolf Bayer 和 Volker Günther
在1972年提出的，它是在AVL树的基础上进行优化得到的一种自平衡二叉搜索树。
在红黑树中，每个节点被标记为红色或黑色，同时满足以下红黑树性质：
(1)每个节点是红色或黑色。
(2)根节点是黑色。
(3)每个叶子节点（NIL节点，即空节点）是黑色。
(4)如果一个节点是红色，那么它的两个子节点都是黑色。
(5)从任意节点到其每个叶子节点的所有路径都包含相同数量的黑色节点。

红黑树保持了相对较好的平衡性能，插入和删除操作的平均时间复杂度为O(log
n)，且在维护平衡性方面相对于AVL树要简单。
*/
#ifndef REDBLACK_TREE_HPP
#define REDBLACK_TREE_HPP

#include <iostream>

enum Color { RED, BLACK };

template <typename T>
class RedBlack_Tree {
 private:
  struct BinNode {
    T data;
    Color color;
    BinNode* left;
    BinNode* right;
    BinNode* parent;

    BinNode(const T& data, Color color = RED)
        : data(data),
          color(color),
          left(nullptr),
          right(nullptr),
          parent(nullptr) {}
  };

  BinNode* root;

 public:
  RedBlack_Tree() : root(nullptr) {}
  ~RedBlack_Tree() { destroy(root); }
  RedBlack_Tree(const RedBlack_Tree& other) { root = clone(other.root); }
  RedBlack_Tree& operator=(const RedBlack_Tree& other);
  BinNode* getRoot() const { return root; }
  void insert(const T& data) {
    BinNode* new_node = new BinNode(data);
    root = insertNode(root, new_node);
    adjustAfterInsert(new_node);
  }

  void inOrder() const { inOrderTraversal(root); }

 private:
  void destroy(BinNode* node) {
    if (node) {
      destroy(node->left);
      destroy(node->right);
      delete node;
    }
  }

  BinNode* insertNode(BinNode* root, BinNode* new_node) {
    if (root == nullptr) {
      return new_node;
    }

    if (new_node->data < root->data) {
      root->left = insertNode(root->left, new_node);
      root->left->parent = root;
    } else if (new_node->data > root->data) {
      root->right = insertNode(root->right, new_node);
      root->right->parent = root;
    } else {
      // Duplicate values are not allowed in red-black tree.
      delete new_node;
    }

    return root;
  }

  void adjustAfterInsert(BinNode* node) {
    while (node != root && node->parent->color == RED) {
      if (node->parent == node->parent->parent->left) {
        BinNode* uncle = node->parent->parent->right;
        if (uncle && uncle->color == RED) {
          // Case 1: Uncle is red, then recolor parent, uncle, and grandparent
          node->parent->color = BLACK;
          uncle->color = BLACK;
          node->parent->parent->color = RED;
          node = node->parent->parent;
        } else {
          if (node == node->parent->right) {
            // Case 2: Uncle is black and node is a right child, then rotate
            // left
            node = node->parent;
            rotateLeft(node);
          }
          // Case 3: Uncle is black and node is a left child, then recolor
          // parent and grandparent, then rotate right
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          rotateRight(node->parent->parent);
        }
      } else {
        BinNode* uncle = node->parent->parent->left;
        if (uncle && uncle->color == RED) {
          // Case 1: Uncle is red, then recolor parent, uncle, and grandparent
          node->parent->color = BLACK;
          uncle->color = BLACK;
          node->parent->parent->color = RED;
          node = node->parent->parent;
        } else {
          if (node == node->parent->left) {
            // Case 2: Uncle is black and node is a left child, then rotate
            // right
            node = node->parent;
            rotateRight(node);
          }
          // Case 3: Uncle is black and node is a right child, then recolor
          // parent and grandparent, then rotate left
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          rotateLeft(node->parent->parent);
        }
      }
    }
    root->color = BLACK;
  }

  void rotateLeft(BinNode* node) {
    BinNode* y = node->right;
    node->right = y->left;
    if (y->left) {
      y->left->parent = node;
    }
    y->parent = node->parent;
    if (!node->parent) {
      root = y;
    } else if (node == node->parent->left) {
      node->parent->left = y;
    } else {
      node->parent->right = y;
    }
    y->left = node;
    node->parent = y;
  }

  void rotateRight(BinNode* node) {
    BinNode* x = node->left;
    node->left = x->right;
    if (x->right) {
      x->right->parent = node;
    }
    x->parent = node->parent;
    if (!node->parent) {
      root = x;
    } else if (node == node->parent->left) {
      node->parent->left = x;
    } else {
      node->parent->right = x;
    }
    x->right = node;
    node->parent = x;
  }

  void inOrderTraversal(const BinNode* node) const {
    if (node) {
      inOrderTraversal(node->left);
      std::cout << node->data << " ";
      inOrderTraversal(node->right);
    }
  }

  BinNode* clone(const BinNode* node) {
    if (!node) return nullptr;
    return new BinNode(node->data, node->color, clone(node->left),
                       clone(node->right));
  }
};

template <typename T>
RedBlack_Tree<T>& RedBlack_Tree<T>::operator=(const RedBlack_Tree& other) {
  if (this != &other) {
    destroy(root);
    root = clone(other.root);
  }
  return *this;
}

template <typename T>
using RBT = RedBlack_Tree<T>;

#endif
