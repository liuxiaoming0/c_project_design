/*
 * @Descripttion: 原型设计模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-11 16:33:21
 * @LastEditors: danae
 * @LastEditTime: 2022-07-14 09:40:52
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

// 方法2：封装类，原型作为入参
class CloneFactoryFromProto {
 public:
  CloneFactoryFromProto(AbtractProtoType* proto) : proto_(proto){};
  AbtractProtoType* create() { return proto_->Clone(); }

 private:
  AbtractProtoType* proto_;
};

// 方法3：封装类，函数指针作为参数
AbtractProtoType* Impl1callback() { return new ImplPrototype1("Impl1callback"); }
typedef AbtractProtoType* (*func)();
class CloneFactoryFromFuncPtr {
 public:
  static AbtractProtoType* create(func f) { return f()->Clone(); }
};

// 方法4：封装类，静态成员作为原型，节省动态分配内存时间
class CloneFactoryFromStatic {
 public:
  static AbtractProtoType* createType1() { return type1_->Clone(); }

 public:
  static ImplPrototype1* type1_;
  // static ImplPrototype1 type1_("ImplPrototype1"); // err
  // static ImplPrototype1 type2_("ImplPrototype2"); // 扩展
};
ImplPrototype1* CloneFactoryFromStatic::type1_ = new ImplPrototype1("ImplPrototype1");

// 方法5：模板创建，静态成员作为原型
template <typename T>
class CloneFactoryFromT {
 public:
  static AbtractProtoType* create() { return type1_->Clone(); }
  static T* type1_;
};

template <class T>
T* CloneFactoryFromT<T>::type1_ = new ImplPrototype1("CloneFactoryFromT");

// 方法6：模板创建，私有成员作为原型，不同模板都为单独的单例
template <typename T>
class CloneFactoryTStatic {
 public:
  ~CloneFactoryTStatic() {
    for (auto t : protos_) {
      RELEASE_PTR(t.second);
    }
  };
  CloneFactoryTStatic(const CloneFactoryTStatic&) = delete;
  CloneFactoryTStatic& operator=(const CloneFactoryTStatic&) = delete;
  static CloneFactoryTStatic& GetInstance() {
    static CloneFactoryTStatic instance_;
    return instance_;
  }
  void AddProto(const std::string name, AbtractProtoType* proto) {
    auto i = protos_.find(name);
    if (i == protos_.end()) protos_.insert(std::make_pair(name, proto));
  };
  AbtractProtoType* create(const std::string name) { return protos_.at(name)->Clone(); }

 private:
  CloneFactoryTStatic() = default;
  std::unordered_map<std::string, AbtractProtoType*> protos_;
};
