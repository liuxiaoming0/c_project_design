#pragma once
#include <string>
#include <unordered_map>
#include <mutex>

using CFG_KV = std::unordered_map<std::string, std::string>;

class Ccfg{
    public:
        Ccfg(const Ccfg&) = delete;
        ~Ccfg() {cfg_kv_.clear(); delete cfg_; cfg_ = nullptr;}
        static Ccfg* getInstance();
        void setCfgPath(const std::string cfg_path) noexcept {cfg_path_ = cfg_path;};
        const CFG_KV& getCfg() {return cfg_kv_;};

    private:
        Ccfg();
    private:
        std::string cfg_path_;
        CFG_KV cfg_kv_;
        static Ccfg* cfg_;
};

# if 0 // 多进程/多线程不安全
Ccfg* Ccfg::getInstance() {
    if (cfg_ == nullptr) {
        cfg_ = new Ccfg;
    }
    return cfg_;
}
# endif
Ccfg* Ccfg::getInstance() {

    if (cfg_ == nullptr) {
        cfg_ = new Ccfg;
    }
    return cfg_;
}