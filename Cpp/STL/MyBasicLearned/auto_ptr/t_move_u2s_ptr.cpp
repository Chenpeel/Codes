#include <iostream>
#include <string>
#include <memory>

// return unique_ptr func
std::unique_ptr<int> t_get_unique_ptr(){
  std::unique_ptr<int> tmp = std::make_unique<int>(-1);
  return tmp;
}

// Main Func
int main(int argc, char *agrv[]){
  std::unique_ptr<int> i_unique_num = std::make_unique<int>(10);
  std::shared_ptr<int> i_shared_num = std::move(i_unique_num);
  std::cout << "* i_shared_num: " << * i_shared_num << std::endl; 
  std::cout << "use count: " << i_shared_num.use_count() << std::endl;
  
  //t_func
  std::shared_ptr<int> t_func = t_get_unique_ptr();
  if(t_func){
    std::cout << "* t_func: " << * t_func << std::endl;  
		std::cout << "use count: " << t_func.use_count() << std::endl;
  }
  return 0;
}
