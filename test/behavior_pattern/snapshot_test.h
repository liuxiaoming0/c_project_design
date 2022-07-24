/*
 * @Descripttion: 快照，备份
 * @version:
 * @Author: danae
 * @Date: 2022-07-24 14:25:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-24 17:26:07
 */

#include "../../behavior_pattern/class_snapshot.h"
#include "../google_test.h"

TEST(testSnapShot, create) {
  auto p_editor = new Editor();
  auto p_command = new Command(p_editor);

  // 更新前备份
  p_command->BackUp();
  p_editor->Edit(1, "change1");

  p_command->BackUp();
  p_editor->Edit(2, "change2");
  p_editor->Print();

  // 恢复快照
  p_command->Undo();
  p_editor->Print();

  RELEASE_PTR(p_editor);
  RELEASE_PTR(p_command);
}