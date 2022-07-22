/*
 * @Descripttion: 中介者
 * @version:
 * @Author: danae
 * @Date: 2022-07-22 11:34:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-22 11:35:24
 */

#include "../../behavior_pattern/class_mediator.h"
#include "../google_test.h"

TEST(testMediator, create) {
  auto p1 = new ImplMediator();
  auto p2 = new ImplAObject(p1);
  auto p3 = new ImplBObject(p1);
  p1->AddObject(p2);
  p1->AddObject(p3);

  // p2->Notify("Send Msg", p3); // 发送给指定人
  AbtractObject* p4 = nullptr;  // 发送给全部
  p2->Notify("Send Msg", p4);

  RELEASE_PTR(p1);
  RELEASE_PTR(p2);
  RELEASE_PTR(p3);
  RELEASE_PTR(p4);
}