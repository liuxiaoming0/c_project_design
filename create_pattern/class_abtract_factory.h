/*
 * @Descripttion:抽象工厂模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-13 14:26:34
 * @LastEditors: danae
 * @LastEditTime: 2022-07-26 10:50:21
 */
#pragma once
#include "../comm/define.h"

namespace ABTRACT_FACTORY {
using PROTO_KV = std::unordered_map<std::string, std::string>;
#define PRINTF(info) printf("%s::%s(%d):%s\n", __FILE__, __FUNCTION__, __LINE__, info)

class JsonProduct /*: public AbtractProduct */ {
 public:
  virtual void ParseText(const std::string& in, PROTO_KV& out) = 0;
};

class Json1Product : public JsonProduct {
 public:
  void ParseText(const std::string& in, PROTO_KV& out) override { PRINTF(""); };
};

class Json2Product : public JsonProduct {
 public:
  void ParseText(const std::string& in, PROTO_KV& out) override { PRINTF(""); };
};

class HttpProduct /*: public AbtractProduct*/ {
 public:
  virtual void ParseText(const std::string& in, PROTO_KV& out) = 0;
};

class Http1Product : public HttpProduct {
 public:
  void ParseText(const std::string& in, PROTO_KV& out) override { PRINTF(""); };
};

class Http2Product : public HttpProduct {
 public:
  void ParseText(const std::string& in, PROTO_KV& out) override { PRINTF(""); };
};

class AbtractFactory {
 public:
  virtual ~AbtractFactory() = default;
  virtual JsonProduct* createNewJson() = 0;
  virtual HttpProduct* createNewHttp() = 0;
};

class Factory1 : public AbtractFactory {
 public:
  JsonProduct* createNewJson() override { return dynamic_cast<JsonProduct*>(new Json1Product); };
  HttpProduct* createNewHttp() override { return dynamic_cast<HttpProduct*>(new Http1Product); };
};

class Factory2 : public AbtractFactory {
 public:
  JsonProduct* createNewJson() override { return dynamic_cast<JsonProduct*>(new Json2Product); };
  HttpProduct* createNewHttp() override { return dynamic_cast<HttpProduct*>(new Http2Product); };
};
}  // namespace ABTRACT_FACTORY