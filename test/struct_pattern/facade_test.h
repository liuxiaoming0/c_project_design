/*
 * @Descripttion: 外观模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-18 09:21:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-18 14:41:08
 */
#include "../../struct_pattern/class_facade.h"
#include "../google_test.h"

TEST(testFacade, create) {
  System1* p1;
  System2* p2;
  Facade* p3 = new Facade(p1, p2);
  p3->Init();
}