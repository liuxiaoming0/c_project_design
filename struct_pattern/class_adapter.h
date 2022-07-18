/*
 * @Descripttion: 适配器
 * @version:
 * @Author: danae
 * @Date: 2022-07-15 09:06:58
 * @LastEditors: danae
 * @LastEditTime: 2022-07-18 09:07:25
 */
#pragma once
#include "../comm/define.h"

// existed server interface
class ExistServer {
 public:
  virtual void processA() { PRINTF(""); };
  virtual void processB() { PRINTF(""); };
  // virtual void processC() { AdapeeC->processC();}
  // 这种写法改动了原有的接口，属于功能扩展，而不是适配特殊的现有接口
};

// expand ability of server, process special request
class Adapee {
 public:
  void processSpecailA() { PRINTF(""); };
};

// method one : inherit ExistServer
class AdapterServer : public ExistServer {
 public:
  AdapterServer() { adapee_ = new Adapee(); }
  void processA() override { adapee_->processSpecailA(); }

 private:
  Adapee* adapee_;
};

// method two : multipe inherit
class AdapterServerMutipe : public ExistServer, public Adapee {
 public:
  void processA() { processSpecailA(); }
};

// client request, support
class NormalClient {
 public:
  NormalClient() { server_ = new ExistServer(); };
  void RequestA() { server_->processA(); };

 private:
  ExistServer* server_;
};

// client request, not support
class SpecialClient {
 public:
  SpecialClient() { server_ = new AdapterServer(); };
  void RequestSpecailA() { server_->processA(); }

 private:
  ExistServer* server_;
};