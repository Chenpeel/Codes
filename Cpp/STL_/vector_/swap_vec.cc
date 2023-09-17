#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v) {
  for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void test() {
  vector<int> v1;
  for (int i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  print(v1);
  vector<int> v2;
  for (int i = 9; i > -1; i--) {
    v2.push_back(i);
  }
  print(v2);

  swap(v1, v2);
  print(v1);
  print(v2);
}

void test_() {
  vector<int> v3;
  for (int i = 0; i < 10000; i++) {
    v3.push_back(i);
  }
  cout << "capacity: " << v3.capacity() << endl;
  cout << "size: " << v3.size() << endl;
  v3.resize(10);
  cout << "size: " << v3.size() << endl;
  vector<int>(v3).swap(v3);
  // swap(vector<int>v)收缩v容量,拷贝构造的v交换后被系统释放
  cout << "capacity: " << v3.capacity() << endl;
  cout << "size: " << v3.size() << endl;
}

int main() {
  test();
  test_();
  return 0;
}