/*
 * @Descripttion: 策略
 * @version:
 * @Author: danae
 * @Date: 2022-07-25 16:56:45
 * @LastEditors: danae
 * @LastEditTime: 2022-07-26 10:51:16
 */
#pragma once
#include "../comm/define.h"

class AbtractStrategy {
 public:
  virtual ~AbtractStrategy() = default;
  virtual void Navigation() = 0;
};

class CityMap {
 public:
  CityMap(AbtractStrategy* s = nullptr) : strate_(s){};
  ~CityMap() { delete strate_; }
  void SetStrategy(AbtractStrategy* s) {
    delete strate_;
    strate_ = s;
  }
  void Navigation() { strate_->Navigation(); }

 private:
  AbtractStrategy* strate_;
};

class WalkStrategy : public AbtractStrategy {
 public:
  void Navigation() override { PRINTF(""); }
};

class BusStrategy : public AbtractStrategy {
 public:
  void Navigation() override { PRINTF(""); }
};

class TaxtStrategy : public AbtractStrategy {
 public:
  void Navigation() override { PRINTF(""); }
};
