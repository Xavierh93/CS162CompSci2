CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: project2

project2: main.o animal.o penguin.o tiger.o turtle.o zoo.o
	$(CC) main.o animal.o penguin.o tiger.o turtle.o zoo.o -o project2

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

animal.o: animal.cpp
	$(CC) $(CFLAGS) animal.cpp

penguin.o: penguin.cpp penguin.hpp
	$(CC) $(CFLAGS) penguin.cpp

tiger.o: tiger.cpp tiger.hpp
	$(CC) $(CFLAGS) tiger.cpp

turtle.o: turtle.cpp turtle.hpp
	$(CC) $(CFLAGS) turtle.cpp

zoo.o: zoo.cpp zoo.hpp
	$(CC) $(CFLAGS) zoo.cpp

clean:
	rm -r *.o project2
