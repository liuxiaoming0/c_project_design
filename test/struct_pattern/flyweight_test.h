/*
 * @Descripttion: 享元模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-18 14:55:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-18 14:42:02
 */
#include "../../struct_pattern/class_flyweight.h"
#include "../google_test.h"

TEST(testFlyweight, create) {
  Forest* forest = new Forest();
  Attr attr = {1, 100, "green", "wenli"};
  forest->AddTree(attr, 0, 100);
  forest->AddTree(attr, 100, 100);
  forest->Show();
}