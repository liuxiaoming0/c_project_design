/*
 * @Descripttion:简单工厂模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-13 14:26:34
 * @LastEditors: danae
 * @LastEditTime: 2022-07-13 15:57:24
 */
#pragma once
#include "../comm/define.h"

namespace SIMPLE_FACTORY {
using PROTO_KV = std::unordered_map<std::string, std::string>;
#define PRINTF(info) printf("%s::%s(%d):%s\n", __FILE__, __FUNCTION__, __LINE__, info)

enum S_P_Type {
  json = 1,
  http = 2,
};

class AbtractProduct {
 public:
  virtual ~AbtractProduct() = default;
  virtual void ParseText(const std::string& in, PROTO_KV& out) = 0;
};

class JsonProduct : public AbtractProduct {
 public:
  void ParseText(const std::string& in, PROTO_KV& out) override { PRINTF(""); };
};

class HttpProduct : public AbtractProduct {
 public:
  void ParseText(const std::string& in, PROTO_KV& out) override { PRINTF(""); };
};

class SimpleFactory {
 public:
  virtual ~SimpleFactory() = default;

  AbtractProduct* createNew(const S_P_Type& t) {
    switch (t) {
      case S_P_Type::json:
        return new JsonProduct();
        // return dynamic_cast<AbtractProduct*>(std::shared_ptr<JsonProduct>()); // error, smart ptr
        // can`t transport
      case S_P_Type::http:
        return new HttpProduct();
      default:
        return nullptr;
        break;
    }
  }
};
}  // namespace SIMPLE_FACTORY
