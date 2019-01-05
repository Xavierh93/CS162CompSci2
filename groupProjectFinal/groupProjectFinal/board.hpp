/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: This is the header for the Board class.
 *****************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "critter.hpp"

class Board
{
private:
    int width;
    int height;
    Critter*** board;

public:
    Board();
    Board(int w, int h);
    Critter* getCritter(int x, int y);
    void swapCritters(int x1, int y1, int x2, int y2);
    void removeCritter(int x, int y);
    void addCritter(int x, int y, char type);
    void moveCritter(int x, int y, Board* b);
    void markCritter(int x, int y);
    void clearMarks();
    void printBoard();
    char getStatus(int x, int y);
    void setStatus(int x, int y, char c);
    int getHeight();
    int getWidth();
    void populate(int numAnts, int numDbugs);
    ~Board();
};


#endif

