/*
 * @Descripttion:
 * @version:
 * @Author: danae
 * @Date: 2022-07-24 17:26:23
 * @LastEditors: danae
 * @LastEditTime: 2022-07-24 17:27:15
 */
#pragma once

#include <ctime>
#include "../comm/define.h"

// 编辑器，每次更改前备份
class ImplMemento;
class AbtractMemento;
class Editor {
 public:
  friend class ImplMemento;
  Editor() {
    status_ = 0;
    text_ = "";
  }
  void Edit(const int status, const std::string text) {
    status_ = status;
    text_ = text;
  }
  ImplMemento* BackUp();
  void Restore(AbtractMemento* t);

  void Print() { printf("status=%d, text=%s\n", status_, text_.c_str()); }

 private:
  int status_;
  std::string text_;
};

// 抽象快照，只保存内容，对象和Editor相同
class AbtractMemento {
 public:
  virtual ~AbtractMemento() = default;
  virtual int GetStatus() = 0;
  virtual std::string GetText() = 0;
};

// 具体快照类
class ImplMemento : public AbtractMemento {
 public:
  friend class Editor;
  ImplMemento(Editor* t) {
    status_ = t->status_;
    text_ = t->text_;
    datetime_ = std::time(0);
  }
  int GetStatus() override { return status_; }
  std::string GetText() override { return text_; }

 private:
  int status_;
  std::string text_;
  std::time_t datetime_;
};

// 编辑器，每次备份，创建快照
ImplMemento* Editor::BackUp() { return new ImplMemento(this); }

// 编辑器，每次恢复，从快照里恢复内容
void Editor::Restore(AbtractMemento* t) {
  this->status_ = t->GetStatus();
  this->text_ = t->GetText();
}

// 命令，保存快照List表，并控制传递哪个快照给Editor类
class Command {
 public:
  Command(Editor* e) : editor_(e) {}
  void BackUp() { memos_.push_back(editor_->BackUp()); }
  void Undo() {
    auto p = memos_.back();
    memos_.pop_back();
    editor_->Restore(p);
  }

 private:
  std::vector<AbtractMemento*> memos_;
  Editor* editor_;
};