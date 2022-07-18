/*
 * @Descripttion: 桥接模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-17 16:34:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-18 14:41:01
 */
#include "../../struct_pattern/bridge_test.h"
#include "../google_test.h"

TEST(testBridge, create) {
  AbtractFeature1* p1 = new ImplFeature1();
  ImplAbility* p2 = new ImplAbility(p1);
  p2->SetFeature();
  delete p1;
  delete p2;
}