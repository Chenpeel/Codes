#ifndef TRIE_HPP
#define TRIE_HPP

#include <iostream>
#include <unordered_map>

// 定义 TrieNode 结构体
struct TrieNode {
  std::unordered_map<char, TrieNode*> children;
  bool isEndOfWord;

  TrieNode() { isEndOfWord = false; }
};

// 定义 Trie 类
class Trie {
 private:
  TrieNode* root;
  TrieNode* currNode;  // 用于记录当前查找/删除的位置

 public:
  Trie() {
    root = new TrieNode();
    currNode = root;
  }

  // 插入一个字符串
  void insert(std::string word) {
    TrieNode* curr = root;
    for (char ch : word) {
      if (curr->children.find(ch) == curr->children.end()) {
        curr->children[ch] = new TrieNode();
      }
      curr = curr->children[ch];
    }
    curr->isEndOfWord = true;
  }

  // 搜索一个字符串
  bool search(std::string word) {
    TrieNode* curr = root;
    for (char ch : word) {
      if (curr->children.find(ch) == curr->children.end()) {
        return false;
      }
      curr = curr->children[ch];
    }
    return curr->isEndOfWord;
  }

  // 删除一个字符串
  void remove(std::string word) {
    currNode = root;  // 初始化当前节点为根节点
    removeHelper(word, 0);
  }

 private:
  // 辅助函数用于递归删除
  bool removeHelper(std::string& word, int index) {
    if (index == word.length()) {
      if (!currNode->isEndOfWord) {
        return false;  // 单词不存在
      }
      currNode->isEndOfWord = false;
      return currNode->children.empty();  // 判断是否有子节点
    }

    char ch = word[index];
    if (currNode->children.find(ch) == currNode->children.end()) {
      return false;  // 单词不存在
    }

    currNode = currNode->children[ch];  // 移动到下一个节点
    bool shouldRemoveCurrNode = removeHelper(word, index + 1);

    if (shouldRemoveCurrNode) {
      delete currNode;
      currNode = nullptr;
      return true;
    }

    return false;
  }
};

#endif
