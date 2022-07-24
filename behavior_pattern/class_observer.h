/*
 * @Descripttion: 观察者
 * @version:
 * @Author: danae
 * @Date: 2022-07-24 11:36:00
 * @LastEditors: danae
 * @LastEditTime: 2022-07-24 11:37:26
 */
#pragma once

#include "../comm/define.h"

// 抽象订阅者
class EventManger;
class AbtractLog {
 public:
  AbtractLog(EventManger* m) : manager_(m){};
  virtual ~AbtractLog() = default;
  virtual std::string Name() = 0;
  virtual void Subscribe(const std::string& msg) = 0;

 protected:
  EventManger* manager_;
};

// 发布者
class EventManger {
 public:
  EventManger() = default;
  ~EventManger() {
    for (auto it : observers_) {
      it.second->Subscribe("eventManger is relase, don`t wait");
    }
  }
  void Subscribe(AbtractLog* observer) { observers_[observer->Name()] = observer; }
  void UnSubscribe(const std::string& name) { observers_.erase(name); }
  void Notify(const std::string msg) {
    for (auto it : observers_) {
      it.second->Subscribe(msg);
    }
  }

 private:
  std::unordered_map<std::string, AbtractLog*> observers_;
};

// 组合发布者
class Editor {
 public:
  Editor(EventManger* m) : manager_(m){};

  void Update() {
    // 更新内容后通知所有订阅者
    manager_->Notify("update editor");
  }

 private:
  EventManger* manager_;
};

// 具体订阅者
class FileLog : public AbtractLog {
 public:
  FileLog(EventManger* m) : AbtractLog(m) { m->Subscribe(this); }
  std::string Name() override { return "FileLog"; }
  ~FileLog() { manager_->UnSubscribe(this->Name()); }
  void Subscribe(const std::string& msg) override {
    // 写文件
    PRINTF(msg.c_str());
  }
};

// 具体订阅者
class SendMailLog : public AbtractLog {
 public:
  SendMailLog(EventManger* m) : AbtractLog(m) {
    m->Subscribe(this);  // 自注册也导致发布者和订阅者不灵活
  }
  std::string Name() override { return "SendMailLog"; }
  ~SendMailLog() { manager_->UnSubscribe(this->Name()); }
  void Subscribe(const std::string& msg) override {
    // 发邮件
    PRINTF(msg.c_str());
  }
};

// 具体订阅者
class SendInfoLog : public AbtractLog {
 public:
  SendInfoLog(EventManger* m) : AbtractLog(m) { m->Subscribe(this); }
  std::string Name() override { return "SendInfoLog"; }
  ~SendInfoLog() { manager_->UnSubscribe(this->Name()); }
  void Subscribe(const std::string& msg) override {
    // 发邮件
    PRINTF(msg.c_str());
  }
};