#pragma once

#include <cstddef> // size_t
#include <mutex>
#include <string>
#include <thread>
#include <vector>

/**
 * @brief RAII 风格的多线程文件分块拷贝器
 *
 * 构造时启动 N 个线程，每个线程负责读取源文件的一段字节范围，
 * 写入目标文件的对应位置。析构时自动 join 所有线程。
 *
 * 典型用法:
 * @code
 *   {
 *     ThreadWorker worker("./input.dat", "./output.dat", 4);
 *     // worker 离开作用域时自动 join 所有线程
 *   }
 * @endcode
 */
class ThreadWorker {
public:
  /**
   * @param src         源文件路径
   * @param dst         目标文件路径
   * @param num_threads 线程数（默认 4），若大于文件字节数则自动缩减
   * @throws std::runtime_error 源文件打不开或目标文件无法创建
   */
  ThreadWorker(const std::string &src, const std::string &dst,
               size_t num_threads = 4);

  /// 析构时自动 join 所有线程（RAII 核心）
  ~ThreadWorker();

  // 禁止拷贝与移动（std::thread 不可拷贝，统一禁止避免混淆）
  ThreadWorker(const ThreadWorker &) = delete;
  ThreadWorker &operator=(const ThreadWorker &) = delete;

private:
  /// 单线程执行体：读取源文件 [start, end) 字节并写入目标文件对应位置
  void copy_chunk(const std::string &src, const std::string &dst, size_t start,
                  size_t end, size_t thread_id);

  std::vector<std::thread> threads_; ///< 线程池
  std::mutex out_mutex_;             ///< 保护目标文件的并发写入
  size_t file_size_;                 ///< 源文件总字节数（0 表示空文件）
};
