// Author: Wang Gang  <hk.wang@gmail.com>
// Last Changed: 2013/11/8
// Purpose: Bitset  
//
#include "./bitset.h"
#include "gtest/gtest.h"

TEST(BitSet, Test) {
  BitSet bit_set;
  bit_set.Resize(32);
  for (uint32_t i = 0; i <= 32; ++i) {
    ASSERT_FALSE(bit_set.HasBit(i));
  }
  bit_set.SetBit(15);
  ASSERT_TRUE(bit_set.HasBit(15));
  bit_set.ClearBit(15);
  ASSERT_FALSE(bit_set.HasBit(15));
  bit_set.SetBit(10);
  bit_set.SetBit(17);
  ASSERT_TRUE(bit_set.HasBit(10));
  ASSERT_TRUE(bit_set.HasBit(17));
  bit_set.Reset();
  for (uint32_t i = 0; i <= 32; ++i) {
    ASSERT_FALSE(bit_set.HasBit(i));
  }
}
