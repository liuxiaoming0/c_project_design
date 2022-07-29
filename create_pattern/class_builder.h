#include "../comm/define.h"

// 最终的产品类
class Product {
 public:
  void SetA(const std::string s) { a_ = s; };
  void SetB(const std::string s) { b_ = s; };
  void Print() { printf("product A=%s, B=%s\n", a_.c_str(), b_.c_str()); };

 private:
  std::string a_;
  std::string b_;
};


// 抽象构造产品组成部分类
class AbtractBuilder {
 public:
  ~AbtractBuilder(){};
  virtual void BuildPartA() = 0;
  virtual void BuildPartB() = 0;
  virtual void Reset() = 0;
  virtual Product* Getproduct() = 0;
};

// 具体实现产品组成部分，可以有多个
class ImplBuilder1 : public AbtractBuilder {
 public:
  ImplBuilder1() = default;
  void Reset() override {
    PRINTF("");
    this->product_ = new Product();
  }
  // ~ImplBuilder1() { RELEASE_PTR(product_); }
  void BuildPartA() override {
    PRINTF("");
    product_->SetA("ImplBuilder1 A");
  };
  void BuildPartB() override {
    PRINTF("");
    product_->SetB("ImplBuilder1 B");
  };

  Product* Getproduct() override { return product_; }

 private:
  Product* product_;
};

// 支持按照不同顺序，选择部分组装生成产品
class Combine {
 public:
  Combine() = default;
  void SetBuilder(AbtractBuilder* b) { this->builder_ = b; }
  Product* createFull() {
    PRINTF("");
    builder_->Reset();
    builder_->BuildPartB();
    builder_->BuildPartA();
    return builder_->Getproduct();
  }

  Product* createPart() {
    builder_->Reset();
    builder_->BuildPartB();
    return builder_->Getproduct();
  }

 private:
  AbtractBuilder* builder_;
};