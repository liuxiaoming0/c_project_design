/*
 * @Descripttion: 享元
 * @version:
 * @Author: danae
 * @Date: 2022-07-18 09:26:06
 * @LastEditors: danae
 * @LastEditTime: 2022-07-18 14:43:57
 */
#pragma once
#include <algorithm>
#include <list>
#include "../comm/define.h"

// 共享变量
struct Attr {
  int type;
  int height;
  std::string color;
  std::string texture;

 public:
  bool operator==(const Attr& rhs) const {
    return (type == rhs.type && height == rhs.height && color == rhs.color &&
            texture == rhs.texture);
  }
};

// x、y是独有变量
class Forest;
class Tree {
 public:
  friend class Forest;
  Tree() = default;
  Tree(const Attr& attr, const int& x, const int& y) : attr_(attr), x_(x), y_(y) {}

 private:
  Attr attr_;
  int x_;
  int y_;
};

// 获取共享变量的工厂
class TreeFactory {
 public:
  static std::list<Attr> attrs_;  // static不是必须
  TreeFactory() { attrs_.resize(100); }
  void GetTree(const Attr& attr, const int& x, const int& y, Tree** tree) {
    *tree = new Tree(getAttr(attr), x, y);
  }

 private:
  const Attr& getAttr(const Attr& attr) {
    auto it = find(attrs_.begin(), attrs_.end(), attr);
    if (it != attrs_.end()) {
      return *it;
    } else {
      return attrs_.emplace_back(attr);
    }
  }
};
std::list<Attr> TreeFactory::attrs_;

class Forest {
 public:
  ~Forest() {
    for (auto& i : trees_) {
      RELEASE_PTR(i);
    }
  }
  void AddTree(const Attr& attr, const int& x, const int& y) {
    Tree* t = new Tree();
    Tree** tree = &t;
    TreeFactory f;
    f.GetTree(attr, x, y, tree);
    trees_.emplace_back(*tree);
  }

  void Show() {
    for (const auto& i : trees_) {
      printf("type=%d, height=%d, color=%s, texture=%s, x=%d, y=%d\n", i->attr_.type,
             i->attr_.height, i->attr_.color.c_str(), i->attr_.texture.c_str(), i->x_, i->y_);
    }
  }

 private:
  std::list<Tree*> trees_;
};
