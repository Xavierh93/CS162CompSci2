/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: This is the header for the Ant class.
 *****************************************************************************/

#include "critter.hpp"
#include "board.hpp"

#ifndef ANT_HPP
#define ANT_HPP

class Ant : public Critter
{
public:
    Ant();
    Ant(int xCoord, int yCoord, int a);
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    char getPrint();
    void setPrint(char);
    void move(Board* b);
    void breed(Board* b);
    int getAge();
    void setAge(int);
};

#endif
