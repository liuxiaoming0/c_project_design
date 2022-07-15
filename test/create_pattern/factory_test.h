/*
 * @Descripttion: 工厂模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-13 14:26:34
 * @LastEditors: danae
 * @LastEditTime: 2022-07-15 11:04:30
 */
#include "../create_pattern/class_abtract_factory.h"
#include "../create_pattern/class_abtract_register_factory.h"
#include "../create_pattern/class_method_factory.h"
#include "../create_pattern/class_simple_factory.h"
#include "../create_pattern/class_simple_register_factory.h"
#include "../google_test.h"

TEST(testFactory, create) {
  // 简单工厂类，根据入参生成不同对象
  using namespace SIMPLE_FACTORY;
  SimpleFactory f;
  AbtractProduct* p = f.createNew(S_P_Type::json);
  PROTO_KV kv;
  p->ParseText("", kv);
  delete p;

  // 使用智能指针，用注册类生成指针，再注册到工厂的map结构体
  using namespace SIMPLE_REGISTER_FACTORY;
  AbtractProductPtr sp = nullptr;
  JsonProductRegister::Create(&sp);

  SimpleFactory::GetInstance().Register(sp);
  PROTO_KV kv;
  // SimpleFactory::GetInstance().getName("JsonProduct")->ParseText("", kv);

  // 工厂方法模型
  using namespace METHOD_FACTORY;
  JsonFactory f;
  AbtractProduct* p = f.createNew();
  PROTO_KV kv;
  p->ParseText("", kv);
  delete p;

  // 抽象工厂模型
  using namespace ABTRACT_FACTORY;
  JsonFactory f;
  AbtractProduct* p = f.createNew1();
  PROTO_KV kv;
  p->ParseText("", kv);
  delete p;

  using namespace ABTRACT_FACTORY;
  Factory1 f;
  auto p = f.createNewJson();
  PROTO_KV kv;
  p->ParseText("", kv);
  delete p;

  // 抽象工厂模板模型
  using namespace ABTRACT_REGISTER_FACTORY;
  TImplFactory<HttpProduct, Http2Product> f;
  std::shared_ptr<HttpProduct> p;
  f.create(&p);
  PROTO_KV kv;
  p->ParseText("", kv);
}