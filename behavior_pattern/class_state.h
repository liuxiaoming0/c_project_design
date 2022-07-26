/*
 * @Descripttion: 状态
 * @version:
 * @Author: danae
 * @Date: 2022-07-25 16:56:45
 * @LastEditors: danae
 * @LastEditTime: 2022-07-26 10:51:13
 */
#pragma once
#include "../comm/define.h"

// 抽象状态类
class Phone;
class AbtractState {
 public:
  AbtractState(Phone* p) : phone_(p) {}
  virtual void ClickLock() { PRINTF(""); }
  virtual void ClickUnLock() { PRINTF(""); }
  virtual void ClickPlay() { PRINTF(""); }

 protected:
  Phone* phone_;
};

// 具体状态类，也负责Phone状态更新
class InitState : public AbtractState {
 public:
  InitState(Phone* p) : AbtractState(p) {}
  void ClickUnLock() override { PRINTF("<InitState>"); }
  void ClickLock() override;
  void ClickPlay() override;
};

// 具体状态类，也负责Phone状态更新
class LockState : public AbtractState {
 public:
  LockState(Phone* p) : AbtractState(p) {}
  void ClickLock() override { PRINTF("<LockState>"); }
  void ClickUnLock() override { PRINTF("<LockState>"); }
  void ClickPlay() override { PRINTF("<LockState>"); }
};

// 具体状态类，也负责Phone状态更新
class PlayState : public AbtractState {
 public:
  PlayState(Phone* p) : AbtractState(p) {}
  void ClickLock() override { PRINTF("<PlayState>"); }
  void ClickUnLock() override { PRINTF("<PlayState>"); }
  void ClickPlay() override { PRINTF("<PlayState>"); }
};

// 调用当前状态的具体状态逻辑
class Phone {
 public:
  Phone() { state_ = new InitState(this); }
  void LockClick() { state_->ClickLock(); }
  void UnLockClick() { state_->ClickUnLock(); }
  void PlayClick() { state_->ClickPlay(); }

  void ChangeState(AbtractState* s) { state_ = s; }

 private:
  AbtractState* state_;
};

// 具体状态的实现
void InitState::ClickLock() {
  PRINTF("<InitState>");
  phone_->ChangeState(new LockState(phone_));
}

void InitState::ClickPlay() {
  PRINTF("<InitState>");
  phone_->ChangeState(new PlayState(phone_));
}