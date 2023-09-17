#include <iostream>
#include <vector>
using namespace std;

void test() {
  vector<int> v;
  int num;
  int *p = nullptr;
  //reserve()预留空间
  v.reserve(100000);
  for (int i = 0; i < 100000; i++) {
    v.push_back(i);
    if (p != &v[0]) {
      p = &v[0];
      num++;
    }
  }
  cout<<num<<endl;
}

int main() {
  test();
  return 0;
}