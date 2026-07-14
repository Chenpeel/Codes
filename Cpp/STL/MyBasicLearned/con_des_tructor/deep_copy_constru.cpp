#include <iostream>
// Define a Person Class
class Person {
public:
  Person() : name(new char[32]) { std::strcpy(name, "Alpha"); }
  Person(const Person &other) : name(new char[32]) {
    std::strcpy(name, other.name);
  }
  ~Person() { delete[] name; };

private:
  char *name;
};

// Main Func
int main(int argc, char *argv[]) {
  Person person_a; // 构造
  Person person_b(person_a);
  // 两个 person 的进行深拷贝，各自持有各自的内存
  // 析构时，两者相互隔离，无内存隐患

  return 0;
}
