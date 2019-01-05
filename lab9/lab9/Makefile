CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: lab9

lab9: main.o functions.o queue.o palindrome.o
	$(CC) main.o functions.o queue.o palindrome.o -o lab9

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

functions.o: functions.cpp functions.hpp
	$(CC) $(CFLAGS) functions.cpp

queue.o: queue.cpp queue.hpp
	$(CC) $(CFLAGS) queue.cpp

palindrome.o: palindrome.cpp palindrome.hpp
	$(CC) $(CFLAGS) palindrome.cpp

clean:
	rm -r *.o lab9
