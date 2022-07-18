/*
 * @Descripttion: 装饰模式（封装）
 * @version:
 * @Author: danae
 * @Date: 2022-07-17 19:54:45
 * @LastEditors: danae
 * @LastEditTime: 2022-07-18 09:05:29
 */
#pragma once

#include "../comm/define.h"

// 原始功能（抽象层）
class AbtractOringin {
 public:
  virtual ~AbtractOringin() = default;
  virtual std::string Process() = 0;
};

// 具体原始功能（实现层）
class Impl1Origin : public AbtractOringin {
 public:
  std::string Process() override { return "Impl1Origin"; };
};

// public 继承原有的接口
// 成员变量 对指定的具体实现ImplNOrigin的包装
class AbtractWrapper : public AbtractOringin {
 public:
  AbtractWrapper(AbtractOringin* o) : origin_(o) {}
  virtual ~AbtractWrapper() {}
  std::string Process() override {
    return this->origin_->Process();
  }  // 封装不改变源逻辑，只前后增加逻辑
 protected:
  AbtractOringin* origin_;
};

class Impl1Wrapper : public AbtractWrapper {
 public:
  Impl1Wrapper(AbtractOringin* o) : AbtractWrapper(o) {}
  std::string Process() override { return "Impl1Wrapper(" + AbtractWrapper::Process() + ")"; }
};

class Impl2Wrapper : public AbtractWrapper {
 public:
  Impl2Wrapper(AbtractOringin* o) : AbtractWrapper(o) {}
  std::string Process() override { return "Impl2Wrapper(" + AbtractWrapper::Process() + ")"; }
};