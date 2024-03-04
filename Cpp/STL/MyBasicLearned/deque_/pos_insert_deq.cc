#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

void print(const deque<int> d) {
  // const deque必须使用const_iterator
  for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}
void test() {
  deque<int> d1;
  for (int i = 0; i < 10; i++) {
    d1.push_back(i);
  }

  d1.insert(d1.end(), 11);
  d1.insert(d1.end(), 10, 10);
  d1.insert(d1.end(), d1.begin(), d1.end());  // 在d1.end()插入全部元素

  print(d1);

  // 访问
  cout << d1.at(0) << endl;
  cout << d1[1] << endl;
  cout << d1.front() << endl;
  cout << d1.back() << endl;

  // sort in algorithm
  sort(d1.begin(),d1.end());
  print(d1);

  d1.erase(d1.begin() + 10, d1.end());
  print(d1);
  d1.erase(d1.begin());
  print(d1);
  d1.clear();
  print(d1);
}

int main() {
  test();
  return 0;
}