#include "./tree.h"

using namespace std;

void test_binary_tree() {
  BiTree<int> binaryTree;

  binaryTree.insert(10);
  binaryTree.insert(5);
  binaryTree.insert(15);
  binaryTree.insert(3);
  binaryTree.insert(7);
  cout << "Binary Tree InOrder Traversal: ";
  InOrder(binaryTree.getRoot());
  cout << endl;
}
void test_AVL_Tree() {
  AVL_Tree<int> avlTree;
  avlTree.insert(10);
  avlTree.insert(5);
  avlTree.insert(15);
  avlTree.insert(3);
  avlTree.insert(7);

  cout << "AVL Tree InOrder Traversal: ";
  avlTree.inOrder();
  cout << endl;
}
void test_B_Tree() {
  B_Tree<int> bTree;
  bTree.insert(10);
  bTree.insert(5);
  bTree.insert(15);
  bTree.insert(3);
  bTree.insert(7);

  cout << "B Tree InOrder Traversal: ";
  bTree.print();
  cout << endl;
}
void test_binary_heap() {
  MaxHeap<int> maxHeap;
  maxHeap.insert(10);
  maxHeap.insert(5);
  maxHeap.insert(15);
  maxHeap.insert(3);
  maxHeap.insert(7);

  cout << "Max Heap elements: ";
  while (!maxHeap.isEmpty()) {
    cout << maxHeap.extractMax() << " ";
  }
  cout << endl;
}
void test_BST() {
  BST<int> bst;
  bst.insert(10);
  bst.insert(5);
  bst.insert(15);
  bst.insert(3);
  bst.insert(7);

  cout << "Binary Search Tree InOrder Traversal: ";
  InOrder(bst.getRoot());
  cout << endl;
}
void test_BPTree() {
  BPTree<int> bPlusTree;
  bPlusTree.insert(10);
  bPlusTree.insert(5);
  bPlusTree.insert(15);
  bPlusTree.insert(3);
  bPlusTree.insert(7);

  cout << "B+ Tree elements: ";
  bPlusTree.print();
  cout << endl;
}
void test_RBT() {
  RBT<int> rbTree;
  rbTree.insert(10);
  rbTree.insert(5);
  rbTree.insert(15);
  rbTree.insert(3);
  rbTree.insert(7);

  cout << "Red-Black Tree InOrder Traversal: ";
  rbTree.inOrder();
  cout << endl;
}
void test_Trie() {
  Trie trie;
  trie.insert("apple");
  trie.insert("app");
  trie.insert("banana");
  trie.insert("orange");

  cout << "Search in Trie:" << endl;
  cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found")
       << endl;
  cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found")
       << endl;
  cout << "Search 'orange': " << (trie.search("orange") ? "Found" : "Not Found")
       << endl;
  cout << "Search 'grape': " << (trie.search("grape") ? "Found" : "Not Found")
       << endl;

  trie.remove("apple");
  cout << "Search after removing 'apple': "
       << (trie.search("apple") ? "Found" : "Not Found") << endl;
}

void test_splay_tree() {
  // 创建一个伸展树对象，用于存储整数类型的数据
  Splay_Tree<int> splayTree;

  // 向伸展树中插入一些数据
  splayTree.insert(50);
  splayTree.insert(30);
  splayTree.insert(70);
  splayTree.insert(20);
  splayTree.insert(40);

  // 查找并输出结果
  int keyToFind = 30;
  if (splayTree.find(keyToFind)) {
    std::cout << keyToFind << " is found in the Splay Tree." << std::endl;
  } else {
    std::cout << keyToFind << " is not found in the Splay Tree." << std::endl;
  }

  keyToFind = 60;
  if (splayTree.find(keyToFind)) {
    std::cout << keyToFind << " is found in the Splay Tree." << std::endl;
  } else {
    std::cout << keyToFind << " is not found in the Splay Tree." << std::endl;
  }

  // 删除一个节点并查找结果
  int keyToRemove = 30;
  splayTree.remove(keyToRemove);
  if (splayTree.find(keyToRemove)) {
    std::cout << keyToRemove << " is found in the Splay Tree after removal."
              << std::endl;
  } else {
    std::cout << keyToRemove << " is not found in the Splay Tree after removal."
              << std::endl;
  }

  // 输出伸展树的遍历结果
  std::cout << "Pre-order traversal: ";
  PreOrder(splayTree.getRoot());
  std::cout << std::endl;

  std::cout << "In-order traversal: ";
  InOrder(splayTree.getRoot());
  std::cout << std::endl;

  std::cout << "Post-order traversal: ";
  PostOrder(splayTree.getRoot());
  std::cout << std::endl;

  std::cout << "Level-order traversal: ";
  LevelOrder(splayTree.getRoot());
  std::cout << std::endl;
}

int main() {
  // test_binary_tree();
  // test_BST();
  // test_AVL_Tree();
  // test_RBT();
  // test_B_Tree();
  // test_BPTree();
  // test_binary_heap();
  // test_Trie();
  test_splay_tree();
  return 0;
}
