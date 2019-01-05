/******************************************************************************
 ** Program name:   Final Project - Cube Tessarack
 ** Authors: Xavier Hollingsworth
 ** Date: 03/10/2018
 ** Description:    This is a text-based game where the user must navigate through
 ** a 2-dimensional cube and find the exit before time runs out.
 ** *Based loosely off of the film Cube (1997). The trick to the game is that
 ** only prime power numbers contain an exit and they also have to be on the edge
 ** of the cube. Composite numbers contain traps. And prime numbers also contain
 ** an item. A key is needed to exit the cube.
 *****************************************************************************/

#include "functions.hpp"
#include <iostream>
using namespace std;


//  Introduce the user to the game
void intro()
{
    cout << "***Welcome to the Cube***" << endl << endl;
    cout << "You have been randomly placed inside a 2-dimensional cube made of several other cubes with no recollection of how you got there. \nYou have an empty backpack with only 10 spaces. A key is needed to open the door in some select cubes that will lead to your exit and success. \nYou must find your way out before the time runs out. But be careful!. Some of the cubes may have traps! Good luck!" << endl << endl;
    
}


//  Give instructions to the user
void description()
{
    cout  << "You notice that each cube you enter is labeled with a number inside and on the door that leads to it. \n There also appears to be a timer in each room that decreases by 1 each time you enter a new room. \nEach cube has 4 doorways: one straight ahead, one behind you, one to the left, and one to the right. \nThere is a pattern that leads to the exit but it is up to you to find it." << endl << endl;
    cout << "Press enter to continue...";
    cin.ignore();
}


int main() {
    
    do{
    intro();
    description();
    runGame();
    }while(playAgain() == true);
    
    cout << endl << "Thanks for playing." << endl;
    return 0;
}
