/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: This is the header for the main menu function.
 *****************************************************************************/

#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>
#include "game.hpp"

void menuStart(Game* gamePtr, int*, int*, int*, int*, int*);
bool continueGame(Game* gamePtr);

#endif
