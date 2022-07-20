/*
 * @Descripttion:
 * @version:
 * @Author: danae
 * @Date: 2022-07-07 09:39:23
 * @LastEditors: danae
 * @LastEditTime: 2022-07-20 15:38:27
 */
// Copyright 2020 Tencent Inc.  All rights reserved.
#include <iostream>
#include "google_test.h"

using namespace std;
int main(int argc, char* argv[]) {
  // testing::GTEST_FLAG(output) = "xml:"; //若要生成xml结果文件
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
}
