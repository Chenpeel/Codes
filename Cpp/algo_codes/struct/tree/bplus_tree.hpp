#ifndef BPLUS_TREE_HPP
#define BPLUS_TREE_HPP

#include <iostream>

const int ORDER_P = 4;  // B+树的阶
template <typename T>
class BPlus_Tree {
 private:
  struct Node {
    int num_keys;             // 当前节点包含的键值个数
    T keys[ORDER_P - 1];      // 键值数组
    Node* children[ORDER_P];  // 子节点指针数组
    Node* next;               // 指向下一个叶子节点的指针
    bool is_leaf;             // 是否是叶子节点

    Node(bool leaf = true) : num_keys(0), is_leaf(leaf), next(nullptr) {}
  };

  Node* root;

 public:
  BPlus_Tree() : root(new Node()) {}
  Node* getRoot() const { return root; }
  void insert(const T& data) {
    Node* new_node = new Node();
    new_node->keys[0] = data;
    new_node->is_leaf = true;

    if (root->num_keys == ORDER_P - 1) {
      Node* new_root = new Node(false);
      new_root->children[0] = root;
      split_child(new_root, 0);
      insert_non_full(new_root, data);
      root = new_root;
    } else {
      insert_non_full(root, data);
    }
  }

  void print() const { print_node(root, 0); }

 private:
  void insert_non_full(Node* node, const T& data) {
    int i = node->num_keys - 1;
    if (node->is_leaf) {
      while (i >= 0 && data < node->keys[i]) {
        node->keys[i + 1] = node->keys[i];
        --i;
      }
      node->keys[i + 1] = data;
      node->num_keys++;
    } else {
      while (i >= 0 && data < node->keys[i]) {
        --i;
      }
      ++i;
      if (node->children[i]->num_keys == ORDER_P - 1) {
        split_child(node, i);
        if (data > node->keys[i]) {
          ++i;
        }
      }
      insert_non_full(node->children[i], data);
    }
  }

  void split_child(Node* parent, int index) {
    Node* child = parent->children[index];
    Node* new_child = new Node(child->is_leaf);
    for (int j = 0; j < ORDER_P / 2 - 1; ++j) {
      new_child->keys[j] = child->keys[j + ORDER_P / 2];
    }
    if (!child->is_leaf) {
      for (int j = 0; j < ORDER_P / 2; ++j) {
        new_child->children[j] = child->children[j + ORDER_P / 2];
      }
    }
    child->num_keys = ORDER_P / 2 - 1;
    for (int j = parent->num_keys; j > index; --j) {
      parent->children[j + 1] = parent->children[j];
    }
    parent->children[index + 1] = new_child;
    for (int j = parent->num_keys - 1; j >= index; --j) {
      parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[index] = child->keys[ORDER_P / 2 - 1];
    ++parent->num_keys;

    if (child->is_leaf) {
      new_child->next = child->next;
      child->next = new_child;
    }
  }

  void print_node(const Node* node, int level) const {
    if (node) {
      for (int i = 0; i < level; ++i) {
        std::cout << "\t";
      }
      for (int i = 0; i < node->num_keys; ++i) {
        std::cout << node->keys[i] << " ";
      }
      std::cout << std::endl;
      if (!node->is_leaf) {
        for (int i = 0; i <= node->num_keys; ++i) {
          print_node(node->children[i], level + 1);
        }
      }
    }
  }
};

template <typename T>
using BPTree = BPlus_Tree<T>;

#endif
