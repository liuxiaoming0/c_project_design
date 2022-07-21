/*
 * @Descripttion: 迭代器
 * @version:
 * @Author: danae
 * @Date: 2022-07-21 19:55:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-21 19:55:30
 */

#include "../../behavior_pattern/class_iterator_v1.h"
#include "../google_test.h"

TEST(testIterator, create) {
  auto w = new WxGather();
  w->Init();

  for (auto it = w->GetIterator(); it->hasNext();) {
    auto data = it->GetData();
    printf("id=%s, name=%s, address=%s\n", data->profileID.c_str(), data->name.c_str(),
           data->address.c_str());
  }

  delete w;
}