#include <iostream>
#include <string>
#include <memory>

// Define a Class
class Person {
public:
  Person(std::string name);
  Person() = default;
  ~Person();
  void print_name() {
    std::cout<< "Person Name:" << name <<std::endl;
  }
  std::string get_person_name(){
		return name;
  }
  void set_person_name(const std::string &name){
    this->name = name;
  }
  void set_friend(std::shared_ptr<Person> person){
    __friend = person;
  }
private:
  std::string name{"A"};
  std::weak_ptr<Person> __friend;
};
// Main Func
int main(int argc, char *agrv[]){
  
	std::shared_ptr<int> i_shared_num = std::make_shared<int> (10);
  std::weak_ptr<int> i_weak_num(i_shared_num);
  std::cout << "use count: " << i_shared_num.use_count() << std::endl;//引用计数不变
  std::cout << "use count: " << i_weak_num.use_count() << std::endl;//引用计数不变
  // 通过lock()转化为shared_ptr
  std::shared_ptr<int> i_back_shared_num = i_weak_num.lock();
  std::cout << "use count: " << i_weak_num.use_count() << std::endl;//+1
  std::cout << "use count: " << i_shared_num.use_count() << std::endl;// +1
  std::cout << "use count: " << i_back_shared_num.use_count() << std::endl;// +1
  
  // 循环依赖
  std::shared_ptr<Person> person_a = std::make_shared<Person>("person_a");
  std::shared_ptr<Person> person_b = std::make_shared<Person>("person_b");
  
  person_a->set_friend(person_b);
  person_b->set_friend(person_a);
  
  return 0;
}

