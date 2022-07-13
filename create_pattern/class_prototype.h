/*
 * @Descripttion: 原型设计模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-11 16:33:21
 * @LastEditors: danae
 * @LastEditTime: 2022-07-11 19:03:10
 */
#pragma once
#include "../comm/define.h"

// using AbtractProtoTypePtr = std::shared_ptr<AbtractProtoType>;

class AbtractProtoType {
 public:
  AbtractProtoType() = default;
  virtual ~AbtractProtoType() { text_ = nullptr; };
  virtual AbtractProtoType* Clone() = 0;
  virtual char* GetText() { return text_; };

 protected:
  char* text_;
};

class ImplPrototype1 : public AbtractProtoType {
 public:
  ImplPrototype1(const char* str) {
    if (str == nullptr) {
      text_ = new char[1];
      text_[0] = '\0';
    } else {
      text_ = new char[strlen(str) + 1];
      strcpy(text_, str);
    }
  };
  ImplPrototype1(const ImplPrototype1& rhs) {
    PRINTF("");
    text_ = new char[strlen(rhs.text_) + 1];
    strcpy(text_, rhs.text_);
  };
  AbtractProtoType* Clone() override {
    return new ImplPrototype1(*this);  // copy contuct
  };
};