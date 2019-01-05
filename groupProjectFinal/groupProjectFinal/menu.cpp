/******************************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description: This is the main menu function that creates the Game object
 ** (default or custom) and allows the user to play/quit.
 *****************************************************************************/

#include "menu.hpp"
#include "game.hpp"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

//Runs the main menu
void menuStart(Game* gamePtr, int *timeSteps, int *rows, int *columns, int *ants, int *doodlebugs)
{
    bool runAgain = true;
    int choice = 0;

    cout << endl;

    //Run menu until game starts
    while(choice != 7 && choice != 1 && choice != 8)   {
        cout << "Please enter an option below: " << endl;
        cout << "1: Start a new game with default variables initialized." << endl;
        cout << "2: Enter the number of time steps to run the game for: " << *timeSteps << endl;
        cout << "3: Enter the number of rows for the board: " << *rows << endl;
        cout << "4: Enter the number of columns for the board: " << *columns << endl;
        cout << "5: Enter the number of ants to start game with: " << *ants << endl;
        cout << "6: Enter the number of doodlebugs to begin game with: " << *doodlebugs << endl;
        cout << "7: Start the game." << endl;
        cout << "8: Quit the game." << endl;
        cin >> choice;
        cin.clear();
        cin.ignore();

        //Input validation
        while (choice < 1 || choice > 8)    {
            cout << "Selection not valid. Please try again." << endl;
            menuStart(gamePtr, timeSteps, rows, columns, ants, doodlebugs);
        }
        switch(choice)  {
            case 1:   //Starts a game using default values
                {
                *rows = 20; *columns = 20; *ants = 100; *doodlebugs = 5;
                cout << "Enter the number of time steps you would like the game to run for: ";
                cin >> *timeSteps;
                cin.clear();
                cin.ignore();
                while (*timeSteps < 1)
                {
                    cout << "You must enter an integer greater than 0. Please try again:";
                    cin >> *timeSteps;
                    cin.clear();
                    cin.ignore();
                }
                while (*timeSteps > 200)
                {
                    cout << "You must enter an integer less than 200. Please try again: ";
                    cin >> *timeSteps;
                    cin.clear();
                    cin.ignore();
                }
                Game gDefault(*timeSteps);
                gamePtr = &gDefault;
                gamePtr->runGame();
                cout << endl;
                while(continueGame(gamePtr));
                break;
                }
            case 2:   //Enter custom number of steps
                cout << "Enter the number of time steps you would like to run the game for: ";
                cin >> *timeSteps;
                cin.clear();
                cin.ignore();
                while (*timeSteps < 1)
                {
                    cout << "You must enter an integer greater than 0. Please try again:";
                    cin >> *timeSteps;
                    cin.clear();
                    cin.ignore();
                }
                while (*timeSteps > 200)
                {
                    cout << "You must enter an integer less than 200. Please try again: ";
                    cin >> *timeSteps;
                    cin.clear();
                    cin.ignore();
                }
                cout << endl;
                break;
            case 3:   //Enter custom number of rows (board height)
                cout << "Enter the number of rows for the board: ";
                cin >> *rows;
                cin.clear();
                cin.ignore();
                while (*rows < 2)
                {
                    cout << "You must enter an integer greater than 1. Please try again: ";
                    cin >> *rows;
                    cin.clear();
                    cin.ignore();
                }
                while ((*rows * *columns) < (*ants + *doodlebugs))
                {
                    cout << "The number of rows you entered is too small to fit the current amount of ants and doodlebugs. Please try again: ";
                    cin >> *rows;
                    cin.clear();
                    cin.ignore();
                }
                cout << endl;
                break;
            case 4:   //Enter custom number of columns (board width)
                cout << "Enter the number of columns for the board: ";
                cin >> *columns;
                cin.clear();
                cin.ignore();
                while (*columns < 2)
                {
                    cout << "You must enter an integer greater than 1. Please try again:";
                    cin >> *columns;
                    cin.clear();
                    cin.ignore();
                }
                while ((*rows * *columns) < (*ants + *doodlebugs))
                {
                    cout << "The number of columns you entered is too small to fit the current amount of ants and doodlebugs. Please try again: ";
                    cin >> *columns;
                    cin.clear();
                    cin.ignore();
                }
                cout << endl;
                break;
            case 5:   //Enter custom number of ants
                cout << "Enter the number of ants to begin game with: ";
                cin >> *ants;
                cin.clear();
                cin.ignore();
                while (*ants < 1)
                {
                    cout << "You must enter an integer greater than 0. Please try again:";
                    cin >> *ants;
                    cin.clear();
                    cin.ignore();
                }
                while (*ants > (*rows * *columns) - *doodlebugs)
                {
                    cout << "The number of ants you entered is too large to fit on the board. Please try again: ";
                    cin >> *ants;
                    cin.clear();
                    cin.ignore();
                }
                cout << endl;
                break;
            case 6:   //Enter custom number of doodlebugs
                cout << "Enter the number of doodlebugs to begin game with: ";
                cin >> *doodlebugs;
                cin.clear();
                cin.ignore();
                while (*doodlebugs < 1)
                {
                    cout << "You must enter an integer greater than 0. Please try again:";
                    cin >> *doodlebugs;
                    cin.clear();
                    cin.ignore();
                }
                while (*doodlebugs > (*rows * *columns) - *ants)
                {
                    cout << "The number of doodlebugs you entered is too large to fit on the board. Please try again: ";
                    cin >> *doodlebugs;
                    cin.clear();
                    cin.ignore();
                }
                cout << endl;
                break;
            case 7:   //Starts a game using the custom values
                {
                if (*timeSteps == 0)    {
                    cout << endl << "WARNING:You must enter an integer greater than 0 for the time steps to begin the game." << endl << endl;
                    choice = 0;
                    break;
                }
                else{
                    Game gCustom(*columns, *rows, *doodlebugs, *ants, *timeSteps);
                    gamePtr = &gCustom;
                    gamePtr->runGame();
                    while(continueGame(gamePtr));
                    break;
                }
                cout << endl;
                }

            case 8:
                exit(0);
        }
    }
}

//Runs the game again from the existing board
bool continueGame(Game* gamePtr)
{
    int choice = 0;
    int addSteps = 0;

    cin.clear();

    //Menu prompt
    cout << "***Please select an option below***" << endl;
    cout << "1: Run more steps." << endl;
    cout << "2: Quit game." << endl;
    cin >> choice;

    //Input validation
    while(choice != 1 && choice != 2)   {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid. Please enter 1 to continue or 2 to quit." << endl;
        cin >> choice;
        cin.clear();
        cin.ignore();
    }
    switch(choice)  {
        case 1:   //Runs more steps
            cout << "Enter the additional number of steps you would like to run the game for: ";
            cin >> addSteps;
            cin.clear();
            cin.ignore();
            while (addSteps < 1)
            {
                cout << "You must enter an integer greater than 0. Please try again:";
                cin >> addSteps;
                cin.clear();
                cin.ignore();
            }
            while (addSteps > 200)
            {
                cout << "You must enter an integer less than 200. Please try again: ";
                cin >> addSteps;
                cin.clear();
                cin.ignore();
            }
            gamePtr->runMoreSteps(addSteps);
            return true;
            break;
        case 2:   //Quits the game
            return false;
    }
}
