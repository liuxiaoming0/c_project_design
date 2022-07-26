/*
 * @Descripttion: 策略
 * @version:
 * @Author: danae
 * @Date: 2022-07-20 16:23:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-20 16:25:29
 */

#include "../../behavior_pattern/class_strategy.h"
#include "../google_test.h"

TEST(testStrategy, create) {
  auto p_map = std::make_shared<CityMap>();
  auto p1 = new WalkStrategy();
  auto p2 = new BusStrategy();
  auto p3 = new TaxtStrategy();

  p_map->SetStrategy(p1);
  p_map->Navigation();
}