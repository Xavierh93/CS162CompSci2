/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: The Doodlebug class inherits from Critter. It also includes
 ** an additional variable for lastEaten and a unique starve() function.
 ** The rest of the functions control construction, moves, and breeding.
 *****************************************************************************/

#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "doodlebug.hpp"

//Default constructor
Doodlebug::Doodlebug()
{
    x = 0;
    y = 0;
    age = 0;
    print = 'X';
    lastEaten = 0;
}

//Contructor with x,y location and age parameters
Doodlebug::Doodlebug(int xCoord, int yCoord, int a)
{
    this->x = xCoord;
    this->y = yCoord;
    this->age = a;
    this->print = 'X';
    this->lastEaten = 0;
}

//Returns age
int Doodlebug::getAge()
{
    return age;
}

//Increases age
void Doodlebug::setAge(int a)
{
    age += a;
}

//Returns x location (horizontal)
int Doodlebug::getX()
{
    return x;
}

//Sets x location (horizontal)
void Doodlebug::setX(int x)
{
    this->x = x;
}

//Returns y location (vertical)
int Doodlebug::getY()
{
    return y;
}

//Sets y location (vertical)
void Doodlebug::setY(int y)
{
    this->y = y;
}

//Returns print character
char Doodlebug::getPrint()
{
    return print;
}

//Sets print character
void Doodlebug::setPrint(char c)
{
    print = c;
}

//Control's the doodlebug's move
void Doodlebug::move(Board* b)
{
    bool antAbove = false;
    bool antBelow = false;
    bool antLeft = false;
    bool antRight = false;

    //Increase age by 1
    setAge(1);

    //Generates a random number within 1-4
    //1 = up, 2 = down, 3 = left, 4 = right
    int r = rand() % 4 + 1;
    bool checkedAbove = false,
         checkedBelow = false,
         checkedLeft = false,
         checkedRight = false;

    //Checks for existing adjacent ants first
    if (b->getCritter(x, y-1)->getPrint() == 'O')
        antAbove = true;
    if (b->getCritter(x, y+1)->getPrint() == 'O')
        antBelow = true;
    if (b->getCritter(x-1, y)->getPrint() == 'O')
        antLeft = true;
    if (b->getCritter(x+1, y)->getPrint() == 'O')
        antRight = true;

    //If there's an ant, swap places with it,
    //adjust Y or X location, then destroy the ant
    if (antAbove || antBelow || antLeft || antRight){
        //Set lastEaten back to 0
        lastEaten = 0;

        if (antAbove){
            b->swapCritters(x, y, x, y-1);
            y--;
            b->removeCritter(x, y+1);
        }
        else if (antBelow){
            b->swapCritters(x, y, x, y+1);
            y++;
            b->removeCritter(x, y-1);
        }
        else if (antLeft){
            b->swapCritters(x, y, x-1, y);
            x--;
            b->removeCritter(x+1, y);
        }
        else if (antRight){
            b->swapCritters(x, y, x+1, y);
            x++;
            b->removeCritter(x-1, y);
        }
    }
    //If there are no ants, move as normal
    else{
        //Increment lastEaten
        lastEaten++;

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
    }

    //Doodlebug breeds every 8 steps
    if (getAge() % 8 == 0 && getAge() != 0)
        breed(b);

    //If doodlebug hasn't eaten within 3 steps, starve
    if (lastEaten >= 3)
        starve(b);
}

//Controls the doodlebug's breeding sequence
void Doodlebug::breed(Board* b)
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
            //If spot is empty, move there
            if (b->getCritter(x, y-1)->getPrint() == ' '){
                b->addCritter(x, y-1, 'd');
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
            //If spot is empty, move there
            if (b->getCritter(x, y+1)->getPrint() == ' '){
                b->addCritter(x, y+1, 'd');
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
            //If spot is empty, move there
            if (b->getCritter(x-1, y)->getPrint() == ' '){
                b->addCritter(x-1, y, 'd');
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
            //If spot is empty, move there
            if (b->getCritter(x+1, y)->getPrint() == ' '){
                b->addCritter(x+1, y, 'd');
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

//Deletes a doodlebug when it starves
void Doodlebug::starve(Board* b){
    b->removeCritter(x, y);
}
