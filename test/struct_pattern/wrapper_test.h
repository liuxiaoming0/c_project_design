/*
 * @Descripttion: 支持递归的包装类
 * @version:
 * @Author: danae
 * @Date: 2022-07-17 16:34:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-18 09:07:53
 */
#include "../google_test.h"
#include "../struct_pattern/wrapper_test.h"

TEST(testWrapper, create) {
  Impl1Origin* p1 = new Impl1Origin();
  Impl1Wrapper* p2 = new Impl1Wrapper(p1);
  Impl2Wrapper* p3 = new Impl2Wrapper(p2);
  printf("%s\n", p3->Process().c_str());  // Impl2Wrapper(Impl1Wrapper(Impl1Origin))
  delete p1;
  delete p2;
  delete p3;
}