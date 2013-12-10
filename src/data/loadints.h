// Author: Wang Gang  <hk.wang@gmail.com>
// Last Changed: 2013/12/10
// Purpose: load int array from txt file 
//
#ifndef BASIC_LOADINTS_H_
#define BASIC_LOADINTS_H_

#include <stdint.h>
#include <stddef.h>
#include "glog/logging.h"

class IntArray {
 public:
  IntArray() {
    numbers_ = NULL;
    int_num_ = 0;
  }

  ~IntArray() {
   if ( NULL != numbers_ )
     delete[] numbers_;
  }

  // read number from a file 
  bool Read(const char* filename);

  // get the numbers  
  uint32_t* numbers(void) { return numbers_; }
  const uint32_t* numbers(void) const { return numbers_; }

  // get the int num size
  uint32_t int_num(void) const { return int_num_; }

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
   * Return: number of ints, 0 is invalid
   ***************************/
  uint32_t SecondLoad(const char* filename, const uint32_t line_num);

 private:
  uint32_t* numbers_; 
  uint32_t int_num_;
};

#endif // BASIC_LOADINTS_H_

