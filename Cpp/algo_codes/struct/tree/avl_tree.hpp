#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

/*
AVL树（Adelson-Velsky and Landis
Tree）：自平衡二叉搜索树通过维持一些特定的性质来保持树的平衡，从而保证在最坏情况下仍然具有较高的性能。
(1)AVL树是由两位俄罗斯数学家 Adelson-Velsky 和 Landis
在1962年提出的，它是最早被发明的自平衡二叉搜索树之一。
(2)在AVL树中，对于任意节点，其左子树和右子树的高度差（平衡因子）不超过1，即每个节点的平衡因子只能是-1、0或1。
(3)当在AVL树中插入或删除节点后，可能会导致树的平衡被破坏，这时需要通过旋转操作来重新恢复树的平衡。
(4)AVL树相比于红黑树，提供了更强的平衡性，因此在某些特定场景下性能可能更优，但维护平衡的代价较高，所以在频繁插入删除的场景下，会有更多的旋转操作。

*/

#include <iostream>

template <typename T>
class AVL_Tree {
 private:
  struct BinNode {
    T data;
    int height;
    BinNode* left;
    BinNode* right;

    BinNode(const T& data)
        : data(data), height(1), left(nullptr), right(nullptr) {}
  };

  BinNode* root;

 public:
  AVL_Tree() : root(nullptr) {}
  ~AVL_Tree() { destroy(root); }
  AVL_Tree(const AVL_Tree& other) { root = clone(other.root); }
  AVL_Tree& operator=(const AVL_Tree& other);
  BinNode* getRoot() const { return root; }
  void insert(const T& data) {
    if (root)
      root = insertNode(root, data);
    else
      root = new BinNode(data);
  }
  void inOrder() const { inOrderTraversal(root); }

 private:
  int getHeight(BinNode* node) const {
    if (node == nullptr) {
      return 0;
    }
    return node->height;
  }

  int getBalanceFactor(BinNode* node) const {
    if (node == nullptr) {
      return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
  }

  int calculateHeight(BinNode* node) const {
    if (node == nullptr) {
      return 0;
    }
    return 1 + std::max(getHeight(node->left), getHeight(node->right));
  }

  BinNode* rotateRight(BinNode* y) {
    BinNode* x = y->left;
    BinNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = calculateHeight(y);
    x->height = calculateHeight(x);

    return x;
  }

  BinNode* rotateLeft(BinNode* x) {
    BinNode* y = x->right;
    BinNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = calculateHeight(x);
    y->height = calculateHeight(y);

    return y;
  }

  BinNode* insertNode(BinNode* node, const T& data) {
    if (node == nullptr) {
      return new BinNode(data);
    }

    if (data < node->data) {
      node->left = insertNode(node->left, data);
    } else if (data > node->data) {
      node->right = insertNode(node->right, data);
    } else {
      // Duplicate values are not allowed in AVL tree.
      return node;
    }

    node->height = calculateHeight(node);

    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data) {
      return rotateRight(node);
    }

    // Right Right Case
    if (balance < -1 && data > node->right->data) {
      return rotateLeft(node);
    }

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
      node->left = rotateLeft(node->left);
      return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
      node->right = rotateRight(node->right);
      return rotateLeft(node);
    }

    return node;
  }

  void destroy(BinNode* node) {
    if (node) {
      destroy(node->left);
      destroy(node->right);
      delete node;
    }
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
    return new BinNode(node->data, clone(node->left), clone(node->right));
  }
};

template <typename T>
AVL_Tree<T>& AVL_Tree<T>::operator=(const AVL_Tree& other) {
  if (this != &other) {
    destroy(root);
    root = clone(other.root);
  }
  return *this;
}

#endif
