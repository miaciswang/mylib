// Author: Wang Gang  <hk.wang@gmail.com>
// Last Changed: 2013/11/8
// Purpose: Bitset  
//
#ifndef BASIC_BITSET_H_
#define BASIC_BITSET_H__

#include <stdint.h>
#include "glog/logging.h"

#define BITSPERWORD 32
#define SHIFT 5 
#define MASK 0x1F

class BitSet {
 public:
   BitSet();
   ~BitSet();

   bool Resize(const uint32_t num_of_bits);
   void Reset(void);
   bool HasBit(const uint32_t index);
   void SetBit(const uint32_t index);
   void ClearBit(const uint32_t index);

  private:
   uint32_t* bit_set_;
   uint32_t size_;
};
#endif
