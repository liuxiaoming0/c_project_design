/*
 * @Descripttion: 迭代器
 * @version:
 * @Author: danae
 * @Date: 2022-07-21 19:55:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-21 23:17:36
 */

#include "../../behavior_pattern/class_iterator_v2.h"
#include "../google_test.h"

TEST(testIterator, create) {
  /// vector存放基本类型
  auto p1 = new Container<int>();
  for (int i = 0; i < 5; i++) {
    p1->AddData(i);
  }
  Iterator<int, Container<int>>* it = p1->CreateIterator();
  for (it->first(); !it->hasNext(); it->next()) {
    printf("datas=[%d]\n", *(it->cur()));
  }
  delete p1;

  /// vector存放CData类， 里面是int值
  auto s1 = std::make_shared<Container<CData>>();
  for (int j = 10; j > 0; j--) {
    s1->AddData(CData(j));
  }
  Iterator<CData, Container<CData>>* s2 = s1->CreateIterator();
  for (s2->first(); !s2->hasNext(); s2->next()) {
    printf("datas=[%d]\n", s2->cur()->GetData());
  }
}