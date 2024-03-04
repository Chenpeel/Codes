#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void test() {
  string str1 = "I ";
  string str2 = " love learning";
  str1 += str2;
  str1 += ":";
  string str3 = " python , C++ ";
  str1 += str3;
  str1.append("!");
  str1.append(str3, 7, 8);
  cout << str1 << endl;

  string user_name = "dashabi@qq.com";
  int pos = user_name.find("@");
  cout << pos << endl;
  string name = user_name.substr(0, pos);
  cout << name << endl;
}

int main() {
  test();
  return 0;
}
