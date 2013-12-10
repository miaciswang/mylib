# makefile for sort

CC = g++
CXXFLAGS += -g -Wall -Wextra

USER_DIR = ../src
SORT_DIR = $(USER_DIR)/sort
SORT_HEADER = $(SORT_DIR)/*.h
DATA_DIR = $(USER_DIR)/data
TESTDATA_DIR = ../test_data

TARGET = sort_main loadints_test bitset_test 

all : $(TARGET)

sort_main : sort_main.o bitset.o loadints.o 
	$(CC) -o $@ $^ -lglog -lpthread

sort_main.o : $(SORT_DIR)/sort_main.cc $(SORT_HEADERS)
	$(CC) $(CXXFLAGS) -c $(SORT_DIR)/sort_main.cc 

bitset.o : $(SORT_DIR)/bitset.cc $(SORT_DIR)/bitset.h
	$(CC) $(CXXFLAGS) -c $(SORT_DIR)/bitset.cc

loadints.o : $(DATA_DIR)/loadints.cc $(DATA_DIR)/loadints.h
	$(CC) $(CXXFLAGS) -c $(DATA_DIR)/loadints.cc

loadints_test : loadints_test.o loadints.o
	$(CC) -o $@ $^ -lgtest_main -lglog -lpthread

loadints_test.o : $(DATA_DIR)/loadints_test.cc $(DATA_DIR)/loadints.h
	cp $(TESTDATA_DIR)/int_test* . ; \
	$(CC) $(CXXFLAGS) -c $(DATA_DIR)/loadints_test.cc

bitset_test : bitset_test.o bitset.o
	$(CC) -o $@ $^ -lgtest_main -lglog -lpthread

bitset_test.o : $(SORT_DIR)/bitset_test.cc $(SORT_DIR)/bitset.h
	$(CC) $(CXXFLAGS) -c $(SORT_DIR)/bitset_test.cc

clean:
	rm -f *.o
