/*
 * @Descripttion:
 * @version:
 * @Author: danae
 * @Date: 2022-07-21 22:53:08
 * @LastEditors: danae
 * @LastEditTime: 2022-07-21 23:17:16
 */
#pragma once

#include "../comm/define.h"

template <typename T, typename U>
class Iterator {
 public:
  using itType = typename std::vector<T>::iterator;
  Iterator(U* c) : c_(c) { it_ = c_->datas_.begin(); }
  bool hasNext() { return it_ == c_->datas_.end(); }
  itType first() { return c_->datas_.begin(); }
  void next() { it_++; }
  itType cur() { return it_; }

 private:
  itType it_;
  U* c_;
};

template <typename T>
class Container {
 public:
  friend class Iterator<T, Container>;
  // typename Container<T>() = default;
  void AddData(const T& t) { datas_.push_back(t); }
  Iterator<T, Container>* CreateIterator() { return new Iterator<T, Container>(this); }

 private:
  std::vector<T> datas_;
};

class CData {
 public:
  CData(const int a) : a_(a){};
  int GetData() { return a_; }

 private:
  int a_;
};