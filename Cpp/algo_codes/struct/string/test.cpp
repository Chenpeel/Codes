#include "./string.hpp"

int main() {
  MyString str1;
  str1 = "Hello";
  MyString str2;
  str2 = "World";

  std::cout << "Length of str1: " << str1.getLength() << std::endl;
  std::cout << "Length of str2: " << str2.getLength() << std::endl;

  int compareResult = str1.compare(str2);
  if (compareResult < 0) {
    std::cout << "str1 is less than str2" << std::endl;
  } else if (compareResult > 0) {
    std::cout << "str1 is greater than str2" << std::endl;
  } else {
    std::cout << "str1 is equal to str2" << std::endl;
  }

  MyString concatResult = str1.concat(str2);
  std::cout << "Concatenated string: ";
  concatResult.print();

  MyString sub = concatResult.substring(1, 5);
  std::cout << "Substring: ";
  sub.print();

  MyString copy;
  copy.copy(concatResult);
  std::cout << "Copied string: ";
  copy.print();

  return 0;
}