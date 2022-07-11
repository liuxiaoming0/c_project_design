#pragma once
#include <unordered_map>
#include <memory>

struct DB_INFO;
using CFG_KV = std::unordered_map<std::string, std::string>;
using CFG_DB = std::unordered_map<std::string, DB_INFO>;
#define RELEASE_PTR(p)        \
  if (p != nullptr) delete p; \
  p = nullptr;

struct DB_INFO {
  std::string name;
  std::string passwd;
  std::string ip;
  int port;
};