/*
 * @Descripttion: command-pattern
 * @version:
 * @Author: danae
 * @Date: 2022-07-20 10:57:41
 * @LastEditors: danae
 * @LastEditTime: 2022-07-20 16:21:58
 */
#pragma once

#include "../comm/define.h"

/// TODO:支持单命令回滚，多命令回滚

/// 命令接收者-真正的处理者
class AbtractReceiver {
 public:
  virtual ~AbtractReceiver() = default;
  virtual void open() = 0;
  virtual void func1(std::string& a) = 0;
  virtual void func2(std::string& b) = 0;
  virtual void undo() = 0;
};

class ImplReceiver : public AbtractReceiver {
 public:
  ImplReceiver() = default;
  virtual void open() { PRINTF(""); }
  virtual void func1(std::string& a) override { PRINTF(a.c_str()); }
  virtual void func2(std::string& b) override { PRINTF(b.c_str()); }
  virtual void undo() { PRINTF(""); }
};

/// 抽象命令
class AbtractCommand {
 public:
  AbtractCommand(AbtractReceiver* r) { recv_ = r; }
  virtual ~AbtractCommand() = default;
  virtual const std::string Name() = 0;
  virtual void Execute() = 0;

 protected:
  AbtractReceiver* recv_;
};

/// 命令使用者，与具体接收者解耦
class ImplInvoker {
 public:
  ImplInvoker() = default;
  void AddCommand(AbtractCommand* cmd) { cmds_[cmd->Name()] = cmd; }

  void OpenCmdAny() { cmds_["open"]->Execute(); }
  void ChangeCmdAny() { cmds_["change"]->Execute(); }

 private:
  std::unordered_map<std::string, AbtractCommand*> cmds_;
};

/// 独立的命令，与具体接收者解耦，可以重复利用
class OpenCommand : public AbtractCommand {
 public:
  explicit OpenCommand(AbtractReceiver* r) : AbtractCommand(r){};
  const std::string Name() { return "open"; }
  void Execute() override {
    PRINTF("");
    recv_->open();
  }

 private:
};

class ChangeCommand : public AbtractCommand {
 public:
  explicit ChangeCommand(AbtractReceiver* r, std::string a, std::string b)
      : AbtractCommand(r), a_(a), b_(b){};
  const std::string Name() { return "change"; }
  void Execute() override {
    PRINTF("");
    recv_->func1(a_);
    recv_->func1(b_);
  }

 private:
  std::string a_;
  std::string b_;
};
