// Author: Wang Gang  <hk.wang@gmail.com>
//
#ifndef BASIC_QSORT_H_
#define BASIC_QSORT_H_

#include <stdlib.h>
#include "./sorter.h"
#include "glog/logging.h"

class QSorter : public Sorter {
 public:
  QSorter();
  ~QSorter();

  void Sort(void);

 private:
  static int IntComp(const void* x, const void* y) {
    return *(int*)x - *(int*)y;
  };

};

QSorter::QSorter() {
  LOG(INFO)<<"qsorter construct...";
}


QSorter::~QSorter(){
  LOG(INFO)<<"qsorter free...";
}

void QSorter::Sort(void) {
  LOG(INFO)<<"qsorting...";
  qsort(numbers_, size_, sizeof(uint32_t), IntComp);
}
#endif // BASIC_QSORT_H_

