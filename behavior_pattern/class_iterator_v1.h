/*
 * @Descripttion: iterator
 * @version:
 * @Author: danae
 * @Date: 2022-07-21 09:14:03
 * @LastEditors: danae
 * @LastEditTime: 2022-07-21 19:53:47
 */
#pragma once
#include "../comm/define.h"

class AbtractIterator {
 public:
  virtual ~AbtractIterator() = default;
  virtual bool hasNext() = 0;

 protected:
  int index_;
};

class AbtractGather;
class FriendIterator : public AbtractIterator {
 public:
  FriendIterator(AbtractGather* g, const Profile_KV& kv) : g_(g), kv_(kv) { init(); }
  bool hasNext() override {
    if (this->index_ < static_cast<int>(kv_.size() - 1)) {
      this->index_++;
      return true;
    }
    return false;
  }

  const std::shared_ptr<PROFILE> GetData() { return kv_[index_id_[this->index_]]; }

 private:
  void init() {
    int i = 0;
    for (auto it : kv_) {
      index_id_.insert(std::make_pair(i++, it.first));
    }
  }

 private:
  AbtractGather* g_;
  std::unordered_map<int, std::string> index_id_;
  Profile_KV kv_;
};

class AbtractGather {
 public:
  virtual ~AbtractGather() = default;
  virtual void Init() = 0;
};

class WxGather : public AbtractGather {
 public:
  WxGather() = default;
  void Init() override {
    for (int i = 0; i < 5; i++) {
      auto one = std::make_shared<PROFILE>();
      one->address = "SH";
      one->name = "HONG";
      one->profileID = std::to_string(i);
      // friend_kv_.insert(std::pair<std::string, std::shared_ptr<PROFILE>>(one->profileID, one));
      friend_kv_.insert(std::make_pair(one->profileID, one));
    }
    it_ = new FriendIterator(this, friend_kv_);
  }

  FriendIterator* GetIterator() { return it_; };

 private:
  Profile_KV friend_kv_;
  FriendIterator* it_;
};