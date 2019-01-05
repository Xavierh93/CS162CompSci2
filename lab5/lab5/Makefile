CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: lab5

lab5: main.o reverseString.o sumOfArray.o triangularNumber.o
	$(CC) main.o reverseString.o sumOfArray.o triangularNumber.o -o lab5

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

reverseString.o: reverseString.cpp reverseString.hpp
	$(CC) $(CFLAGS) reverseString.cpp

sumOfArray.o: sumOfArray.cpp sumOfArray.hpp
	$(CC) $(CFLAGS) sumOfArray.cpp

triangularNumber.o: triangularNumber.cpp triangularNumber.hpp
	$(CC) $(CFLAGS) triangularNumber.cpp

clean:
	rm -r *.o lab5
