/*
 * @Descripttion: 访问者
 * @version:
 * @Author: danae
 * @Date: 2022-07-20 16:23:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-26 14:24:28
 */

#include "../../behavior_pattern/class_visit.h"
#include "../google_test.h"

TEST(testVisit, create) {
  auto pA = std::make_shared<SystemA>("ABC", 10);
  auto pB = std::make_shared<SystemB>("abc", 20);

  auto p_log = new GetLogVisitor();
  auto p_metric = new GetMetricVisitor();

  pA->Accept(p_log);
  pB->Accept(p_log);

  pA->Accept(p_metric);
  pB->Accept(p_metric);

  RELEASE_PTR(p_log);
  RELEASE_PTR(p_metric);
}