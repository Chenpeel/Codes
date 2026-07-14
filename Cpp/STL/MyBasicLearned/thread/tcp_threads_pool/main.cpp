/**
 * @brief TCP Echo 服务器 — 基于线程池的多客户端并发处理
 *
 * 编译:
 *   g++ -std=c++17 -pthread -O2 main.cpp -o echo_server
 *
 * 运行:
 *   ./echo_server
 *
 * 测试（另开终端）:
 *   nc localhost 8888       # 输入任意文本，回车看回显
 *   echo "hello" | nc -w1 localhost 8888
 *
 * 退出方式:
 *   方式 A: 在服务器终端按 Enter 键
 *   方式 B: 按 Ctrl+C（发送 SIGINT）
 *   方式 C: kill <pid>（发送 SIGTERM）
 */

#include <atomic>
#include <csignal>
#include <cstddef>
#include <iostream>
#include <thread>

#include "tcp_server.hpp"

/// 全局指针，用于信号处理函数访问 TcpServer
static TcpServer *g_server = nullptr;

/// 标记是否由信号触发的退出（而非按 Enter 键）
static std::atomic<bool> g_shutdown_by_signal{false};

/// Ctrl+C / kill 信号处理 → 通知服务器停止
void signal_handler(int /*sig*/) {
  g_shutdown_by_signal = true;
  if (g_server) {
    std::cout << "\n收到中断信号，正在关闭服务器...\n";
    g_server->stop();
  }
}

int main() {
  // 注册信号处理（Ctrl+C / kill 优雅退出）
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);

  // 1. 创建线程池
  size_t threads_num = 10;
  ThreadPool pool(threads_num);

  // 2. 创建 TCP 服务器（监听 8888 端口）
  TcpServer server(8888, pool);
  g_server = &server;

  std::cout << "==========================================\n";
  std::cout << "  TCP Echo 服务器 v1.1\n";
  std::cout << "  端口: 8888\n";
  std::cout << "  线程:" << threads_num << " workers\n";
  std::cout << "  按 Ctrl+C 或 Enter 退出\n";
  std::cout << "==========================================\n\n";

  // 3. 启动一个线程监听键盘输入（按 Enter 退出）
  std::thread input_thread([]() {
    std::cin.get(); // 阻塞等待回车
    std::cout << "\n收到退出指令（Enter）...\n";
    if (g_server) {
      g_server->stop();
    }
  });

  // 4. 启动服务器（阻塞，直到 stop() 被调用）
  server.start();

  // 5. 清理 input_thread
  //    - Enter 退出: input_thread 已自行结束 → join()
  //    - Ctrl+C 退出: input_thread 卡在 cin.get() → detach()
  //      （进程即将退出，OS 会回收线程资源）
  if (input_thread.joinable()) {
    if (g_shutdown_by_signal) {
      input_thread.detach();
    } else {
      input_thread.join();
    }
  }
  g_server = nullptr;

  std::cout << "服务器已完全关闭，再见！\n";
  return 0;
}
