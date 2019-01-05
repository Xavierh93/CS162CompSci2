/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: The Game class controls the overall order of gameplay.
 ** It tracks what to do during each step.
 *****************************************************************************/

#include "game.hpp"

#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

//Constructor runs default game values for number of steps
Game::Game(int steps)
{
    gameBoard = new Board(20, 20);
    time = 0;
    this->steps = steps;
    gameBoard->populate(100, 5);
}

//Constructor creates a custom game with custom values
Game::Game(int boardWidth, int boardHeight, int numDbugs, int numAnts, int steps)
{
    gameBoard = new Board(boardWidth, boardHeight);
    time = 0;
    this->steps = steps;
    gameBoard->populate(numAnts, numDbugs);
}

//Runs the game for the set number of steps
void Game::runGame(){
    cout << endl << "Step " << time << ": " << endl;
    gameBoard->printBoard();
    for (int i = 0; i < steps; i++){
        runStep();
        usleep(800000);
    }
}

//Runs each individual step
void Game::runStep()
{
    //Increment time
    time++;

    //Clear any 'moved' flags from critters
    gameBoard->clearMarks();

    //Doodlebugs move first
    for (int y = 1; y <= gameBoard->getHeight(); y++){
        for (int x = 1; x <= gameBoard->getWidth(); x++){
            //If a doodlebug exists on a square, move it and mark it as moved
            if (gameBoard->getCritter(x, y)->getPrint() == 'X' && gameBoard->getCritter(x, y)->getMoved() == false){
                gameBoard->markCritter(x, y);
                gameBoard->moveCritter(x, y, gameBoard);
            }
        }
    }

    //Ants move second
    for (int y = 1; y <= gameBoard->getHeight(); y++){
        for (int x = 1; x <= gameBoard->getWidth(); x++){
            //If an ant exists on a square, move it and mark it as moved
            if (gameBoard->getCritter(x, y)->getPrint() == 'O' && gameBoard->getCritter(x, y)->getMoved() == false){
                gameBoard->markCritter(x, y);
                gameBoard->moveCritter(x, y, gameBoard);
            }
        }
    }

    //Displays the step results
    cout << endl << "Step " << time << ": " << endl;
    gameBoard->printBoard();
}

//Runs additional steps
void Game::runMoreSteps(int s){
    for (int i = 0; i < s; i++){
        runStep();
        usleep(800000);
    }
}

//Destroys memory for Board
Game::~Game(){
    delete gameBoard;
}
