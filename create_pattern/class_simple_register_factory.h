#pragma once
#include "../comm/define.h"

namespace SIMPLE_REGISTER_FACTORY {
class AbtractProduct;
using PROTO_KV = std::unordered_map<std::string, std::string>;
using AbtractProductPtr = std::shared_ptr<AbtractProduct>;

#define PRINTF(info) printf("%s::%s(%d):%s\n", __FILE__, __FUNCTION__, __LINE__, info)

#define NEW_IMPL_REGISTER_CLASS(implRegisterClassName, BaseClassName, implClassName, \
                                __VA_ARGS__...)                                      \
  class implRegisterClassName                                                        \
      : public RegisterAbtract<BaseClassName, implClassName, ##__VA_ARGS__> {}

// 注册模板类，用于生成智能指针
// TODO：抽象类，不知为何？
template <typename BaseClass, typename implClassName, typename... Args>
class RegisterAbtract {
 public:
  RegisterAbtract() = default;
  static void Create(std::shared_ptr<BaseClass>* res, Args... args) {
    BaseClass* bp = new implClassName(std::forward<Args>(args)...);
    res->reset(bp);
  }
};

// 抽象产品类
class AbtractProduct {
 public:
  virtual ~AbtractProduct() = default;
  virtual void ParseText(const std::string& in, PROTO_KV& out) = 0;
  virtual std::string Name() = 0;
};

// 实现产品类
class JsonProduct : public AbtractProduct {
 public:
  void ParseText(const std::string& in, PROTO_KV& out) override { PRINTF(""); };
  std::string Name() override { return "JsonProduct"; };
};

NEW_IMPL_REGISTER_CLASS(JsonProductRegister, AbtractProduct, JsonProduct);

// 实现产品类
class HttpProduct : public AbtractProduct {
 public:
  void ParseText(const std::string& in, PROTO_KV& out) override { PRINTF(""); };
  std::string Name() override { return "HttpProduct"; };
};

NEW_IMPL_REGISTER_CLASS(HttpProductRegister, AbtractProduct, HttpProduct);

// 工厂类
class SimpleFactory {
 public:
  virtual ~SimpleFactory() = default;
  SimpleFactory(const SimpleFactory&) = delete;
  SimpleFactory& operator=(const SimpleFactory&) = delete;

  static SimpleFactory& GetInstance() {
    static SimpleFactory instance;
    return instance;
  }

  void Register(AbtractProductPtr ptr) {
    printf("test Register:%s\n", ptr->Name().c_str());
    map_[ptr->Name()] = ptr;
  }

  AbtractProductPtr getName(const std::string name) {
    AbtractProductPtr ptr = nullptr;
    auto it = map_.find(name);
    if (it != map_.end()) ptr = it->second;
    return ptr;
  }

 private:
  SimpleFactory() = default;

 private:
  std::unordered_map<std::string, AbtractProductPtr> map_;
};
}  // namespace SIMPLE_REGISTER_FACTORY