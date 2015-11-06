######################################

# Makefile written by Zev Kronenberg #

#     zev.kronenberg@gmail.com       #

######################################

CC=g++
CFLAGS= -Wall -std=c++0x -pthread  -lgtest  -lm -O3
INCLUDE=-Isrc/gtest-1.7.0/include/ -Isrc/lib
LIB=-L.

all: buildTest runTest buildExample clean

gtest:
	cd src/gtest-1.7.0 && mkdir build && cd build && cmake .. && make
libgtest:
	cp src/gtest-1.7.0/build/*.a .

buildTest: gtest libgtest
	$(CC) $(CFLAGS) $(INCLUDE) $(LIB) src/mainTest.cpp -lgtest -o runTests

buildExample:
	$(CC) $(CFLAGS) $(INCLUDE) $(LIB) src/example.cpp -o example
runTest:
	@./runTests && echo "Test success!" || echo "Test failure!" 

clean:
	rm -rf src/gtest-1.7.0/build && rm -rf runTests && rm *.a