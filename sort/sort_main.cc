#include <stdio.h>
#include <sys/time.h>
#include "intarray.h"
#include "bitsorter.h"
#include "qsorter.h"
#include "setsorter.h"
#include "heapsorter.h"

#include "glog/logging.h"
#include "gtest/gtest.h"

double TimeCalc(timeval start_t, timeval end_t);
bool SortTest(Sorter* sorter, IntArray* int_array, const char* type);
 
int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  google::LogToStderr();

  char test_conf[] = "test";
  char src[] = "../test_data/int_numbers.txt";
  char dest[] = "./t";

  if ( 1 < argc ) {
    if (0 == strcmp(argv[1], test_conf) ) {
      testing::InitGoogleTest(&argc, argv);
      return RUN_ALL_TESTS();
    }
  }

  /*****************************
   * read from keyboard input  *
   *****************************
  uint32_t n = 0;
  int status = 0;
  while ( status != EOF ) {
    status = scanf("%d", &a[n]);
    printf("%d %d\n", a[n], status);
    if (status == 1)
      n++;
  }
  LOG(INFO)<<"number:"<<a;
  LOG(INFO)<<"size:"<<n;
  if ( (NULL == a) || (n <= 0) ) {
    LOG(WARNING)<<"no input data";
    return 1;
  }
  *****************************/
 
  // read numbers of txt 
  IntArray* int_array = new IntArray();
  if (!int_array->Create(src)) {
    LOG(WARNING)<<"no data loaded";
    return 1;
  }
   
  Sorter* sorter = NULL;
  const char* type = "sort";
  SortTest(sorter, int_array, type);
  type = "qsort";
  SortTest(sorter, int_array, type);
  type = "bitsort";
  SortTest(sorter, int_array, type);
  type = "setsort";
  SortTest(sorter, int_array, type);
  type = "heapsort";
  SortTest(sorter, int_array, type);

  delete int_array; 
  return 0; 
}

double TimeCalc(timeval start_t, timeval end_t) {
   return (end_t.tv_sec - start_t.tv_sec) * 1000000 + 
          (end_t.tv_usec - start_t.tv_usec);
}

uint32_t SortIndex(const char* type) {
  uint32_t index = 0;
  char sort[] = "sort";
  char qsort[] = "qsort";
  char bitsort[] = "bitsort";
  char setsort[] = "setsort";
  char heapsort[] = "heapsort";

  if (0 == strcmp(type, sort)) index = 1;
  if (0 == strcmp(type, qsort)) index = 2;
  if (0 == strcmp(type, bitsort)) index = 3;
  if (0 == strcmp(type, setsort)) index = 4;
  if (0 == strcmp(type, heapsort)) index = 5;
  return index;
}

bool SortTest(Sorter* sorter, IntArray* int_array, const char* type) {
  timeval start_t1, start_t2, end_t;
  gettimeofday(&start_t1, NULL);
  switch ( SortIndex(type) ) {
    case 1: sorter = new Sorter(); break;
    case 2: sorter = new QSorter(); break;
    case 3: sorter = new BitSorter(); break;
    case 4: sorter = new SetSorter(); break;
    case 5: sorter = new HeapSorter(); break;
    default: 
      LOG(WARNING)<<"sort type is not defined";
      return false;
  }
  if ( !sorter->Init(int_array->numbers(), int_array->int_num()) ) {
    LOG(WARNING)<<"sorter fail to be initialized";
    return false;
  }
  gettimeofday(&start_t2, NULL);
  sorter->Sort();
  gettimeofday(&end_t, NULL);
  double total_t = TimeCalc(start_t1, end_t);
  double sort_t = TimeCalc(start_t2, end_t);
  LOG(INFO)<<"total time: "<<total_t;
  LOG(INFO)<<"sort time: "<<sort_t;
  delete sorter;
  return true;
}
