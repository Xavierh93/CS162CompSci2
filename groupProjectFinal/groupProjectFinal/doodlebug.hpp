/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: This is the header for the Doodlebug class.
 *****************************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "critter.hpp"
#include "board.hpp"

class Doodlebug : public Critter
{
private:
    int lastEaten;

public:
    Doodlebug();
    Doodlebug(int xCoord, int yCoord, int a);
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    char getPrint();
    void setPrint(char);
    void move(Board* b);
    void breed(Board* b);
    void starve(Board* b);
    int getAge();
    void setAge(int);
    int getLastEaten();
    void setLastEaten(int);
};

#endif
