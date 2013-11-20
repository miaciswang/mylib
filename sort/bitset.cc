// Author: Wang Gang  <hk.wang@gmail.com>
// Last Changed: 2013/11/8
// Purpose: Bitset  
//
#include "./bitset.h"
#include "glog/logging.h"

BitSet::BitSet() {
  bit_set_ = NULL;
  size_ = 0;
}

BitSet::~BitSet() {
  if ( NULL != bit_set_ ) {
    delete []bit_set_;
    bit_set_ = NULL;
  }
  size_ = 0;
}

bool BitSet::Resize(const uint32_t num_of_bits) {
  size_ = 1 + num_of_bits / BITSPERWORD;
  bit_set_ = new uint32_t [size_]; 
  if (NULL == bit_set_) {
    LOG(WARNING)<<"memory cannot be allocated";
    return false;
  }
  Reset();
  return true;
}

void BitSet::Reset(void) {
  memset(bit_set_, 0, sizeof(uint32_t) * size_); 
}

bool BitSet::HasBit(const uint32_t index) {
  return bit_set_[index>>SHIFT] & (1u << (index & MASK)) ;
}

void BitSet::SetBit(const uint32_t index) {
  bit_set_[index>>SHIFT] |= (1u << (index & MASK));
}

void BitSet::ClearBit(uint32_t index) {
  bit_set_[index>>SHIFT] &= ~(1u << (index &MASK));
}
