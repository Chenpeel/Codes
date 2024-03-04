#include <deque>
#include <iostream>
#include <vector>

using namespace std;

void print(const deque<int> d) {
  // const deque必须使用const_iterator
  for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void print(const vector<int> v) {
  // const deque必须使用const_iterator
  for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  F cout << endl;
}
/**
 * @brief
 * deque just like vector,but there's a central controller to control the
 * address deque do not have the capacity
 */

void test() {
  deque<int> d1;
  for (int i = 0; i < 10; i++) {
    d1.push_back(i);   // add the last one
    d1.push_front(i);  // insert the first one
  }
  vector<int> v1;
  for (int i = 0; i < 10; i++) {
    v1.push_back(d1[i]);
  }
  print(d1);
  d1.pop_back();   // delete the last one
  d1.pop_front();  // delete the first one
  print(d1);

  if (d1.empty()) {
    cout << "Empty" << endl;
    cout << d1.size() << endl;
  }
  // resize
  //   d1.resize(15,0);
  print(d1);
  print(v1);
}

int main() {
  test();
  return 0;
}