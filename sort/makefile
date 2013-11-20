# makefile for sort

CC = g++
CXXFLAGS += -g -Wall -Wextra

TARGET = sort_main
SORT_HEADERS = ./*.h

$(TARGET): sort_main.o bitset.o bitset_test.o
	$(CC) -o $(TARGET) sort_main.o bitset.o bitset_test.o \
	      -lglog -lgtest -lpthread
sort_main.o: sort_main.cc $(SORT_HEADERS)
	$(CC) -c sort_main.cc 
bitset.o: bitset.cc bitset.h
	$(CC) $(CXXFLAGS) -c bitset.cc
bitset_test.o: bitset_test.cc bitset.h
	$(CC) $(CXXFLAGS) -c bitset_test.cc
clean:
	rm -f *.o
