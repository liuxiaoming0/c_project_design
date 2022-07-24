/*
 * @Descripttion: 观察者
 * @version:
 * @Author: danae
 * @Date: 2022-07-24 09:38:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-24 11:36:00
 */

#include "../../behavior_pattern/class_observer.h"
#include "../google_test.h"

TEST(testObserver, create) {
  EventManger* p = new EventManger();
  FileLog* p1 = new FileLog(p);
  SendMailLog* p2 = new SendMailLog(p);
  SendInfoLog* p3 = new SendInfoLog(p);

  delete p2;  // 析构中注销订阅，避免向空指针发消息
  auto p4 = std::make_shared<Editor>(p);
  p4->Update();
}