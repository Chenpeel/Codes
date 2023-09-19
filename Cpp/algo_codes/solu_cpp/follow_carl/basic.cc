#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

// for_each()
void print(int val) { cout << val << " "; }
class print_ {
 public:
  void operator()(int val) { cout << val << " "; }
};
void for_each_test() {
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(random() % 100 + 1);
  }
  for_each(v.begin(), v.end(), print);
  cout << endl;
  for_each(v.begin(), v.end(), print_());
  cout << endl;
}

// transform
class trans {
 public:
  int operator()(int val) { return val; }
};
void transform_test() {
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(random() % 1000 + 1);
  }
  vector<int> vTarget;
  vTarget.resize(v.size());
  transform(v.begin(), v.end(), vTarget.begin(), trans());
  // 提供了一个逻辑运算的入口
  for_each(vTarget.begin(), vTarget.end(), print_());
  cout << endl;
}

// find __default__
void find_test() {
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(random() % 1000 + 1);
  }
  vector<int>::iterator it = find(v.begin(), v.end(), 50);
  cout << *it << endl;  // not found -> it = v.end()
}
// find_person
class Person {
 public:
  string name;
  int age;
  Person(string name, int age) {
    this->age = age;
    this->name = name;
  }
  // 重载find()方法的比较参数
  bool operator==(const Person &p) {
    if (this->name == p.name && this->age == p.age) return true;
    return false;
  }
};
void find_person_test() {
  vector<Person> v;
  Person p1("aa", 10);
  Person p2("cc", 29);
  v.push_back(p1);
  v.push_back(p2);
  vector<Person>::iterator it = find(v.begin(), v.end(), p2);
  cout << it->name << ": " << it->age << endl;
}

// find_if __default__
class greater_eighth {
 public:
  bool operator()(int val) { return val > 80; }
};
void find_if_test() {
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(random() % 100 + 1);
  }
  vector<int>::iterator it = find_if(v.begin(), v.end(), greater_eighth());
  // 找到的第一个
  cout << *it << endl;
}
// find_if_person
class greater_twenty {
 public:
  bool operator()(Person &p) { return p.age > 20; }
};
void find_if_person() {
  vector<Person> v;
  Person p1("aa", 10);
  Person p2("cc", 29);
  v.push_back(p1);
  v.push_back(p2);
  vector<Person>::iterator it = find_if(v.begin(), v.end(), greater_twenty());
  cout << it->name << ": " << it->age << endl;
}

// adjacent_find 相邻重复元素
void adjacent_find_test() {
  vector<int> v;
  v.push_back(0);
  v.push_back(3);
  v.push_back(2);
  v.push_back(0);
  v.push_back(3);
  v.push_back(3);
  vector<int>::iterator it = adjacent_find(v.begin(), v.end());
  cout << *it << endl;
}

// binary_search 指定元素是否存在 return true or false
// 必须有序
void binary_search_test() {
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    // v.push_back(random() % 10 + 1);//this could not found
    v.push_back(i);
  }
  bool judge = binary_search(v.begin(), v.end(), 9);
  if (judge) cout << "9 was found" << endl;
}

// count __default__
void count_test() {
  vector<int> v;
  v.push_back(0);
  v.push_back(3);
  v.push_back(2);
  v.push_back(0);
  v.push_back(3);
  v.push_back(3);
  v.push_back(3);
  cout << count(v.begin(), v.end(), 3) << endl;
}

// count_person
class Person_count {
 public:
  string name;
  int age;
  Person_count(string name, int age) {
    this->age = age;
    this->name = name;
  }
  // 重载find()方法的比较参数
  bool operator==(const Person_count &p) {
    if (this->age == p.age) return true;
    return false;
  }
};
void count_person() {
  vector<Person_count> v;
  Person_count p1("aa", 10);
  Person_count p2("cc", 29);
  Person_count p3("hk", 29);
  v.push_back(p1);
  v.push_back(p2);
  v.push_back(p3);

  Person_count p("oo", 29);

  cout << "Person Same Age: " << count(v.begin(), v.end(), p) << endl;
}

// count_if(iterator begin,iterator end, _Pred)
// count_if_person(iterator begin,iterator end, person)

// sort
void sort_test() {
  vector<int> v;
  for (int i = 0; i < 20; i++) {
    v.push_back(random() % 100 + 1);
  }
  sort(v.begin(), v.end());
  cout << "Sorted nums : ";
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
}

// random_shuffle 洗牌
void random_shuffle_test() {
  vector<int> v;
  for (int i = 0; i < 20; i++) {
    v.push_back(random() % 100 + 1);
  }
  sort(v.begin(), v.end());
  
}

int main() {
  for_each_test();
  transform_test();
  find_test();
  find_person_test();
  find_if_test();
  find_if_person();
  adjacent_find_test();
  binary_search_test();
  count_test();
  count_person();
  sort_test();
  return 0;
}