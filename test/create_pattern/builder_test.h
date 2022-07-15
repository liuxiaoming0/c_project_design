/*
 * @Descripttion: 建造者模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-14 11:55:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-15 11:04:22
 */
#include "../create_pattern/class_builder.h"
#include "../google_test.h"

TEST(testBuilder, create) {
  ImplBuilder1* b1 = new ImplBuilder1();
  auto c1 = std::make_shared<Combine>();
  c1->SetBuilder(b1);
  auto p1 = c1->createFull();
  auto p2 = c1->createPart();
  p1->Print();
  p2->Print();
  delete p1;
  delete p2;
}