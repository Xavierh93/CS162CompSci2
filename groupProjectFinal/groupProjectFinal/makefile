#
# Project: Group Project
# Authors: Hidayet Abay, Xavier Hollingsworth, Hannah Moon, and Nicholas Nystrom
# Date: 2/18/18
#


CXX = g++

CXXFLAGS = -std=c++0x

CXXFLAGS += -Wall

CXXFLAGS += -pedantic-errors

CXXFLAGS += -g

#CXXFLAGS += -O3

LDFLAGS = -lboost_date_time



OBJS =  ${SOURCES:.cpp=.o}

SRCS =  main.cpp ant.cpp board.cpp critter.cpp doodlebug.cpp game.cpp menu.cpp

HEADERS = ant.hpp board.hpp critter.hpp doodlebug.hpp game.hpp menu.hpp


#target: dependencies
#	rule to build
#

GroupProject: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} ${HEADERS} -o GroupProject

clean:
	rm GroupProject
