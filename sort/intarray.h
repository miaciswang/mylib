// Author: Wang Gang  <hk.wang@gmail.com>
// Last Changed: 2013/11/8
// Purpose: build int array from txt file 
//
#ifndef BASIC_INTARRAY_H_
#define BASIC_INTARRAY_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "glog/logging.h"

class IntArray {
 public:
  IntArray();
  ~IntArray();
  
  bool Create(const char* filename);
  uint32_t* numbers(void) const { return numbers_; }
  uint32_t int_num(void) const {return int_num_; }

 private:
  /*****************************
   * Description: first scan the file to count file size
   * Parameter: filename
   * Return: number of lines, 0 is invalid
   *****************************/
  uint32_t FirstLoad(const char* filename);
  /***************************
   * Description: second scan the file and new memory to save numbers
   * Parameter: filename
   * Return: number of lines, 0 is invalid
   ***************************/
  uint32_t SecondLoad(const char* filename, const uint32_t line_num);

 private:
  uint32_t* numbers_; 
  uint32_t int_num_;
};

IntArray::IntArray() {
  numbers_ = NULL;
  int_num_ = 0;
  LOG(INFO)<<"intarray initialize...";
}

IntArray::~IntArray() {
  if ( NULL != numbers_ )
    delete numbers_;
    LOG(INFO)<<"intarray free...";
}

bool IntArray::Create(const char* filename) {
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
    LOG(WARNING)<<"second load fails";
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
  return index;
}
#endif // BASIC_INTARRAY_H_

