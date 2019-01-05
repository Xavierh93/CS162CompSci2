//  This is the header file for the functions that help run the program.
//  Created by Xavier Elon Hollingsworth on 3/15/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include "space.hpp"
#include "inventory.hpp"
#include "user.hpp"
#include <stdio.h>

int startLocation();
int getDirection(Space *l);
void setDirections(Space *l, int *currentLocation, int *up, int *, int *, int *);
void printBoard();
void cubeRun(Space *l2, Inventory *b2, User *u);
void runGame();
bool playAgain();



#endif /* functions_hpp */
