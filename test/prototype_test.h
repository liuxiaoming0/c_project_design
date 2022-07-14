#include "../create_pattern/class_prototype.h"
#include "google_test.h"

TEST(testProtoType, create) {
  // 方法1：动态调用创建模板
  AbtractProtoType* t1 = new ImplPrototype1("abc");
  auto p1 = t1->Clone();
  printf("p1->GetText()=%s\n", p1->GetText());

  // 方法2：封装类，原型作为入参
  AbtractProtoType* t2 = new ImplPrototype1("def");
  CloneFactoryFromProto f2(t2);
  auto p2 = f2.create();
  printf("p2->GetText()=%s\n", p2->GetText());

  // 方法3：封装类，函数指针作为参数
  auto p3 = CloneFactoryFromFuncPtr::create(Impl1callback);
  printf("p3->GetText()=%s\n", p3->GetText());

  // 方法4：封装类，静态成员作为原型，节省动态分配内存时间
  auto p4 = CloneFactoryFromStatic::createType1();
  printf("p4->GetText()=%s\n", p4->GetText());

  // 方法5：模板创建，静态成员作为原型
  auto p5 = CloneFactoryFromT<ImplPrototype1>::create();
  printf("p5->GetText()=%s\n", p5->GetText());

  // 方法6：模板创建，私有成员作为原型，不同模板都为单独的单例
  AbtractProtoType* t6_1 = new ImplPrototype1("20220713");
  AbtractProtoType* t6_2 = new ImplPrototype1("20220714");
  CloneFactoryTStatic<ImplPrototype1>::GetInstance().AddProto("one", t6_1);
  CloneFactoryTStatic<ImplPrototype1>::GetInstance().AddProto("two", t6_2);
  auto p6_1 = CloneFactoryTStatic<ImplPrototype1>::GetInstance().create("one");
  printf("p6_1->GetText()=%s\n", p6_1->GetText());
}
