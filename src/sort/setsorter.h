// Author: Wang Gang  <hk.wang@gmail.com>
//
#ifndef BASIC_SETSORT_H_
#define BASIC_SETSORT_H_

#include <stdlib.h>
#include <set>
#include "./sorter.h"
#include "glog/logging.h"

using namespace std;
class SetSorter : public Sorter {
 public:
  SetSorter();
  ~SetSorter();

  bool Init(const uint32_t numbers[], const uint32_t size);
  void Sort(void);

 private:
  set<uint32_t>* int_set_;
};

SetSorter::SetSorter() {
  int_set_ = NULL;
  LOG(INFO)<<"setsorter construct...";
}


SetSorter::~SetSorter(){
  if (NULL != int_set_ )
    delete int_set_;
  LOG(INFO)<<"setsorter free...";
}

bool SetSorter::Init(const uint32_t numbers[], const uint32_t size) {
  LOG(INFO)<<"setsorter initialize...";
  CHECK_NOTNULL(numbers);
  CHECK(size > 0);
  size_ = size;
  numbers_ = new uint32_t [size_];
  if (NULL == numbers_ ) {
    LOG(WARNING)<<"memory cannot be allocated";
    return false; 
  }
  int_set_ = new set<uint32_t>();
  if (NULL == int_set_ ) {
    LOG(WARNING)<<"memory cannot be allocated";
    return false;
  }
  for (uint32_t i = 0; i < size_; ++i)  
    numbers_[i] = *(numbers + i);
  return true;
}
    

void SetSorter::Sort(void) {
  LOG(INFO)<<"setsort...";
  for (uint32_t i = 0; i < size_; ++i) {
    int_set_->insert(numbers_[i]);
  }
  uint32_t index = 0;
  for (set<uint32_t>::iterator iter = int_set_->begin(); 
       iter != int_set_->end(); ++iter) 
    numbers_[index] = *iter;
}
#endif // BASIC_SETSORT_H_

