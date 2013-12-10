// Author: Wang Gang  <hk.wang@gmail.com>
// Last Changed: 2013/12/5
// Purpose: build unittest for loadint.h/cc using sample data
//

#include "loadints.h"
#include "gtest/gtest.h"
#include "glog/logging.h"

TEST(LoadIntsTest, DefaultConstructor) {
  IntArray ia0_;
  EXPECT_EQ(0u, ia0_.int_num());
  EXPECT_TRUE( NULL == ia0_.numbers());
}

TEST(LoadIntsTest, EmptyFile) {
  IntArray ia1_;
  // int_test0 is a empty file
  bool ret = ia1_.Read("int_test0.txt");
  ASSERT_FALSE(ret);
  EXPECT_EQ(0u, ia1_.int_num());
  EXPECT_FALSE( NULL == ia1_.numbers());
}

TEST(LoadIntsTest, IntFile) {
  IntArray ia2_;
  // int_test1 contains a list of ints
  bool  ret = ia2_.Read("int_test1.txt");
  ASSERT_TRUE(ret);
  EXPECT_EQ(8u, ia2_.int_num());
  EXPECT_FALSE( NULL == ia2_.numbers());
}

TEST(LoadIntsTest, NoisyFile) {
  IntArray ia3_;
  // int_test2 contains a list of ints with some string
  bool ret = ia3_.Read("int_test2.txt");
  ASSERT_TRUE(ret);
  EXPECT_EQ(3u, ia3_.int_num());
  EXPECT_FALSE( NULL == ia3_.numbers());
}

