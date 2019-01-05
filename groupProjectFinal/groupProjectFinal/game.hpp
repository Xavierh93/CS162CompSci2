/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: This is the header for the Game class.
 *****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"

class Game
{
private:
    int time;
    int steps;
    Board* gameBoard;
public:
    Game(int steps);
    Game(int w, int h, int d, int a, int s);
    void runMoreSteps(int steps);
    void runGame();
    void runStep();
    ~Game();
};


#endif
