CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: lab2

lab2: main.o count_letters.o output_letters.o
	$(CC) main.o count_letters.o output_letters.o -o lab2

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

count_letters.o: count_letters.cpp count_letters.hpp
	$(CC) $(CFLAGS) count_letters.cpp

output_letters.o: output_letters.cpp output_letters.hpp
	$(CC) $(CFLAGS) output_letters.cpp

clean:
	rm -r *.o lab2
