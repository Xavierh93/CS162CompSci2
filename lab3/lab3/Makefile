CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: lab3

lab3: main.o die.o
	$(CC) main.o die.o -o lab3

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

die.o: die.cpp
	$(CC) $(CFLAGS) die.cpp

clean:
	rm -r *.o lab3
