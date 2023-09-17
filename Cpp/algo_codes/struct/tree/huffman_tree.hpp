#ifndef HUFFMAN_TREE_HPP
#define HUFFMAN_TREE_HPP

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

template <typename T>
class HuffmanTree {
 private:
  struct Node {
    T data;
    int frequency;
    Node* left;
    Node* right;

    Node(T data, int frequency)
        : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
  };

  struct Compare {
    bool operator()(Node* a, Node* b) { return a->frequency > b->frequency; }
  };

  Node* root;

  void buildHuffmanTree(const std::unordered_map<T, int>& frequencies) {
    std::priority_queue<Node*, std::vector<Node*>, Compare> minHeap;

    for (const auto& entry : frequencies) {
      Node* newNode = new Node(entry.first, entry.second);
      minHeap.push(newNode);
    }

    while (minHeap.size() > 1) {
      Node* left = minHeap.top();
      minHeap.pop();
      Node* right = minHeap.top();
      minHeap.pop();

      Node* combinedNode = new Node('\0', left->frequency + right->frequency);
      combinedNode->left = left;
      combinedNode->right = right;

      minHeap.push(combinedNode);
    }

    root = minHeap.top();
  }

  void destroyTree(Node* node) {
    if (node) {
      destroyTree(node->left);
      destroyTree(node->right);
      delete node;
    }
  }

  void printHuffmanCodes(
      Node* node, std::string code,
      std::unordered_map<T, std::string>& huffmanCodes) const {
    if (node == nullptr) {
      return;
    }

    if (node->data != '\0') {
      huffmanCodes[node->data] = code;
    }

    printHuffmanCodes(node->left, code + "0", huffmanCodes);
    printHuffmanCodes(node->right, code + "1", huffmanCodes);
  }

 public:
  HuffmanTree() : root(nullptr) {}
  Node* getRoot() const { return root; }
  HuffmanTree(const std::unordered_map<T, int>& frequencies) {
    buildHuffmanTree(frequencies);
  }

  ~HuffmanTree() { destroyTree(root); }

  std::unordered_map<T, std::string> getHuffmanCodes() const {
    std::unordered_map<T, std::string> huffmanCodes;
    printHuffmanCodes(root, "", huffmanCodes);
    return huffmanCodes;
  }
};

#endif
