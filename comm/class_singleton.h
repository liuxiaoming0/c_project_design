#pragma once
#include <mutex>
#include <string>
#include <unordered_map>
#include "define.h"

template <typename T>
class Ccfg {
 public:
  // delete default contruct
  Ccfg(const Ccfg&) = delete;
  Ccfg& operator=(const Ccfg&) = delete;

  // release variance
  virtual ~Ccfg() {
    sys_cfg_.clear();
    db_cfg_.clear();
  }

  // get object, only entrance
  static T& getInstance() {
    static T cfg_;
    return cfg_;
  };

  // init params, parse conf file
  virtual void init(const std::string cfg_path) noexcept {
    cfg_path_ = cfg_path;
    // parse conf file
    sys_cfg_.emplace("base_flag", "true");
  };

  // read conf info
  virtual const CFG_KV& getSysCfg() final { return sys_cfg_; };
  virtual const CFG_DB& getDbCfg() final { return db_cfg_; };

  //  private:
 protected:
  Ccfg() = default;  // CServercfg() use

 private:
  std::string cfg_path_;
  CFG_KV sys_cfg_;
  CFG_DB db_cfg_;
};

class CServercfg : public Ccfg<CServercfg> {
 public:
  friend class Ccfg<CServercfg>;  // Ccfg class use CServercfg()
  CServercfg(const CServercfg&) = delete;
  CServercfg& operator=(const CServercfg&) = delete;
  ~CServercfg() = default;
  void init(const std::string& cfg_path) noexcept {
    Ccfg::init(cfg_path);
    // 解析特有配置
    special_cfg_.emplace("server_flag", "true");
  };
  const CFG_KV& getSpecialCfg() { return special_cfg_; };

 private:
  CServercfg() = default;

 private:
  CFG_KV special_cfg_;
};