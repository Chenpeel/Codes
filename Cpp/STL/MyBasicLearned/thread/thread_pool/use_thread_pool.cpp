#include "ThreadPool.hpp"
#include <iostream>
#include <vector>

int main() {
  ThreadPool pool(4);
  std::vector<std::future<int>> futures;

  for (size_t i = 0; i < 20; i++) {
    futures.push_back(pool.enqueue([](int a, int b) -> int { return a + b; },
                                   10 * i, 10 * i));
  }

  for (size_t i = 0; i < futures.size(); i++) {
    std::cout << "Task " << i << "\t\tresult: " << futures[i].get()
              << std::endl;
  }

  return 0;
}
