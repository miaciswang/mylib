// Author: Wang Gang  <hk.wang@gmail.com>
// Last Changed: 2013/11/8
// Purpose: sort int numbers using bitset  
//
#ifndef BASIC_BITSORT_H_
#define BASIC_BITSORT_H_

#include <stdint.h>
#include "./sorter.h"
#include "./bitset.h"
#include "glog/logging.h"

static const uint32_t kMaxInt = 1000000;

class BitSorter : public Sorter {
 public:
  BitSorter();
  ~BitSorter();
  
  bool Init(const uint32_t numbers[], const uint32_t size); 
  void Sort(void); 
  
 private:
  BitSet* bitset_;
};

BitSorter::BitSorter() {
  bitset_ = NULL;
  LOG(INFO)<<"bitsorter construct...";
}

BitSorter::~BitSorter() {
  if (NULL != bitset_ ) 
    delete bitset_;
  LOG(INFO)<<"bitsorter free...";
}

bool BitSorter::Init(const uint32_t numbers[], const uint32_t size) {
  LOG(INFO)<<"bitsort initialize...";
  CHECK_NOTNULL(numbers);
  CHECK(size > 0);
  size_ = size;
  numbers_ = new uint32_t [size_];
  if (NULL == numbers_ ) {
    LOG(WARNING)<<"memory cannot be allocated";
    return false; 
  }
  memset(numbers_, 0, sizeof(uint32_t) * size_);
  for (uint32_t i = 0; i < size_; ++i)  
    numbers_[i] = *(numbers + i);
  
  bitset_ = new BitSet();
  if (NULL == bitset_ ) {
    LOG(WARNING)<<"memory cannot be allocated";
    return false;
  }
  if ( ! bitset_->Resize(kMaxInt) ) {
    LOG(WARNING)<<"bitset resize fail";
    return false;
  }
  for (uint32_t i = 0; i < size_; ++i)  
    numbers_[i] = *(numbers + i);
  LOG(INFO)<<"data is loaded successfully";
  return true;
}

void BitSorter::Sort(void) {
  LOG(INFO)<<"bitsort...";
  for (uint32_t i = 0; i < size_; ++i)
    bitset_->SetBit(numbers_[i]);
  uint32_t idx = 0;
  for (uint32_t i = 0; i < kMaxInt; ++i) {
    if ( bitset_->HasBit(i) ) {
      numbers_[idx] = i;
      ++idx;
    }
  }
}
#endif // BASIC_BITSORT_H_ 

