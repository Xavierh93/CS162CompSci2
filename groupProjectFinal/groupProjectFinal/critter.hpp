/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: This is the header for the Critter class.
 *****************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

class Board;

class Critter
{
protected:
    int x;
    int y;
    int age;
    char print;
    bool moved;

public:
    Critter();
    Critter(int x, int y, int age, char print);
    int getX();
    int getY();
    bool getMoved();
    void setMoved(bool m);
    virtual void setX(int);
    virtual void setY(int);
    virtual char getPrint();
    virtual void setPrint(char);
    virtual void move(Board* b) {};
    virtual void breed(Board* b) {};
    virtual int getAge();
    virtual void setAge(int);
    ~Critter() {};
};

#endif
