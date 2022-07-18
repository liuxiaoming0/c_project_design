/*
 * @Descripttion: 适配者模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-14 11:55:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-18 14:40:13
 */
#include "../../struct_pattern/class_adapter.h"
#include "../google_test.h"

TEST(testAdapter, create) {
  auto c1 = std::make_shared<NormalClient>();
  c1->RequestA();
  auto c2 = std::make_shared<SpecialClient>();
  c2->RequestSpecailA();
}