/*
 * @Descripttion: 桥接模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-15 22:04:00
 * @LastEditors: danae
 * @LastEditTime: 2022-07-18 09:04:42
 */
#pragma once

#include "../comm/define.h"

class AbtractFeature1 {
 public:
  virtual ~AbtractFeature1() = default;
  virtual void SetFeature1() = 0;
};

class ImplFeature1 : public AbtractFeature1 {
 public:
  ImplFeature1() = default;
  void SetFeature1() { PRINTF(""); };
};

class AbtractAbility {
 public:
  AbtractAbility(AbtractFeature1* f) : feature_(f){};
  void SetAbilityA() { PRINTF(""); };
  virtual ~AbtractAbility() = default;

  virtual void SetFeature() = 0;

 protected:
  AbtractFeature1* feature_;
};

class ImplAbility : public AbtractAbility {
 public:
  ImplAbility(AbtractFeature1* f) : AbtractAbility(f){};
  void SetFeature() override {
    PRINTF("");
    feature_->SetFeature1();
  };
};