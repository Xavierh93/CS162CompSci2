CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: lab4

lab4: main.o university.o person.o building.o
	$(CC) main.o university.o person.o building.o -o lab4

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

person.o: person.cpp person.hpp
	$(CC) $(CFLAGS) person.cpp

building.o: building.cpp building.hpp
	$(CC) $(CFLAGS) building.cpp

university.o: university.cpp university.hpp
	$(CC) $(CFLAGS) university.cpp
clean:
	rm -r *.o lab4
