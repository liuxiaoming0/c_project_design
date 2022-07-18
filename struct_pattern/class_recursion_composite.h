/*
 * @Descripttion:
 * @version: 递归组合模式
 * @Author: danae
 * @Date: 2022-07-17 17:39:42
 * @LastEditors: danae
 * @LastEditTime: 2022-07-18 09:04:59
 */
#pragma once
#include <list>
#include "../comm/define.h"

// 叶子节点、组合节点统一的抽象接口
class AbtractNode {
 public:
  virtual ~AbtractNode() = default;
  virtual std::string DoProcess() = 0;
};

// 单元节点，真正功能
class Node : public AbtractNode {
 public:
  Node(const std::string& s) { str_ = s; }
  std::string DoProcess() override { return "leaf"; }

 private:
  std::string str_;
};

// 组合节点
class CompositeNode : public AbtractNode {
 public:
  CompositeNode() = default;
  ~CompositeNode() {
    for (auto& one : nodes_) {
      RELEASE_PTR(one);
    }
  }
  void Add(AbtractNode* node) { nodes_.push_back(node); }

  void Remove(AbtractNode* node) { nodes_.remove(node); }

  std::string DoProcess() override {
    std::string res;
    for (const auto& i : nodes_) {
      if (i == nodes_.back())
        res += i->DoProcess();
      else
        res = res + i->DoProcess() + "+";
    }
    return "branch(" + res + ")";
  }

 private:
  std::list<AbtractNode*> nodes_;
};