/*
 * @Descripttion: 代理模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-19 12:25:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-19 12:25:20
 */
#include "../../struct_pattern/class_proxy.h"
#include "../google_test.h"

TEST(testProxy, create) {
  auto p1 = std::make_shared<ImplProxyServer>();
  p1->func1();
}