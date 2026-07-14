#include <iostream>
// Define a Person Class
class Person {
public:
  Person() : name(new char[32]) { std::strcpy(name, "Alpha"); }
  ~Person() { delete[] name; };

private:
  char *name;
};

// Main Func
int main(int argc, char *argv[]) {
  Person person_a; // 默认构造
  Person person_b(person_a);
  // 两个 person 的内部指针会指向同一块内存
  // 析构时，同一块内存会delete两次，程序崩溃

  return 0;
}
