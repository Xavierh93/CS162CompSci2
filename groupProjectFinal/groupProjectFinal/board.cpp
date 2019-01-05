/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: The Board class not only is responsible for creating and
 ** displaying the game board, but also functions for manipulating the
 ** Critters that exist on the board during the game.
 *****************************************************************************/

#include "board.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"

#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//Default constructor set to minimum of 20 (plus edges)
Board::Board(){
    width = 22;
    height = 22;

    //Creates dynamic array
    board = new Critter**[width];

    //Creates 2D array
    for (int i = 0; i < width; i++){
        board[i] = new Critter*[height];
    }

    //Sets up a blank board with edges
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            if (y == 0 || y == (height-1)){
                board[x][y] = new Critter(x, y, 0, '-');
            }
            else if (x == 0){
                board[x][y] = new Critter(x, y, 0, '|');
            }
            else{
                if (x == (width-1)){
                    board[x][y] = new Critter(x, y, 0, '|');
                }
                else{
                    board[x][y] = new Critter(x, y, 0, ' ');
                }
            }
        }
    }
}

//Constructor that takes width and height parameters
//Height and width are increased by 2 to account for edges
Board::Board(int w, int h){
    width = (w + 2);
    height = (h + 2);

    //Creates dynamic array
    board = new Critter**[width];

    //Creates 2D array
    for (int i = 0; i < width; i++){
        board[i] = new Critter*[height];
    }

    //Sets up a blank board with edges
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            if (y == 0 || y == (height-1)){
                board[x][y] = new Critter(x, y, 0, '-');
            }
            else if (x == 0){
                board[x][y] = new Critter(x, y, 0, '|');
            }
            else{
                if (x == (width-1)){
                    board[x][y] = new Critter(x, y, 0, '|');
                }
                else{
                    board[x][y] = new Critter(x, y, 0, ' ');
                }
            }
        }
    }
}

//Prints all of the board array's contents
void Board::printBoard(){
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            cout << board[x][y]->getPrint();
            if (x == (width -1))
                cout << endl;
        }
    }
}

//Returns what Critter is at a square
Critter* Board::getCritter(int x, int y){
    return board[x][y];
}

//Swaps critters
void Board::swapCritters(int x1, int y1, int x2, int y2){
    Critter* temp = board[x1][y1];
    board[x1][y1] = board[x2][y2];
    board[x2][y2] = temp;
}

//Removes a critter from the board
void Board::removeCritter(int x, int y){
    delete board[x][y];
    board[x][y] = new Critter(x, y, 0, ' ');
}

//Adds a new critter of type ant (a) or
//doodlebug (d) to an x,y location
void Board::addCritter(int x, int y, char type){
    delete board[x][y];
    if (type == 'a' || type == 'A')
        board[x][y] = new Ant(x, y, 0);
    else if (type == 'd' || type == 'D')
        board[x][y] = new Doodlebug(x, y, 0);
}

//Triggers a critter to move
void Board::moveCritter(int x, int y, Board* b){
    board[x][y]->move(b);
}

//Marks that a critter has moved during this step
void Board::markCritter(int x, int y){
    board[x][y]->setMoved(1);
}

//Clears all moved marks from Critters
void Board::clearMarks(){
    for (int y = 1; y <= getHeight(); y++){
        for (int x = 1; x <= getWidth(); x++){
            board[x][y]->setMoved(0);
        }
    }
}

//Returns the board's height (minus edges)
int Board::getHeight(){
    return (height - 2);
}

//Returns the board's width (minus edges)
int Board::getWidth(){
    return (width - 2);
}

//Returns a square's status (ant, dbug, empty, edge)
char Board::getStatus(int x, int y){
    return board[x][y]->getPrint();
}

//Sets a square's status (ant, dbug, empty, edge)
void Board::setStatus(int x, int y, char c){
    board[x][y]->setPrint(c);
}

//Chooses random placement for ants and doodlebugs
void Board::populate(int numAnts, int numDbugs){
    int rand_x;
    int rand_y;
    bool placed = false;

    //For the number of ants, place them randomly
    for (int i = 0; i < numAnts; i++){
        placed = false;

        //Until an empty spot is found, keep picking random X/Y
        while(!placed){
            rand_x = (rand() % getWidth()) + 1;
            rand_y = (rand() % getHeight()) + 1;

            //If the random spot is empty, delete the existing Critter
            //and replace with a new Ant
            if (board[rand_x][rand_y]->getPrint() == ' '){
                delete board[rand_x][rand_y];
                board[rand_x][rand_y] = new Ant(rand_x, rand_y, 0);
                placed = true;
            }
            else {
                rand_x = (rand() % getWidth()) + 1;
                rand_y = (rand() % getHeight()) + 1;
            }
        }
    }

    //For the number of doodlebugs, place them randomly
    for (int i = 0; i < numDbugs; i++){
        placed = false;

        //Until an empty spot is found, keep picking random X/Y
        while(!placed){
            rand_x = (rand() % getWidth()) + 1;
            rand_y = (rand() % getHeight()) + 1;

            //If the random spot is empty, delete the existing Critter
            //and replace with a new Ant
            if (board[rand_x][rand_y]->getPrint() == ' '){
                delete board[rand_x][rand_y];
                board[rand_x][rand_y] = new Doodlebug(rand_x, rand_y, 0);
                placed = true;
            }
            else {
                rand_x = (rand() % getWidth()) + 1;
                rand_y = (rand() % getHeight()) + 1;
            }
        }
    }
}

//Clears allocated memory for board
Board::~Board(){
    for (int i = 0; i < width; i++){
        delete[] board[i];
        board[i] = NULL;
    }

    delete[] board;
    board = NULL;
}

