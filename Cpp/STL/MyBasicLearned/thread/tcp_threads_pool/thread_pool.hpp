#pragma once

#include <atomic>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <type_traits>
#include <vector>

/**
 * @brief 固定大小的线程池
 *
 * 构造时启动 N 个 worker 线程，这些线程在后台循环等待任务。
 * 通过 enqueue() 提交任务，返回 std::future 以便调用方获取结果。
 * 析构时自动 join 所有线程（RAII）。
 *
 * 典型用法:
 * @code
 *   ThreadPool pool(4);
 *   auto future = pool.enqueue([](int x) { return x * 2; }, 21);
 *   int result = future.get();  // 42
 * @endcode
 */
class ThreadPool {
public:
  /// @param num_threads worker 线程数量（默认取硬件并发数）
  explicit ThreadPool(size_t num_threads = std::thread::hardware_concurrency())
      : stop_(false) {
    std::cout << "[ThreadPool] 创建 " << num_threads << " 个 worker 线程\n";
    workers_.reserve(num_threads);
    for (size_t i = 0; i < num_threads; ++i) {
      workers_.emplace_back(&ThreadPool::worker_loop, this, i);
    }
  }

  /// 析构时通知所有线程停止并 join（RAII 核心）
  ~ThreadPool() {
    {
      std::lock_guard<std::mutex> lock(queue_mutex_);
      stop_ = true;
    }
    cv_.notify_all(); // 唤醒所有阻塞在 cv_.wait 上的线程

    for (std::thread &worker : workers_) {
      if (worker.joinable()) {
        worker.join();
      }
    }
    std::cout << "[ThreadPool] 所有线程已退出\n";
  }

  // 禁止拷贝与移动
  ThreadPool(const ThreadPool &) = delete;
  ThreadPool &operator=(const ThreadPool &) = delete;

  /**
   * @brief 提交一个任务到线程池
   *
   * @tparam F  可调用对象类型（函数、lambda、std::function 等）
   * @tparam Args 参数类型包
   * @param f   可调用对象
   * @param args 参数
   * @return std::future<返回类型>  用于异步获取任务结果
   *
   * 示例:
   *   auto fut = pool.enqueue([](int a, int b) { return a + b; }, 3, 4);
   *   int sum = fut.get(); // sum == 7
   */
  template <typename F, typename... Args>
  auto enqueue(F &&f, Args &&...args)
      -> std::future<std::invoke_result_t<F, Args...>> {
    using return_type = std::invoke_result_t<F, Args...>;

    // 用 packaged_task + shared_ptr 将任务包装为无参 void() 函数，
    // 这样所有任务在队列中是同质的 std::function<void()>
    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...));

    std::future<return_type> result = task->get_future();

    {
      std::lock_guard<std::mutex> lock(queue_mutex_);

      if (stop_) {
        throw std::runtime_error("[ThreadPool] 线程池已停止，无法提交新任务");
      }

      // 将打包好的任务塞进队列
      tasks_.emplace([task]() { (*task)(); });
    }

    cv_.notify_one(); // 唤醒一个等待中的 worker
    return result;
  }

private:
  /// 每个 worker 线程的执行体：循环取任务 → 执行
  void worker_loop(size_t /*worker_id*/) {
    while (true) {
      std::function<void()> task;

      // --- 临界区：从队列取任务 ---
      {
        std::unique_lock<std::mutex> lock(queue_mutex_);

        // 条件变量等待：队列非空 或 线程池停止
        cv_.wait(lock, [this] { return stop_ || !tasks_.empty(); });

        // 线程池已停止 且 队列已空 → 退出
        if (stop_ && tasks_.empty()) {
          return;
        }

        task = std::move(tasks_.front());
        tasks_.pop();
      }

      // --- 临界区外执行任务（不持锁，允许其他线程并发取任务）---
      task();
    }
  }

  std::vector<std::thread> workers_;        ///< worker 线程池
  std::queue<std::function<void()>> tasks_; ///< 任务队列
  std::mutex queue_mutex_;                  ///< 保护任务队列
  std::condition_variable cv_;              ///< 用于阻塞/唤醒 worker
  std::atomic<bool> stop_{false};           ///< 停止标志
};
