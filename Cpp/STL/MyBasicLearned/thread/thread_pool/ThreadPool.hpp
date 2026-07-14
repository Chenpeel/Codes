#include <condition_variable>
#include <cstddef>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <type_traits>
#include <vector>

class ThreadPool {
public:
  ThreadPool(std::size_t thread_nums);
  template <typename F, typename... Arg>
  auto enqueue(F &&f, Arg &&...arg)
      -> std::future<std::invoke_result_t<F, Arg...>>;
  ~ThreadPool();

private:
  void worker();
  bool _stop;
  std::condition_variable _condi_var;
  std::mutex _mutex;
  std::vector<std::thread> _workers;
  std::queue<std::function<void()>> _work_queue;
};

//
ThreadPool::ThreadPool(size_t thread_nums) : _stop(false) {
  for (size_t i = 0; i < thread_nums; i++) {
    _workers.emplace_back([this]() { this->worker(); });
  }
}
//
ThreadPool::~ThreadPool() {
  {
    std::scoped_lock lock(_mutex);
    _stop = true;
  }
  _condi_var.notify_all();
  for (std::thread &onethread : _workers) {
    onethread.join();
  }
}
//
template <typename F, typename... Arg>
auto ThreadPool::enqueue(F &&f, Arg &&...arg)
    -> std::future<std::invoke_result_t<F, Arg...>> {
  using func_type = typename std::invoke_result_t<F, Arg...>;
  auto task = std::make_shared<std::packaged_task<func_type()>>(
      std::bind(std::forward<F>(f), std::forward<Arg>(arg)...));
  std::future<func_type> rs_future = task->get_future();
  {
    std::lock_guard<std::mutex> lock_guard(this->_mutex);
    if (_stop) {
      throw std::runtime_error("Error, Thread has stopped");
    }
    _work_queue.emplace([task]() { (*task)(); });
  }
  _condi_var.notify_one();
  return rs_future;
}

void ThreadPool::worker() {
  while (true) {
    std::function<void()> task;
    {
      std::unique_lock<std::mutex> lock(_mutex);
      _condi_var.wait(
          lock, [this] { return this->_stop || !this->_work_queue.empty(); });
      if (_stop && _work_queue.empty()) {
        return;
      }
      task = std::move(this->_work_queue.front());
      this->_work_queue.pop();
    }
    task();
  }
}
