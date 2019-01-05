//  This is the header file for the functions file.
//  Created by Xavier on 2/16/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include "queue.hpp"
using namespace std;

void titleDisplay();
void playMenu();
void retrieveNumbers();
void retrieveTeams(int, int);
void createTeam1(int [], int, Queue *);
void createTeam2(int [], int, Queue *);
void fightMain(Queue *, Queue *, Queue *);
void showWinners(Queue *, int);
void showLosers(Queue *);
void playAgain();


#endif /* functions_hpp */
