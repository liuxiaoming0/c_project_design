#pragma once
#include <stdio.h>
#include <string.h>
#include <memory>
#include <unordered_map>

struct DB_INFO;
using CFG_KV = std::unordered_map<std::string, std::string>;
using CFG_DB = std::unordered_map<std::string, DB_INFO>;
#define RELEASE_PTR(p)        \
  if (p != nullptr) delete p; \
  p = nullptr;

#define PRINTF(info) printf("%s::%s(%d):%s\n", __FILE__, __FUNCTION__, __LINE__, info)

struct DB_INFO {
  std::string name;
  std::string passwd;
  std::string ip;
  int port;
};