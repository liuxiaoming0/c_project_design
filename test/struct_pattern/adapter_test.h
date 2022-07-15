/*
 * @Descripttion: 适配者模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-14 11:55:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-15 11:10:09
 */
#include "../google_test.h"
#include "../struct_pattern/adapter_test.h"

TEST(testAdapter, create) {
  auto c1 = std::make_shared<NormalClient>();
  c1->RequestA();
  auto c2 = std::make_shared<SpecialClient>();
  c2->RequestSpecailA();
}