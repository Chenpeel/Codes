#include <iostream>
int main() {
  int a = 3, b = 5;
  (a > b ? a : b) = 10;
  std::cout << "a : " << a << ",b : " << b << std::endl;
  return 0;
}
