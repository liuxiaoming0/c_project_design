/*
 * @Descripttion: 中介者
 * @version:
 * @Author: danae
 * @Date: 2022-07-22 09:28:55
 * @LastEditors: danae
 * @LastEditTime: 2022-07-24 11:34:39
 */
#pragma once

#include "../comm/define.h"

// 抽象中介者
class AbtractObject;
class AbtractMediator {
 public:
  virtual ~AbtractMediator() = default;
  virtual void AddObject(AbtractObject* a) { objects_.push_back(a); }
  virtual void SendMsg(AbtractObject* from, const std::string& msg, AbtractObject* to) = 0;

 protected:
  std::vector<AbtractObject*> objects_;
};

// 抽象对象
class AbtractObject {
 public:
  AbtractObject(AbtractMediator* m) : media_(m) {}
  virtual ~AbtractObject() = default;
  virtual const std::string Getname() = 0;
  virtual void Notify(const std::string& msg, AbtractObject* a) { media_->SendMsg(this, msg, a); }
  virtual void Listen(const std::string& msg) { PRINTF(msg.c_str()); }

 protected:
  AbtractMediator* media_;
};

// 具体中介者
class ImplMediator : public AbtractMediator {
 public:
  void SendMsg(AbtractObject* from, const std::string& msg, AbtractObject* to) override {
    if (to == nullptr) {
      for (auto& o : objects_) {
        o->Listen(msg);
      }
    } else {
      to->Listen(msg);
    }
  }
};

// 具体对象A
class ImplAObject : public AbtractObject {
 public:
  ImplAObject(AbtractMediator* m) : AbtractObject(m) {}
  const std::string Getname() override { return "ImplA"; };
};

// 具体对象B
class ImplBObject : public AbtractObject {
 public:
  ImplBObject(AbtractMediator* m) : AbtractObject(m) {}
  const std::string Getname() override { return "ImplB"; };
};
