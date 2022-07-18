/*
 * @Descripttion: 外观模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-18 09:10:48
 * @LastEditors: danae
 * @LastEditTime: 2022-07-18 09:27:17
 */
#pragma once

#include "../comm/define.h"

class System1 {
 public:
  void func1() { PRINTF(""); }
};

class System2 {
 public:
  void func2() { PRINTF(""); }
};

class Facade {
 public:
  Facade(System1* sys1, System2* sys2) {
    sys1_ = sys1;
    sys2_ = sys2;
    if (sys1_ == nullptr) sys1_ = new System1();
    if (sys2_ == nullptr) sys2_ = new System2();
  }

  ~Facade() {
    RELEASE_PTR(sys1_);
    RELEASE_PTR(sys2_);
  }

  void Init() {
    sys1_->func1();
    sys2_->func2();
  }

 private:
  System1* sys1_;
  System2* sys2_;
};