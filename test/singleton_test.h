#include "../create_pattern/class_singleton.h"
#include "google_test.h"

#if 0
int add(int a, int b) { return a + b; }
TEST(testCase, test0) { EXPECT_EQ(add(2, 3), 5); }
#endif

TEST(testSingleton, create) {
  std::string cfg_path = "../conf/design_conf.xml";
  Ccfg<CServercfg>::getInstance().init(cfg_path);
  auto cfg_kv = Ccfg<CServercfg>::getInstance().getSysCfg();
  for (auto one : cfg_kv) {
    printf("sys_kv, [%s]\n", one.first.c_str());
  }

  CServercfg::getInstance().init(cfg_path);
  auto specail_kv = CServercfg::getInstance().getSpecialCfg();
  for (auto one : specail_kv) {
    printf("specail_kv, [%s]\n", one.first.c_str());
  }
}
