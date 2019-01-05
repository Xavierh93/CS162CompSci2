CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: lab6

lab6: main.o
	$(CC) main.o -o lab6

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -r *.o lab6
