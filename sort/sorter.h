// Author: Wang Gang  <hk.wang@gmail.com>
//
#ifndef BASIC_SORTER_H_
#define BASIC_SORTER_H_

#include <algorithm>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "glog/logging.h"

class Sorter
{
 public:
  Sorter();
  virtual ~Sorter();

  virtual bool Init(const uint32_t numbers[], const uint32_t size);
  virtual void Sort(void);
  bool Save(char* path);
  void INFO(void);
 
 protected:
  uint32_t* numbers_;
  uint32_t size_;
};

Sorter::Sorter() {
  numbers_ = NULL;
  size_ = 0;
  LOG(INFO)<<"sorter construct...";
}

Sorter::~Sorter() {
  if (NULL != numbers_ ) {
    delete []numbers_;
    numbers_ = NULL;
    }
  LOG(INFO)<<"sorter free...";
}

bool Sorter::Init(const uint32_t numbers[], const uint32_t size) {
  LOG(INFO)<<"sorter initialize...";
  CHECK_NOTNULL(numbers);
  CHECK(size > 0);
  numbers_ = new uint32_t [size];
  size_ = size;
  if (NULL == numbers_) {
    LOG(WARNING)<<"memory cannot be allocated";
    return false;
  }
  for (uint32_t i = 0; i < size_; ++i) 
    numbers_[i] = *(numbers + i);
  return true;
}

void Sorter::Sort(void) {
  LOG(INFO)<<"sorting...";
  std::sort(&numbers_[0], &numbers_[size_]);
}

void Sorter::INFO(void) {
  for (uint32_t i = 0; i < size_; ++i)
    LOG(INFO)<< numbers_[i];
}

bool Sorter::Save(char* path) {
  CHECK_NOTNULL(path);
  FILE* fp = fopen(path, "w");
  if (NULL == fp) {
    LOG(WARNING)<<"file fail to be written";
    return false;
  }
  char write_str[100];
  for (uint32_t i = 0; i < size_; ++i) {
    memset(write_str, 0, sizeof(write_str));
    sprintf(write_str, "%d\n", numbers_[i]);
    fputs(write_str, fp);
  }
  fclose(fp);
  return true;
}
#endif // BASIC_SORTER_H_

