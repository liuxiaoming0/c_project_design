/*
 * @Descripttion: 状态模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-24 19:51:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-26 10:51:24
 */

#include "../../behavior_pattern/class_state.h"
#include "../google_test.h"

TEST(testState, create) {
  auto p_phone = new Phone();
  p_phone->LockClick();
  p_phone->PlayClick();
  p_phone->UnLockClick();
  RELEASE_PTR(p_phone);
}