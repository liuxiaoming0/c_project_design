/*
 * @Descripttion: 责任链
 * @version:
 * @Author: danae
 * @Date: 2022-07-19 15:02:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-19 15:02:08
 */

#include "../../behavior_pattern/class_clain_responsibility.h"
#include "../google_test.h"

TEST(testClain, create) {
  Impl1Chain* p1 = new Impl1Chain();
  Impl2Chain* p2 = new Impl2Chain();
  Impl3Chain* p3 = new Impl3Chain();

  p1->SetNextChain(p2)->SetNextChain(p3);

  auto p4 = std::make_shared<ImplEntrance>(p1);
  p4->ButtonProcess(3);

  delete p1;
  delete p2;
  delete p3;
}