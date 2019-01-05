CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: lab7

lab7: main.o menu.o queue.o
	$(CC) main.o menu.o queue.o -o lab7

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(CFLAGS) menu.cpp

queue.o: queue.cpp queue.hpp
	$(CC) $(CFLAGS) queue.cpp

clean:
	rm -r *.o lab7
