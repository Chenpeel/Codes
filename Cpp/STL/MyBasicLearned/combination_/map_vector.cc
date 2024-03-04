#include <iostream>
#include <map>
#include <string>
#include <vector>
 
using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

// 仿函数
class Id_ {
 public:
  int id_;
  Id_() { this->id_ = 2021304300; }
  void operator()(int i) { this->id_++; }
};

class Staff {
 public:
  string name;
  int salary;
  int id;
};
// 打印全部信息
void print_info(vector<Staff>& v) {
  for (vector<Staff>::iterator it = v.begin(); it != v.end(); it++) {
    cout << "name: " << it->name << endl
         << "id: " << it->id << endl
         << "salary: " << it->salary << endl
         << endl;
  }
}

// 创建成员
void createstaff(vector<Staff>& v, int id) {
  string s = "ASDFGMNBVC";
  Id_ id_;
  for (int i = 0; i < 10; i++) {
    Staff staff;
    staff.name = "staff: ";
    staff.name += s[i];
    id_(0);
    staff.id = id_.id_;
    staff.salary = random() % 10000 + 10000;
    v.push_back(staff);
  }
}

// 建立分组
void set_group(vector<Staff>& v, multimap<int, Staff>& m) {
  for (vector<Staff>::iterator it = v.begin(); it != v.end(); it++) {
    int dept_id = rand() % 3;
    m.insert(make_pair(dept_id, *it));
  }
}

// 以分组形式显示
void show_by_group(multimap<int, Staff>& m) {
  cout << "CEHUA:" << endl;
  multimap<int, Staff>::iterator pos = m.find(CEHUA);
  int count = m.count(CEHUA);
  cout << count << endl << endl;
  int index = 0;
  for (; pos != m.end() && index < count; pos++, index++) {
    cout << "name: " << pos->second.name << endl
         << "id: " << pos->second.id << endl
         << "salary: " << pos->second.salary << endl
         << endl;
  }
  cout << "--------------------" << endl;
  cout << "MEISHU" << endl;
  count = m.count(MEISHU);
  cout << count << endl << endl;
  index = 0;
  for (; pos != m.end() && index < count; pos++, index++) {
    cout << "name: " << pos->second.name << endl
         << "id: " << pos->second.id << endl
         << "salary: " << pos->second.salary << endl
         << endl;
  }
  cout << "--------------------" << endl;
  cout << "YANFA" << endl;
  count = m.count(MEISHU);
  cout << count << endl << endl;
  index = 0;
  for (; pos != m.end() && index < count; pos++, index++) {
    cout << "name: " << pos->second.name << endl
         << "id: " << pos->second.id << endl
         << "salary: " << pos->second.salary << endl
         << endl;
  }
}

int main() {
  vector<Staff> v;
  int id = 0;
  createstaff(v, id);
  multimap<int, Staff> m;
  set_group(v, m);
  show_by_group(m);
  // print_info(v);
  return 0;
}