//  This file contains 3 functions for the menu:
//  1. The start menu
//  2. The menu that prompts the user for all the information to run the simulation
//  3. The menu to play again or quit (similar to the first one)
//  Created by Xavier on 1/15/18.
//  Copyright © 2018 Xavier. All rights reserved.
//
#include "menu.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//************************************************************************************************
//  This function displays the start menu and gives the user the option to start the program
//  or quit the program.
//
//************************************************************************************************

int startMenu() {
    int choice;
   
    cout << "*Extra Credit: Ask user if they would like to use a random starting location for the ant*" << endl << endl;
    cout << "Please select an option below: " << endl;
    cout << "1. Play Langton's Ant" << endl;
    cout << "2. Quit " << endl;
    cin >> choice;
    while ((choice != 1 && choice != 2)) {
        cin.clear();
        cin.ignore();
        cout << "Selection incorrect. Please enter 1 or 2." << endl;
        cin >> choice;
    }
    return choice;
}
   
//************************************************************************************************
//  This function displays the menu to retrieve all the variables from the menu and then passes them
//  back to the main function via reference. Also provides input validation and gives the user option
//  to generate a random starting location for the ant
//************************************************************************************************


void getValues(int *rows, int *columns, int *steps, int *startRow, int *startColumn) {
    int choice = 0;
    unsigned seed;
    seed = time(0);
    srand(seed);
    const int MINRANGE = 14;
    const int MAXRANGE = 34;
    
    //Until user decides to start the program loop the menu
    while (choice != 7) {
        
    cout << endl << "***All variables except for the starting location of the ant must be filled with an integer in order to run the program properly and the starting row and starting column must be less than the number for rows or columns respectively.***" << endl << endl<< "Please enter the variable you would like to input: " << endl;
    cout << "1. Number of rows for the board: " << *rows << endl;
    cout << "2. Number of columns for the board: " << *columns << endl;
    cout << "3. Number of steps during simulation: " << *steps << endl;
    cout << "4. Starting row of the ant: " << *startRow << endl;
    cout << "5. Starting column of the ant: " << *startColumn << endl;
    cout << "6. Generate random starting location for ant. (Note: rows and columns will be automatically generated if not already provided)" << endl;
    cout << "7. Start Langton's Ant" << endl;
    cout << "Enter 1-7 for choice: ";
    
    cin >> choice;
    
    //Input validation for the menu choices
    while (choice < 1 || choice > 7){
        cin.clear();
        cin.ignore();
        cout << "Choice must be between 1 and 7. Please re-enter your choice: " << endl;
        cin >> choice;
    }
        //Switch statement to get user input for selected variable with each case having input validation to make sure program runs properly
        switch(choice) {
            case 1: cout << "Enter the number of rows for the board: ";
                cin >> *rows;
                while (*rows < 1)
                {
                    cin.clear();    // Prevents character input from breaking the program
                    cin.ignore();
                    cout << "You must enter an integer greater than 0. Please try again:";
                    cin >> *rows;
                }
                break;
            case 2: cout << "Enter the number of columns for the board: ";
                cin >> *columns;
                while (*columns < 1)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer greater than 0. Please try again:";
                    cin >> *columns;
                }
                break;
            case 3: cout << "Enter the number of steps during the simulation: ";
                cin >> *steps;
                while (*steps < 1)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer greater than 0. Please try again:";
                    cin >> *steps;
                }
                while (*steps > 200)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer less than 200. Please try again: ";
                    cin >> *steps;
                }
                break;
            case 4: cout << "Enter the starting row of the ant: ";
                cin >> *startRow;
                while (*startRow < 0)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer equal to or greater than 0. Please try again:";
                    cin >> *startRow;
                }
                break;
            case 5: cout << "Enter the starting column of the ant: ";
                cin >> *startColumn;
                while (*startColumn < 0)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer equal to or greater than 0. Please try again: ";
                    cin >> *startColumn;
                }
                break;
            //  Case to generate random starting location of ant
            case 6: if (*rows == 0 && *columns == 0){
                *rows = (rand() % (MAXRANGE - MINRANGE + 1) + MINRANGE);
                *columns = (rand() % (MAXRANGE - MINRANGE + 1) + MINRANGE);
                *startRow = (rand() % *rows);
                *startColumn = (rand() % *columns);
                break;
                }else if(*rows == 0 && *columns > 0) {
                *rows = (rand() % (MAXRANGE - MINRANGE + 1) + MINRANGE);
                *startRow = (rand() % *rows);
                *startColumn = (rand() % *columns);
                }else if (*rows > 0 && *columns == 0) {
                *columns = (rand() % (MAXRANGE - MINRANGE + 1) + MINRANGE);
                *startRow = (rand() % *rows);
                *startColumn = (rand() % *columns);
                }
                else {
                *startRow = (rand() % *rows);
                *startColumn = (rand() % *columns);
                break;
                }
            case 7: if (*rows != 0 && *columns != 0 && *steps != 0 && *startRow < *rows && *startColumn < *columns)
                        break;
                else {
                    cout << "\nERROR: Rows, Columns, and Steps must bet set to an integer value greater than 0 to begin program and the starting column and starting row cannot be greater than the number of rows and columns." << endl;
                    choice = 1;
                    break;
                }
}
    }
}


//************************************************************************************************
//  This function displays the start menu again
//
//
//************************************************************************************************

bool playAgain(bool again) {
    int choice;
    

    cout << "\nPlease select an option below: " << endl;
    cout << "1. Play Langton's Ant Again" << endl;
    cout << "2. Quit " << endl;
    cin >> choice;
    while (choice != 1 && choice != 2) {
        cin.clear();
        cin.ignore();
        cout << "Selection incorrect. Please enter 1 or 2." << endl;
        cin >> choice;
    }
    if (choice == 1)
        return again = 1;
    else
        return again = 0;
        
}

