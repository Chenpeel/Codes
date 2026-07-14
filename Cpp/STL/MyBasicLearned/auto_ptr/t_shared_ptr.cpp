#include <iostream>
#include <string>
#include <memory>

void t_pass_value_func(std::shared_ptr<int> i_num){
  // use_count() 计数器会 +1 ，因为使用了copy
  *i_num = 30;
  std::cout << "use count: " << i_num.use_count() << std::endl;
}

void t_pass_ref_func(const std::shared_ptr<int> &i_num){
  // use_count() 计数器会 不变 ，因为使用了 const 及 &， const也是限定了无法 reset()
  *i_num = 40;
  std::cout << "use count: " << i_num.use_count() << std::endl;
}

  
// Main Func
int main(int argc, char *agrv[]){
	std::shared_ptr<int> i_num = std::make_shared<int> (10);
  std::cout << "* i_num: " << * i_num << std::endl;
  std::cout << "use count: " << i_num.use_count() << std::endl;
  
  std::shared_ptr<int> i_num_copy = i_num;
  std::cout << "use count: " << i_num.use_count() << std::endl;
  std::cout << "use count: " << i_num_copy.use_count() << std::endl;
  
  // change
  *i_num_copy = 20;
  std::cout << "* i_num: " << * i_num << std::endl;
  std::cout << "* i_num_copy: " << * i_num_copy << std::endl;
  
// i_num = nullptr;  ==> i_num_copy.use_count() 返回 1，i_num.use_count() 返回 0
// i_num_copy = nullptr; ==> i_num.use_count() 返回 1，i_num_copy.use_count() 返回 0
  std::cout << "use count: " << i_num.use_count() << std::endl;
  std::cout << "use count: " << i_num_copy.use_count() << std::endl;
  t_pass_value_func(i_num); // 会在use count输出 3
  std::cout << "use count: " << i_num.use_count() << std::endl;
  std::cout << "use count: " << i_num_copy.use_count() << std::endl;
  std::cout << "* i_num: " << * i_num << std::endl; // 值也会改变
  
  t_pass_ref_func(i_num); // 会在use count输出 2
  std::cout << "use count: " << i_num.use_count() << std::endl;
  std::cout << "use count: " << i_num_copy.use_count() << std::endl;
  std::cout << "* i_num: " << * i_num << std::endl; // 值也会改变
  return 0;
}
