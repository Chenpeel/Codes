#include "class_thread_RAII.hpp"

#include <algorithm> // std::min
#include <chrono>    // 计时
#include <fstream>
#include <iostream>
#include <stdexcept> // std::runtime_error

// ======================== ThreadWorker 实现 ========================

ThreadWorker::ThreadWorker(const std::string &src, const std::string &dst,
                           size_t num_threads)
    : file_size_(0) {

  // 1. 获取源文件大小
  std::ifstream in(src, std::ios::binary | std::ios::ate);
  if (!in) {
    throw std::runtime_error("无法打开源文件: " + src);
  }
  file_size_ = static_cast<size_t>(in.tellg());
  in.close();

  std::cout << "源文件: " << src << " (" << file_size_ << " bytes)"
            << std::endl;

  if (file_size_ == 0) {
    std::cout << "源文件为空，无需拷贝。" << std::endl;
    return;
  }

  // 2. 预分配目标文件（扩展到与源文件相同大小）
  {
    std::ofstream out(dst, std::ios::binary);
    if (!out) {
      throw std::runtime_error("无法创建目标文件: " + dst);
    }
    // seekp + write 一个字节来扩展文件大小
    out.seekp(file_size_ - 1);
    char zero = '\0';
    out.write(&zero, 1);
    out.close();
  }

  // 3. 计算每个线程负责的字节范围
  //    例: file_size_=329201, num_threads=4
  //    → chunk_size=82300, remainder=1
  //    → 线程0: [0, 82301)  线程1: [82301, 164601) ...
  size_t actual_threads = std::min(num_threads, file_size_);
  size_t chunk_size = file_size_ / actual_threads;
  size_t remainder = file_size_ % actual_threads;

  threads_.reserve(actual_threads);
  for (size_t i = 0; i < actual_threads; ++i) {
    size_t start = i * chunk_size + std::min(i, remainder);
    size_t end = start + chunk_size + (i < remainder ? 1 : 0);

    threads_.emplace_back(&ThreadWorker::copy_chunk, this, src, dst, start, end,
                          i);
  }

  std::cout << "启动 " << actual_threads << " 个线程，"
            << "每块约 " << chunk_size << " bytes\n"
            << std::endl;
}

ThreadWorker::~ThreadWorker() {
  for (auto &t : threads_) {
    if (t.joinable()) {
      t.join();
    }
  }
  std::cout << "\n所有线程已完成，拷贝结束。" << std::endl;
}

void ThreadWorker::copy_chunk(const std::string &src, const std::string &dst,
                              size_t start, size_t end, size_t thread_id) {
  if (start >= end)
    return;

  size_t chunk_size = end - start;
  std::vector<char> buffer(chunk_size);

  // ① 读取源文件的对应分块
  std::ifstream in(src, std::ios::binary);
  if (!in) {
    std::cerr << "[线程 " << thread_id << "] 无法打开源文件！" << std::endl;
    return;
  }
  in.seekg(start);
  in.read(buffer.data(), chunk_size);
  size_t bytes_read = static_cast<size_t>(in.gcount());
  in.close();

  // ② 写入目标文件的对应位置（加锁保护 fstream 操作）
  {
    std::lock_guard<std::mutex> lock(out_mutex_);

    // 必须用 fstream(in|out) 而非 ofstream，否则 ofstream 默认会截断文件
    std::fstream out(dst, std::ios::binary | std::ios::in | std::ios::out);
    if (!out) {
      std::cerr << "[线程 " << thread_id << "] 无法打开目标文件！" << std::endl;
      return;
    }
    out.seekp(start);
    out.write(buffer.data(), bytes_read);
    out.close();
  }

  std::cout << "[线程 " << thread_id << "] 完成: " << start << " ~ " << end
            << " (" << bytes_read << " bytes)" << std::endl;
}

// ======================== main 入口 ========================

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  auto t_start = std::chrono::steady_clock::now();

  try {
    ThreadWorker worker("./binary_file", "./res_file", 4);
    // worker 离开作用域时自动 join 所有线程
  } catch (const std::exception &e) {
    std::cerr << "错误: " << e.what() << std::endl;
    return 1;
  }

  auto t_end = std::chrono::steady_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start);

  std::cout << "总耗时: " << elapsed.count() << " ms" << std::endl;
  return 0;
}
