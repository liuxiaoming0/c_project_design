#pragma once
#include "../comm/define.h"

namespace ABTRACT_REGISTER_FACTORY {

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

template <typename BaseProduct, typename Implproduct>
class TImplFactory {
  using BaseProductPtr = std::shared_ptr<BaseProduct>;

 public:
  void create(BaseProductPtr* p) {
    BaseProduct* basePtr = new Implproduct();
    return p->reset(basePtr);
  }
};

}  // namespace ABTRACT_REGISTER_FACTORY