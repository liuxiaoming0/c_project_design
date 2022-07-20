/*
 * @Descripttion: 命令
 * @version:
 * @Author: danae
 * @Date: 2022-07-20 16:23:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-20 16:25:29
 */

#include "../../behavior_pattern/class_command.h"
#include "../google_test.h"

TEST(testCommand, create) {
  ImplReceiver* recv = new ImplReceiver();

  OpenCommand* cmd1 = new OpenCommand(recv);
  ChangeCommand* cmd2 =
      new ChangeCommand(recv, "args-a", "args-b");  // 指定处理的对象和参数（电视、空调等）
  ImplInvoker* i = new ImplInvoker();               // 只负责执行命令，坚决不传参
  i->AddCommand(cmd1);
  i->AddCommand(cmd2);
  i->OpenCmdAny();
  i->ChangeCmdAny();
  RELEASE_PTR(recv);
  RELEASE_PTR(cmd1);
  RELEASE_PTR(cmd2);
  RELEASE_PTR(i);
}