//
//  main.cpp
//  project1
//
//  Created by Xavier on 1/12/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "menu.hpp"
#include "ant.hpp"
using namespace std;

void movement(Ant &, int*, int*, char *[], int, int);
void clearScreen();

int main() {
    
    //Create Variables
    int choice, rows, columns, steps, startRow, startColumn;
    bool runAgain = 0;
    
    
    // Create the menu
    choice = startMenu();
    
    // If user wants to exit program
    if (choice == 2)
        exit(0);
    // Else start the game
    else {
        do {
            
            rows = 0; columns = 0; steps = 0; startRow = 0; startColumn = 0;
            
            getValues(&rows, &columns, &steps, &startRow, &startColumn);
            
            //Properly allign variables for correct border placement and board placement
            rows += 2;
            columns += 2;
            startRow += 1;
            startColumn += 1;
            
            //Create Ant class object
            Ant ant(startRow, startColumn);
            
            //Create a 2D array board
            char** board = new char*[rows];
            for (int i = 0; i < rows; i++)
                board[i] = new char[columns];
            
            
            //Fill the board with blank spaces and create the border
            for(int i = 0; i < rows; i++) {
                for(int n = 0; n < columns; n++) {
                    if (i == 0 || i == (rows - 1)) {
                        board[i][n] = '-';
                    }
                    else if (((n == 0) || n == (columns - 1)) && ((i != 0) || i != (rows))) {
                        board[i][n] = '|';
                    }
                    else board[i][n] = ' ';
                }
            }
            
           
            //Create the ant
            board[startRow][startColumn] = '*';
            cin.clear();
            cin.ignore();
            //Print the board to the screen
            for(int i =0; i < rows; i++) {
                for(int n = 0; n < (columns + 1); n++) {
                    cout << board[i][n];
                }
                cout << endl;
            }
            cin.clear();
            
            //Print the ant to the screen
            cout << board[startRow][startColumn];
            cin.clear();
            usleep(650000);
            clearScreen();
            
            //Loop based on number of steps
            for (int i = steps; i > 0; i--) {
                
                movement(ant, &startRow, &startColumn, board, rows, columns);
                usleep(650000);
                clearScreen();
            }
            //  Deletes the dynamically allocated 2D array.
            delete [] board;
            board = nullptr;
            
        } while (playAgain(runAgain)); // Continues to run indefinitely until user quits program.
    }

   
        
    
    return 0;
}


//************************************************************************************************
//  This function records the movement of the ant and updates the board accordingly.
//
//
//************************************************************************************************

void movement(Ant &theAnt, int *startRow, int *startColumn, char *board[], int rows, int columns)
{
    // If the next space is blank it adjusts accordingly and works the same way for each else if statement in given if statement. Repeats
    //  accordingly for the black color space
    if (theAnt.getCurrentColor() == ' ') {
        board[theAnt.getPrevRow()][theAnt.getPrevCol()] = '#';
        
        //  Changes proper direction for each movement and adjust the rows and columns accordingly. Repeats statements accordingly for each directioon
        if(theAnt.getDirection() == north)  {
            theAnt.setDirection(east);
            *startColumn = theAnt.getCurrentCol();
            *startColumn += 1;
            //  If statement to make sure ant isn't going out of the borders and if it does it moves the ant to the other side of the board. Repeats accordingly for each if and else if statement for based on currentColor and getDirection.
            if (*startColumn == columns - 1)
                *startColumn = 1;
        }
        
        else if(theAnt.getDirection() == east)  {
            theAnt.setDirection(south);
            *startRow = theAnt.getCurrentRow();
            *startRow += 1;
            if(*startRow == rows - 1)
                *startRow = 1;
        }
        
        else if(theAnt.getDirection() == south)  {
            theAnt.setDirection(west);
            *startColumn = theAnt.getCurrentCol();
            *startColumn -= 1;
            if (*startColumn == 0)
                *startColumn = columns - 2;
        }
        
        else if(theAnt.getDirection() == west)  {
            theAnt.setDirection(north);
            *startRow = theAnt.getCurrentRow();
            *startRow -= 1;
            if(*startRow == 0)
                *startRow = rows - 2;
        }
    }
    
    else if(theAnt.getCurrentColor() == '#')   {
        board[*startRow][*startColumn] = ' ';
        
        if(theAnt.getDirection() == north)  {
            theAnt.setDirection(west);
            *startColumn = theAnt.getCurrentCol();
            *startColumn -= 1;
            if(*startColumn == 0)
                *startColumn = columns - 2;
        }
        
        else if(theAnt.getDirection() == east) {
            theAnt.setDirection(north);
            *startRow = theAnt.getCurrentRow();
            *startRow -= 1;
            if(*startRow == 0)
                *startRow = rows - 2;
        }
        
        else if(theAnt.getDirection() == south)  {
                theAnt.setDirection(east);
                *startColumn = theAnt.getCurrentCol();
                *startColumn += 1;
                if(*startColumn == columns - 1)
                    *startColumn = 1;
        }
        
        else if(theAnt.getDirection() == west) {
                theAnt.setDirection(south);
                *startRow = theAnt.getCurrentRow();
                *startRow += 1;
                if(*startRow == rows - 1)
                    *startRow = 1;
        }
    }
    //  Sets current location
    theAnt.setCurrentCol(*startColumn);
    theAnt.setCurrentRow(*startRow);
    
    //  Stores CurrentColor in object variable
    if (board[theAnt.getCurrentRow()][theAnt.getCurrentCol()] == ' ')   {
        theAnt.setCurrentColor(' ');
    }else    {
        theAnt.setCurrentColor('#');
    }
    //  Updates ant on board based on startRow and startColumn
    board[theAnt.getCurrentRow()][theAnt.getCurrentCol()] = '*';
    
    //Prints out updated board
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            cout << board[i][j];
            }
        cout << endl;
    }
    
    //This section sets the previous location of the ant to the current location
    theAnt.setPrevRow(*startRow);
    theAnt.setPrevCol(*startColumn);
}

//************************************************************************************************
//    This function clears the screen to show the progress of the ant. Only works so well
//    because it's just new lines so it depends on how big the window size is to being
//    with
//************************************************************************************************

void clearScreen()  {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
