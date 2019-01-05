CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: project1

project1: main.o menu.o ant.o
	$(CC) main.o menu.o ant.o -o project1

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

menu.o: menu.cpp menu.hpp
	$(CC) $(CFLAGS) menu.cpp

ant.o: ant.cpp ant.hpp
	$(CC) $(CFLAGS) ant.cpp

clean:
	rm -r *.o project1
