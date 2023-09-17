#include "./struct/tree/huffman_tree.hpp"
#include <vector>

int main() {
  // 给定字符集和频率
  std::unordered_map<char, int> frequencies = {
      {'a', 22}, {'b', 13}, {'c', 7}, {'d', 6},  {'e', 20},
      {'f', 10}, {'g', 7},  {'h', 6}, {'i', 10}, {'j', 7}};

  // 构建哈夫曼树
  HuffmanTree<char> huffmanTree(frequencies);

  // 获取哈夫曼编码
  std::unordered_map<char, std::string> huffmanCodes =
      huffmanTree.getHuffmanCodes();

  // 输出哈夫曼编码
  std::cout << "Huffman Codes:" << std::endl;
  for (const auto& entry : huffmanCodes) {
    std::cout << entry.first << ": " << entry.second << std::endl;
  }

  return 0;
}
