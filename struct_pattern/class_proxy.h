/*
 * @Descripttion: 代理
 * @version:
 * @Author: danae
 * @Date: 2022-07-19 11:59:37
 * @LastEditors: danae
 * @LastEditTime: 2022-07-19 14:42:56
 */
#pragma once

#include "../comm/define.h"

// 代理类和实际处理类的抽象类
class AbtractServer {
 public:
  virtual ~AbtractServer() = default;

  virtual void func1() = 0;
};

// 实际处理类
class ImplServer : public AbtractServer {
 public:
  void func1() override { PRINTF(""); }
};

// 代理类, 负责实际处理对象的声明周期
class ImplProxyServer : public AbtractServer {
 public:
  ImplProxyServer() {
    if (server_ == nullptr) server_ = new ImplServer();
  }
  ~ImplProxyServer() { RELEASE_PTR(server_); }
  void func1() override {
    PRINTF("");
    // check access power
    server_->func1();
    // record log message
  }

 private:
  ImplServer* server_;
};
