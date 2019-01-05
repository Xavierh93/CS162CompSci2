/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: The Ant class inherits from Critter. Most of the functions
 ** here control construction, moves, and breeding for this Critter.
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::swap;

#include "ant.hpp"

//Default constructor
Ant::Ant()
{
    x = 0;
    y = 0;
    age = 0;
    print = 'O';
}

//Constructor at x,y with age parameters
Ant::Ant(int xCoord, int yCoord, int a)
{
    x = xCoord;
    y = yCoord;
    age = a;
    print = 'O';
}

//Returns age
int Ant::getAge()
{
    return age;
}

//Increases age
void Ant::setAge(int a)
{
    age += a;
}

//Returns x location (horizontal)
int Ant::getX()
{
    return x;
}

//Sets x location (horizontal)
void Ant::setX(int x)
{
    this->x = x;
}

//Returns y location (vertical)
int Ant::getY()
{
    return y;
}

//Sets y location (vertical)
void Ant::setY(int y)
{
    this->y = y;
}

//Returns print character
char Ant::getPrint()
{
    return print;
}

//Sets print character
void Ant::setPrint(char c)
{
    print = c;
}

//Control's the ant's move
void Ant::move(Board* b)
{
    //Increase age by 1
    setAge(1);

    //Generates a random number within 1-4
    //1 = up, 2 = down, 3 = left, 4 = right
    int r = rand() % 4 + 1;
    bool checkedAbove = false,
         checkedBelow = false,
         checkedLeft = false,
         checkedRight = false;

    //Looks for a random direction to move until
    //all directions are checked
    while (checkedAbove == false || checkedBelow == false || checkedLeft == false || checkedRight == false)
    {
        if (r == 1){ //Up
            //If spot is empty, move there
            if (b->getCritter(x, y-1)->getPrint() == ' '){
                b->swapCritters(x, y, x, y-1);
                //Adjust Y location
                y--;
                checkedAbove = true;
                checkedBelow = true;
                checkedLeft = true;
                checkedRight = true;
            }
            //Else, pick a new direction
            else
            {
                r = rand() % 4 + 1;
                checkedAbove = true;
            }
        }
        else if (r == 2){ //Down
            //If spot is empty, move there
            if (b->getCritter(x, y+1)->getPrint() == ' '){
                b->swapCritters(x, y, x, y+1);
                //Adjust Y location
                y++;
                checkedAbove = true;
                checkedBelow = true;
                checkedLeft = true;
                checkedRight = true;
            }
            //Else, pick a new direction
            else
            {
                r = rand() % 4 + 1;
                checkedBelow = true;
            }
        }
        else if (r == 3){ //Left
            //If spot is empty, move there
            if (b->getCritter(x-1, y)->getPrint() == ' '){
                b->swapCritters(x, y, x-1, y);
                //Adjust X location
                x--;
                checkedAbove = true;
                checkedBelow = true;
                checkedLeft = true;
                checkedRight = true;
            }
            //Else, pick a new direction
            else
            {
                r = rand() % 4 + 1;
                checkedLeft = true;
            }
        }
        else if (r == 4){ //Right
            //If spot is empty, move there
            if (b->getCritter(x+1, y)->getPrint() == ' '){
                b->swapCritters(x, y, x+1, y);
                //Adjust X location
                x++;
                checkedAbove = true;
                checkedBelow = true;
                checkedLeft = true;
                checkedRight = true;
            }
            //Else, pick a new direction
            else
            {
                r = rand() % 4 + 1;
                checkedRight = true;
            }
        }
    }

    //Ant breeds every 3 steps
    if (getAge() % 3 == 0 && getAge() > 0)
        breed(b);
}

//Controls the ant's breeding sequence
void Ant::breed(Board* b)
{
    //Generates a random number within 1-4
    //1 = up, 2 = down, 3 = left, 4 = right
    int r = rand() % 4 + 1;
    bool checkedAbove = false,
         checkedBelow = false,
         checkedLeft = false,
         checkedRight = false;

    //Looks for a random blank adjacent space until
    //all directions are checked
    while (checkedAbove == false || checkedBelow == false || checkedLeft == false || checkedRight == false)
    {
        if (r == 1){ //Up
            //If spot is empty, breed there
            if (b->getCritter(x, y-1)->getPrint() == ' '){
                b->addCritter(x, y-1, 'a');
                b->getCritter(x, y-1)->setMoved(1);
                checkedAbove = true;
                checkedBelow = true;
                checkedLeft = true;
                checkedRight = true;
            }
            //Else, pick a new direction
            else
            {
                r = rand() % 4 + 1;
                checkedAbove = true;
            }
        }
        else if (r == 2){ //Down
            //If spot is empty, breed there
            if (b->getCritter(x, y+1)->getPrint() == ' '){
                b->addCritter(x, y+1, 'a');
                b->getCritter(x, y+1)->setMoved(1);
                checkedAbove = true;
                checkedBelow = true;
                checkedLeft = true;
                checkedRight = true;
            }
            //Else, pick a new direction
            else
            {
                r = rand() % 4 + 1;
                checkedBelow = true;
            }
        }
        else if (r == 3){ //Left
            //If spot is empty, breed there
            if (b->getCritter(x-1, y)->getPrint() == ' '){
                b->addCritter(x-1, y, 'a');
                b->getCritter(x-1, y)->setMoved(1);
                checkedAbove = true;
                checkedBelow = true;
                checkedLeft = true;
                checkedRight = true;
            }
            //Else, pick a new direction
            else
            {
                r = rand() % 4 + 1;
                checkedLeft = true;
            }
        }
        else if (r == 4){ //Right
            //If spot is empty, breed there
            if (b->getCritter(x+1, y)->getPrint() == ' '){
                b->addCritter(x+1, y, 'a');
                b->getCritter(x+1, y)->setMoved(1);
                checkedAbove = true;
                checkedBelow = true;
                checkedLeft = true;
                checkedRight = true;
            }
            //Else, pick a new direction
            else
            {
                r = rand() % 4 + 1;
                checkedRight = true;
            }
        }
    }
}

