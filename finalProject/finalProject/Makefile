CC=g++ -std=c++11

CFLAGS=-c -Wall -pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: finalProject

finalProject: main.o functions.o space.o inventory.o user.o exitSpace.o normalSpace.o trapSpace.o
	$(CC) main.o functions.o space.o inventory.o user.o exitSpace.o normalSpace.o trapSpace.o -o finalProject

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

functions.o: functions.cpp functions.hpp
	$(CC) $(CFLAGS) functions.cpp

space.o: space.cpp space.hpp
	$(CC) $(CFLAGS) space.cpp

inventory.o: inventory.cpp inventory.hpp
	$(CC) $(CFLAGS) inventory.cpp

user.o: user.cpp user.hpp
	$(CC) $(CFLAGS) user.cpp

exitSpace.o: exitSpace.cpp exitSpace.hpp
	$(CC) $(CFLAGS) exitSpace.cpp

normalSpace.o: normalSpace.cpp normalSpace.hpp
	$(CC) $(CFLAGS) normalSpace.cpp

trapSpace.o: trapSpace.cpp trapSpace.hpp
	$(CC) $(CFLAGS) trapSpace.cpp

clean:
	rm -r *.o finalProject
