/*
 * @Descripttion: 责任链
 * @version:
 * @Author: danae
 * @Date: 2022-07-19 12:36:43
 * @LastEditors: danae
 * @LastEditTime: 2022-07-19 15:00:36
 */
#pragma once

#include "../comm/define.h"

// 抽象链
class AbtractChain {
 public:
  AbtractChain() : nextChain_(nullptr){};
  virtual ~AbtractChain() = default;
  virtual AbtractChain* SetNextChain(AbtractChain* nextChain) final {
    nextChain_ = nextChain;
    return nextChain_;
  }
  virtual void BuProcess(int type) = 0;

 protected:
  AbtractChain* nextChain_;
};

// 抽象入口，可以没有
class AbtractEntrance {
 public:
  AbtractEntrance(AbtractChain* chain) : chain_(chain) {}
  virtual ~AbtractEntrance() = default;
  virtual void ButtonProcess(int type) = 0;

 protected:
  AbtractChain* chain_;
};

// 实际入口，可以没有
class ImplEntrance : public AbtractEntrance {
 public:
  ImplEntrance(AbtractChain* chain) : AbtractEntrance(chain) {}
  void ButtonProcess(int type) { chain_->BuProcess(type); };
};

// 实现链-顺序不定
class Impl1Chain : public AbtractChain {
 public:
  void BuProcess(int type) override {
    PRINTF("");
    if (type == 1)
      printf("Impl1Chain processed, STOP\n");
    else if (nextChain_ != nullptr)
      nextChain_->BuProcess(type);
    else
      printf("Impl1Chain no nextchain, STOP\n");
  }
};

// 实现链-顺序不定
class Impl2Chain : public AbtractChain {
 public:
  void BuProcess(int type) override {
    PRINTF("");
    if (type == 2)
      printf("Impl2Chain processed, STOP\n");
    else if (nextChain_ != nullptr)
      nextChain_->BuProcess(type);
    else
      printf("Impl2Chain no nextchain, STOP\n");
  }
};

// 实现链-顺序不定
class Impl3Chain : public AbtractChain {
 public:
  void BuProcess(int type) override {
    PRINTF("");
    if (type == 3)
      printf("Impl3Chain processed, STOP\n");
    else if (nextChain_ != nullptr)
      nextChain_->BuProcess(type);
    else
      printf("Impl3Chain no nextchain, STOP\n");
  }
};