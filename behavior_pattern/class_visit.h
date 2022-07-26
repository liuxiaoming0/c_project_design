/*
 * @Descripttion: 访问者
 * @version:
 * @Author: danae
 * @Date: 2022-07-26 12:09:23
 * @LastEditors: danae
 * @LastEditTime: 2022-07-26 12:11:32
 */
#pragma once

#include "../comm/define.h"

// 抽象访问者类
class SystemA;
class SystemB;
class AbtractVisitor {
 public:
  virtual ~AbtractVisitor() = default;
  virtual void Visit(SystemA* s) = 0;
  virtual void Visit(SystemB* s) = 0;
};

// 已有系统A
class SystemA {
 public:
  SystemA(const std::string& c, const int& v) : context_(c), value_(v) {}
  void Accept(AbtractVisitor* a) { a->Visit(this); }
  std::string GetContext() { return context_; }
  int GetValue() { return value_; }

 private:
  std::string context_;
  int value_;
};

// 已有系统B
class SystemB {
 public:
  SystemB(const std::string& c, const int& v) : context_(c), value_(v) {}
  void Accept(AbtractVisitor* a) { a->Visit(this); }
  std::string GetContext() { return context_; }
  int GetValue() { return value_; }

 private:
  std::string context_;
  int value_;
};

// 具体访问者实现-收集所有系统的日志
class GetLogVisitor : public AbtractVisitor {
 public:
  void Visit(SystemA* s) { PRINTF(s->GetContext().c_str()); };
  void Visit(SystemB* s) { PRINTF(s->GetContext().c_str()); };
};

// 具体访问者实现-收集所有系统的指标
class GetMetricVisitor : public AbtractVisitor {
 public:
  void Visit(SystemA* s) { printf("%d\n", s->GetValue()); }
  void Visit(SystemB* s) { printf("%d\n", s->GetValue()); }
};
