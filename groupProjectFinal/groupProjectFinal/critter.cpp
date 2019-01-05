/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: The base Critter class tracks age, location, and whether or
 ** not a Critter has been moved on the board.
 *****************************************************************************/

#include "critter.hpp"

//Default constructor
Critter::Critter()
{
    x = 1;
    y = 1;
    age = 0;
    print = ' ';
    moved = false;
}

//Constructor with x,y location, age, and print parameters
Critter::Critter(int x, int y, int age, char print)
{
    this->x = x;
    this->y = y;
    this->age = age;
    this->print = print;
    moved = false;
}

//Returns x location (horizontal)
int Critter::getX()
{
    return x;
}

//Returns y location (vertical)
int Critter::getY()
{
    return y;
}

//Sets x location (horizontal)
void Critter::setX(int xNum)
{
    x = xNum;
}

//Sets y location (vertical)
void Critter::setY(int yNum)
{
    y = yNum;
}

//Returns moved flag
bool Critter::getMoved()
{
    return moved;
}

//Sets the moved flag
void Critter::setMoved(bool m)
{
    moved = m;
}

//Returns print character
char Critter::getPrint()
{
    return print;
}

//Sets print character
void Critter::setPrint(char c)
{
    this->print = c;
}

//Returns age
int Critter::getAge()
{
    return age;
}

//Increases age
void Critter::setAge(int a)
{
    age += a;
}
