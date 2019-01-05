//  This is a simulated zoo tycoon game.
//  Created by Xavier on 2/4/18.
//  Copyright © 2018 Xavier. All rights reserved.

#include <iostream>
#include <string>
#include "Zoo.h"

using namespace std;

//  Gets user input for number of animals to start game with
int getInput(string animal, int cost)
{
    int choice = 0;
    
    cout << "Enter Number (1 or 2) of " << animal << " you would like to buy for $" << cost << " each: ";
    cin >> choice;
    while (!(choice >= 1 && choice <= 2))
    {
        cin.clear();
        cin.ignore();
        cout << "You must buy either 1 or 2 " << animal << " to start the game. Please try again: ";
        cin >> choice;
    }
    return choice;
}

void gameInstruction()
{
    int choice = 0;
    cin.clear();
    cin.ignore();
    cout << endl << "Do you want to continue the game?\n1. Yes\n2. No\n ";
    cin >> choice;
    while (!(choice >= 1 && choice <= 2))
    {
        cin.clear();
        cin.ignore();
        cout << " You must enter 1 to continue the game or 2 to quit. Please try agaom: ";
      
    }
    if (choice == 2)
        exit(0);
}

int isBuy()
{
    int choice = 2;
    while (!(choice >= 1 && choice <= 2))
    {
        cout << "Do you want to but an Adult Animal?\n 1.Yes 2.No" << endl;;
        cin >> choice;
    }
    return choice;
}

int typeAnimal()
{
    int choice = 0;
    while (!(choice >= 0 && choice <= 2))
    {
        cout << "0. Tigers\n1. Penguins\n2. Turtles\n? ";
        cin >> choice;
    }
    return choice;
}

void displayBalance(double bankBalance)
{
    cout << "Starting balance: " << bankBalance << endl;
}

int main()
{
    double bankBalance = 100000;
    int tigers, penguins, turtles;
    Zoo zoo;
    
    srand(time(NULL));
    displayBalance(bankBalance);
    tigers = getInput("Tigers", 10000);
    penguins = getInput("Penguins", 1000);
    turtles = getInput("Turtles", 100);
    
    bankBalance -= zoo.startZoo(tigers, penguins, turtles);
    cout << "Your bank Balance is: " << bankBalance << endl;
    while (bankBalance > 0)
    {
        
        gameInstruction();
        bankBalance -= zoo.foodCostADay();
        cout << "Your bank Balance is: " << bankBalance << endl;
        switch (rand()%3)
        {
            case 0:
                zoo.sickness();
                break;
            case 1:
                zoo.boom();
                break;
            case 2:
                zoo.bornbaby();
                break;
        }
        zoo.printProfit();
        cout << "Your bank Balance is: " << bankBalance << endl;
        if (isBuy() == 1)
        {
            bankBalance -= zoo.buyAnAdultAnimal(typeAnimal());
        }
    }
    return 0;
}
