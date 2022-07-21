/*
 * @Descripttion:
 * @version:
 * @Author: danae
 * @Date: 2022-07-07 16:56:45
 * @LastEditors: danae
 * @LastEditTime: 2022-07-21 16:41:56
 */
#pragma once
#include <stdio.h>
#include <string.h>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

struct DB_INFO;
struct PROFILE;
using CFG_KV = std::unordered_map<std::string, std::string>;
using CFG_DB = std::unordered_map<std::string, DB_INFO>;
using Profile_KV = std::unordered_map<std::string, std::shared_ptr<PROFILE>>;

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

struct PROFILE {
  std::string profileID;
  std::string name;
  std::string address;
};