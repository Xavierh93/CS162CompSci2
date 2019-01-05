/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: This is the main file that starts the menu.
 *****************************************************************************/

#include "menu.hpp"
#include "game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

//Function to display extra-credit at beginning of program.
void extraCredit()
{
    cout << "*Extra-Credit: Ask user to enter the number of time steps, the size of ";
    cout << "grid in rows and columns, the number of ants, and the number of ";
    cout << "doodlebugs*" << endl << endl;
    cout << "******Welcome to the Prey-Predator Simulation Game******" << endl;
}

//Main function starts the menu
int main() {
    //Sets a random seed
    srand(time(NULL) + rand());

    //Create variables
    int timeSteps = 0, rows = 20, columns = 20, ants = 100, doodlebugs = 5;
    Game* gamePtr;

    extraCredit();

    menuStart(gamePtr, &timeSteps, &rows, &columns, &ants, &doodlebugs);

    return 0;
}
