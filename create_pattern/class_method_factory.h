/*
 * @Descripttion:工厂方法模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-13 14:26:34
 * @LastEditors: danae
 * @LastEditTime: 2022-07-13 15:58:24
 */
#pragma once
#include "../comm/define.h"

namespace METHOD_FACTORY {
using PROTO_KV = std::unordered_map<std::string, std::string>;
#define PRINTF(info) printf("%s::%s(%d):%s\n", __FILE__, __FUNCTION__, __LINE__, info)

class AbtractProduct {
 public:
  virtual ~AbtractProduct() = default;
  virtual void ParseText(const std::string& in, PROTO_KV& out) = 0;
};

class JsonProduct : public AbtractProduct {  // Impl product
 public:
  void ParseText(const std::string& in, PROTO_KV& out) override { PRINTF(""); };
};

class HttpProduct : public AbtractProduct {  // Impl product
 public:
  void ParseText(const std::string& in, PROTO_KV& out) override { PRINTF(""); };
};

class AbtractFactory {
 public:
  virtual ~AbtractFactory() = default;
  virtual AbtractProduct* createNew() = 0;
};

class JsonFactory : public AbtractFactory {  // Impl factory
 public:
  AbtractProduct* createNew() override { return dynamic_cast<AbtractProduct*>(new JsonProduct); };
};

class HttpFactory : public AbtractFactory {  // Impl factory
 public:
  AbtractProduct* createNew() override { return dynamic_cast<AbtractProduct*>(new HttpProduct); };
};
}  // namespace METHOD_FACTORY
