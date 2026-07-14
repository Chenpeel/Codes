#include <boost/any/basic_any.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

int main() {
  boost::shared_ptr<int> p1{new int{1}};
  std::cout << *p1 << std::endl;
}
