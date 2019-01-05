CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: lab8

lab8: main.o binarySearch.o copyArray.o displayFile.o linearSearch.o readFile.o selectionSort.o showArray.o
	$(CC) main.o binarySearch.o copyArray.o displayFile.o linearSearch.o readFile.o selectionSort.o showArray.o -o lab8

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

binarySearch.o: binarySearch.cpp binarySearch.hpp
	$(CC) $(CFLAGS) binarySearch.cpp

copyArray.o: copyArray.cpp copyArray.hpp
	$(CC) $(CFLAGS) copyArray.cpp

displayFile.o: displayFile.cpp displayFile.hpp
	$(CC) $(CFLAGS) displayFile.cpp

linearSearch.o: linearSearch.cpp linearSearch.hpp
	$(CC) $(CFLAGS) linearSearch.cpp

readFile.o: readFile.cpp readFile.hpp
	$(CC) $(CFLAGS) readFile.cpp

selectionSort.o: selectionSort.cpp selectionSort.hpp
	$(CC) $(CFLAGS) selectionSort.cpp

showArray.o: showArray.cpp showArray.hpp
	$(CC) $(CFLAGS) showArray.cpp
clean:
	rm -r *.o *.txt lab8
