#include <iostream>
#include <string>
// Define a Person Class
class Person {
  friend void t_copy_constructor_value(Person person);
  friend void t_copy_constructor_ref(const Person &person);

public:
  Person() = default;
  Person(const Person &person) {
    std::cout << "default copy constructor" << std::endl;
    this->name = person.name;
  }
  ~Person() = default;

private:
  std::string name{"Alpha"};
};

// 传参构造
void t_copy_constructor_value(Person person) {
  // 会有一次输出 default copy constructor
  std::cout << person.name << std::endl;
}
// 引用传递则无构造
void t_copy_constructor_ref(const Person &person) {
  std::cout << person.name << std::endl;
}

// Main Func
int main(int argc, char *argv[]) {
  Person person_a;                    // 默认构造
  Person person_b(person_a);          // 拷贝构造
  t_copy_constructor_value(person_a); // 函数值传递
  t_copy_constructor_ref(person_a);
  return 0;
}
