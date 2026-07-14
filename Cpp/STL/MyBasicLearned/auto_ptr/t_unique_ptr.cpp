#include <iostream>
#include <string>
#include <memory>

// Define a Class
class Person {
public:
  Person(std::string name);
  Person() = default;
  void print_name() {
    std::cout<< "Person Name:" << name <<std::endl;
  }
  std::string get_person_name(){
		return name;
  }
  void set_person_name(const std::string &name){
    this->name = name;
  }
private:
  std::string name{"A"};
};

// Define a Function
void t_pass_value_func(std::unique_ptr<Person> person){
  person->print_name();
}
// const 修饰 person的地址
void t_pass_value_ref_func(const std::unique_ptr<Person> & person){
  person->set_person_name("beta");
  person->print_name();
  std::cout<< "ref address" << person.get() << std::endl;
  // person.reset() 由于const，reset会报错
  // 且reset会导致外部无法实例的类内调用方法，因为指针地址已经reset
}

// Main Func
int main(int argc, char *agrv[]){
  // 使用 make_unique 创建 unique_ptr (C++ 14)
  std::unique_ptr<int> i_num = std::make_unique<int> (100);
  // 使用 * 解引用
  std::cout << * i_num <<std::endl;
  // 使用 get() 方法获得指针的地址
  std::cout << "i_num address:" << i_num.get() <<std::endl;
  // 使用 -> 类内方法
  std::unique_ptr<Person> person_a = std::make_unique<Person>();
  person_a -> set_person_name("alpha");
  person_a -> print_name();
	// 所有权转移至函数内部，外部再调用会报错
  t_pass_value_func(std::move(person_a));
  // person_a -> print_name(); // 生命周期结束，无法调用，程序崩溃
  std::unique_ptr<Person> person_b = std::make_unique<Person>();
	t_pass_value_ref_func(person_b);
  return 0;
}
