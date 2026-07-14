#pragma once

#include <arpa/inet.h> // htons, inet_ntoa
#include <atomic>
#include <cstring> // memset
#include <iostream>
#include <netinet/in.h> // IPPROTO_TCP
#include <string>
#include <sys/socket.h> // socket, bind, listen, accept, sockaddr_in
#include <unistd.h>     // close, read, write

#include "thread_pool.hpp"

/**
 * @brief 基于线程池的 TCP Echo 服务器
 *
 * 主线程负责 accept()，每个客户端连接作为一个任务提交到 ThreadPool，
 * 由空闲的 worker 线程执行 Echo（读一行 → 回一行）循环。
 *
 * 典型用法:
 * @code
 *   ThreadPool pool(threads_num);
 *   TcpServer server(8888, pool);
 *   server.start();  // 阻塞，直到 server.stop() 被调用或 Ctrl+C
 * @endcode
 */
class TcpServer {
public:
  /// @param port 监听端口
  /// @param pool 外部传入的线程池引用（生命周期需长于 TcpServer）
  TcpServer(uint16_t port, ThreadPool &pool)
      : port_(port), pool_(pool), server_fd_(-1), running_(false) {}

  ~TcpServer() { stop(); }

  // 禁止拷贝与移动
  TcpServer(const TcpServer &) = delete;
  TcpServer &operator=(const TcpServer &) = delete;

  /**
   * @brief 启动服务器（阻塞调用）
   *
   * 顺序执行：
   *   1. socket() 创建监听套接字
   *   2. bind()   绑定端口
   *   3. listen() 开始监听
   *   4. 进入 accept 循环，每接到一个客户端就提交给线程池
   */
  void start() {
    // ---------- 1. 创建 socket ----------
    server_fd_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_fd_ < 0) {
      perror("[TcpServer] socket() 失败");
      return;
    }

    // 设置 SO_REUSEADDR: 允许重启后立即复用端口（避免 TIME_WAIT 延迟）
    int opt = 1;
    setsockopt(server_fd_, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // ---------- 2. 绑定端口 ----------
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;         // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // 监听所有网卡
    server_addr.sin_port = htons(port_);      // 主机字节序 → 网络字节序

    if (bind(server_fd_, reinterpret_cast<sockaddr *>(&server_addr),
             sizeof(server_addr)) < 0) {
      std::cerr << "[TcpServer] bind() 失败，端口 " << port_ << " 可能被占用。"
                << std::endl;
      std::cerr << "  提示: 运行 lsof -i :" << port_ << " 查看占用进程"
                << std::endl;
      perror("[TcpServer] bind()");
      close(server_fd_);
      server_fd_ = -1;
      return;
    }

    // ---------- 3. 开始监听 ----------
    // SOMAXCONN: 系统允许的最大未完成连接队列长度
    if (listen(server_fd_, SOMAXCONN) < 0) {
      perror("[TcpServer] listen() 失败");
      close(server_fd_);
      return;
    }

    std::cout << "[TcpServer] 监听端口 " << port_ << "，等待客户端连接...\n";

    // ---------- 4. accept 循环 ----------
    running_ = true;
    while (running_) {
      sockaddr_in client_addr{};
      socklen_t client_len = sizeof(client_addr);

      // accept() 默认阻塞，直到有客户端连接
      int client_fd = accept(
          server_fd_, reinterpret_cast<sockaddr *>(&client_addr), &client_len);

      if (client_fd < 0) {
        // stop() 已调用 → close() 了 server_fd_，accept() 返回 EBADF
        if (!running_) {
          break;
        }
        perror("[TcpServer] accept() 失败");
        continue;
      }

      // 获取客户端 IP（便于日志）
      char client_ip[INET_ADDRSTRLEN];
      inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
      uint16_t client_port = ntohs(client_addr.sin_port);

      std::cout << "[TcpServer] 新连接: " << client_ip << ":" << client_port
                << " (fd=" << client_fd << ")\n";

      // 将客户端处理任务提交给线程池
      try {
        pool_.enqueue(&TcpServer::echo_handler, this, client_fd,
                      std::string(client_ip), client_port);
      } catch (const std::exception &e) {
        std::cerr << "[TcpServer] 提交任务失败: " << e.what() << "\n";
        close(client_fd);
      }
    }

    // 清理监听 socket
    if (server_fd_ >= 0) {
      close(server_fd_);
      server_fd_ = -1;
    }
    std::cout << "[TcpServer] 服务器已停止\n";
  }

  /// 通知 accept 循环退出（线程安全）
  void stop() {
    bool expected = true;
    if (!running_.compare_exchange_strong(expected, false)) {
      return; // 已经停止过了，避免重复 close
    }
    // 直接 close 监听 fd，强制阻塞中的 accept() 返回 EBADF
    // （shutdown 对监听 socket 不可靠，close 是确定性的）
    if (server_fd_ >= 0) {
      close(server_fd_);
      server_fd_ = -1;
    }
  }

private:
  /**
   * @brief Echo 处理逻辑（在 worker 线程中执行）
   *
   * 循环读取客户端发来的数据，原样写回，直到客户端断开或出错。
   *
   * @param client_fd  客户端 socket 文件描述符
   * @param client_ip  客户端 IP（用于日志）
   * @param client_port 客户端端口（用于日志）
   */
  void echo_handler(int client_fd, const std::string &client_ip,
                    uint16_t client_port) {
    constexpr size_t kBufSize = 4096;
    char buffer[kBufSize];

    std::cout << "[Echo #" << client_fd << "] 开始处理 " << client_ip << ":"
              << client_port << "\n";

    while (true) {
      memset(buffer, 0, kBufSize);

      // 阻塞读取客户端数据
      ssize_t n = read(client_fd, buffer, kBufSize);

      if (n < 0) {
        perror("[Echo] read() 失败");
        break;
      }
      if (n == 0) {
        // 读到 0 字节 → 客户端正常关闭连接（FIN）
        std::cout << "[Echo #" << client_fd << "] 客户端关闭连接 " << client_ip
                  << ":" << client_port << "\n";
        break;
      }

      // 原样写回（Echo）
      ssize_t written = write(client_fd, buffer, static_cast<size_t>(n));
      if (written < 0) {
        perror("[Echo] write() 失败");
        break;
      }
    }

    close(client_fd);
    std::cout << "[Echo #" << client_fd << "] 处理结束，fd 已关闭\n";
  }

  uint16_t port_;
  ThreadPool &pool_;
  int server_fd_;
  std::atomic<bool> running_;
};
