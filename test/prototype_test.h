#include "../create_pattern/class_prototype.h"
#include "google_test.h"


TEST(testProtoType, create) {
  AbtractProtoType* t1 = new ImplPrototype1("abcde");
  auto p2 = t1->Clone();
  printf("p2->GetText()=%s\n", p2->GetText());
}
