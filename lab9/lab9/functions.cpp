//  This is the function file for all the functions for the menu and other various components of lab 9
//  Created by Xavier on 3/9/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include "functions.hpp"
#include "queue.hpp"
#include "palindrome.hpp"
#include <iostream>
using namespace std;


void titleDisplay()
{
    cout << "*** Welcome to the Linear Data Structures Program ***" << endl << endl;
}

void mainMenu()
{
    int choice;
    
    cout << "---Main Menu---: " << endl;
    cout << "1) Test the buffer." << endl;
    cout << "2) Create a palindrome." << endl;
    cout << "3) Exit program." << endl;
    cout << "Enter a choice: ";
    cin.clear();
    cin >> choice;
    
    if (choice != 1 && choice != 2 && choice != 3)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid. Please try again: ";
        cin >> choice;
    }
    else if (choice == 1)
    {
        queueContainer();
    }
    else if (choice == 2)
    {
        palindrome();
    }
    else if (choice == 3)
    {
        exit(0);
    }
    mainMenu();
}


int mainMenuRounds()
{
    int rounds;
    
    cout << "Please enter the number of rounds to be simulated: ";
    cin.clear();
    cin >> rounds;
    while (rounds <= 0 || rounds > 1000)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid. Please try again: ";
        cin >> rounds;
    }
    return rounds;
}



double mainMenuPush()
{
    double pushChance;
    
    cout << "Please enter the percentage chance to output a randomly generated number at the end of the buffer: ";
    cin.clear();
    cin >> pushChance;
    while (pushChance < 0 || pushChance > 100)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid. Please try again: ";
        cin >> pushChance;
    }
    return pushChance;
}


double mainMenuPop()
{
    double popChance;
    
    cout << "Please enter the percentage chance to take out a randomly generated number at the front of the buffer: ";
    cin.clear();
    cin >> popChance;
    while (popChance < 0 || popChance > 100)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid. Please try again: ";
        cin >> popChance;
    }
    return popChance;
}
