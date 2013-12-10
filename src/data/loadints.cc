// Author: Wang Gang  <hk.wang@gmail.com>
// Last Changed: 2013/12/10
// Purpose: load int array from txt file 
//

#include "loadints.h"
#include <stdio.h>
#include <stdlib.h>
#include "glog/logging.h"

bool IntArray::Read(const char* filename) {
  if (NULL == filename) {
    LOG(WARNING)<<"filename doesnot exist";
    return false;
  }

  uint32_t line_num = FirstLoad(filename);
  if (0u >= line_num) {
    LOG(WARNING)<<"first load fails";
    return false;
  }
  LOG(INFO)<<"first load successfull, total line: "<<line_num;

  uint32_t int_num = SecondLoad(filename, line_num);
  if (0u >= int_num) {
    LOG(WARNING)<<"second load fails, no number is loaded";
    return false;
  }
  LOG(INFO)<<"second load successful, total number: "<<int_num_;

  return true;
}

uint32_t IntArray::FirstLoad(const char* filename) {
  FILE* fp = fopen(filename, "r"); 
  if (NULL == fp) {
    LOG(WARNING)<<filename<<" :first load cannot open file";
    return 0;
  }
  char buf[100];
  uint32_t index = 0;
  while (fgets(buf, sizeof(buf), fp))
    ++index;
  fclose(fp);
  return index;
}

uint32_t IntArray::SecondLoad(const char* filename, const uint32_t line_num) {
  CHECK(line_num > 0);
  // open the file
  FILE* fp = fopen(filename, "r");
  if (NULL == fp) {
    LOG(WARNING)<<filename<<" :second load cannot open file";
    return 0;
  }

  numbers_ = new uint32_t [line_num];
  if (NULL == numbers_) {
    LOG(WARNING)<<"memory cannot be allocated";
    return 0;
  }
  memset(numbers_, 0, sizeof(uint32_t) * line_num);

  char buf[100];
  uint32_t index = 0;
  while (fgets(buf, sizeof(buf), fp) ) {
    uint32_t read_num = static_cast<uint32_t>(atoi(buf));
    if (0u == read_num) {
      LOG(WARNING)<<"read number is invalid";
      continue;
    }
    numbers_[index] = read_num;
    ++index;
  }
  
  fclose(fp);
  int_num_ = index;
  if ((NULL != numbers_) && (0 == int_num_)) {
    delete[] numbers_;
    numbers_ = NULL;
  }

  return index;
} 
