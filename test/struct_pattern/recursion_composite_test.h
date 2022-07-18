/*
 * @Descripttion: 递归组合模式
 * @version:
 * @Author: danae
 * @Date: 2022-07-17 17:42:16
 * @LastEditors: danae
 * @LastEditTime: 2022-07-18 14:41:16
 */
#include "../../struct_pattern/recursion_composite_test.h"
#include "../google_test.h"

TEST(testComposite, create) {
  AbtractNode* p1 = new Node("ab");
  AbtractNode* p2 = new Node("de");
  AbtractNode* p3 = new Node("cf");
  AbtractNode* p4 = new Node("qw");
  CompositeNode* cp1 = new CompositeNode();
  CompositeNode* cp2 = new CompositeNode();
  cp1->Add(p1);
  cp1->Add(p2);
  cp1->Add(p3);
  cp2->Add(cp1);
  cp2->Add(p4);
  printf("%s\n", cp2->DoProcess().c_str());  // branch(branch(leaf+leaf+leaf)+leaf)
  // delete cp1; // err,Segmentation fault
  delete cp2;
}