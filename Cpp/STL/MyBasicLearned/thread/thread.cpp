#include <iostream>
#include <thread>

bool thre_finished = false;

void do_work() {
  using namespace std::literals::chrono_literals;
  while (!thre_finished) {
    std::cout << "working" << std::endl;
    std::this_thread::sleep_for(1s);
  }
}

int main(int argc, char *argv[]) {
  std::thread worker(do_work);
  std::cin.get();
  thre_finished = true;
  worker.join();
  std::cout << "Finished" << std::endl;
  std::cin.get();
  return 0;
}
