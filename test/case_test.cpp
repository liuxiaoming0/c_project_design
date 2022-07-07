#include "google_test.h"

int add(int a, int b) { return a + b; }
TEST(testCase, test0) { EXPECT_EQ(add(2, 3), 5); }
