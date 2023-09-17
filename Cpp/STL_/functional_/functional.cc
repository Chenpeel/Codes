#include <algorithm>
#include <functional>  //内建仿函数
#include <iostream>
#include <vector>
using namespace std;

void default_test() {
  // 算数仿函数
  negate<int> n;  // 一元
  cout << n(50) << endl;
  plus<int> p;
  cout << p(10, 100) << endl;
  // minus<int> m;
  //  multiplies<int>mp;
  //  divides<int>d;
  //  modulus<int>md;
}

void relation_test() {
  // 关系仿函数
  vector<int> v;
  v.push_back(1);
  v.push_back(9);
  v.push_back(7);
  v.push_back(3);
  sort(v.begin(), v.end(), greater<int>());
  // 关系比较器
  // greater<int>() == class mycompare{};
}

void logical_test() {
  // 逻辑仿函数
  vector<bool> v;
  v.push_back(true);
  v.push_back(false);
  v.push_back(true);
  v.push_back(false);
  v.push_back(false);
  // 利用逻辑非 将v搬运到v2中，并取反
  for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  vector<bool> v2;
  v2.resize(v.size());
  transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
  // logical_and<bool>()
  // logical_or<bool>()

  for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

int main() {
  default_test();
  logical_test();
  return 0;
}