// Author: Wang Gang  <hk.wang@gmail.com>
//
#ifndef BASIC_HEAPSORT_H_
#define BASIC_HEAPSORT_H_

#include <algorithm>
#include "./sorter.h"
#include "glog/logging.h"

class HeapSorter : public Sorter {
 public:
  HeapSorter();
  ~HeapSorter();

  void Sort(void);
};

HeapSorter::HeapSorter() {
  LOG(INFO)<<"heapsorter construct...";
}


HeapSorter::~HeapSorter(){
  LOG(INFO)<<"heapsorter free...";
}

void HeapSorter::Sort(void) {
  LOG(INFO)<<"heapsort...";
  std::make_heap(&numbers_[0], &numbers_[size_]);
  std::sort_heap(&numbers_[0], &numbers_[size_]);
}
#endif // BASIC_HEAPSORT_H_

