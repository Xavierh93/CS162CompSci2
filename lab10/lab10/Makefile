CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: lab10

lab10: main.o functions.o  iterative.o recursive.o
	$(CC) main.o functions.o  iterative.o recursive.o -o lab10

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

functions.o: functions.cpp functions.hpp
	$(CC) $(CFLAGS) functions.cpp

iterative.o: iterative.cpp iterative.hpp
	$(CC) $(CFLAGS) iterative.cpp

recursive.o: recursive.cpp recursive.hpp
	$(CC) $(CFLAGS) recursive.cpp

clean:
	rm -r *.o lab10
