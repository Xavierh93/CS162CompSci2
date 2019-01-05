//  This is the file the contains the functions to help run game.
//  Created by Xavier Elon Hollingsworth on 3/15/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#include "functions.hpp"
#include "user.hpp"
#include "space.hpp"
#include "inventory.hpp"
#include "exitSpace.hpp"
#include "normalSpace.hpp"
#include "trapSpace.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


//  Generates random number between 1 and 64 for the starting location of the user
int startLocation()
{
    int randomLoc = 1 + (rand() % (64 - 1 + 1));
    return randomLoc;
}


//  Gets the direction from the user that they want to move
int getDirection(Space *l)
{
    //  Create variables
    int choice;
    bool n = false, s = false, e = false, w = false;
    //  Initialize string variable to save lots of space and time
    string north = "The door to the North reads ";
    string south = "The door to the South reads ";
    string east = "The door to the East reads ";
    string west = "The door to the West reads ";
    string door = "What door would you like to enter? ";
    string incorrect = "Selection incorrect. Please try again: ";
    
    //  4 if loops check to see if any of the directions are at the edge of the cube
    if (l->getTop() == 0)
    {
        cout << "The North is at the edge of the cube and thus you cannot move this way." << endl;
        n = true;
    }
    if (l->getRight() == 0)
    {
        cout << "The East is at the edge of the cube and thus you cannot move this way." << endl;
        e = true;
    }
    if (l->getBottom() == 0)
    {
        cout << "The South is at the edge of the cube and thus you cannot move this way." << endl;
        s = true;
    }
    if (l->getLeft() == 0)
    {
        cout << "The West is at the edge of the cube and thus you cannot move this way." << endl;
        w = true;
    }
    
    
    //  If/elseif/else statement to provide correct menu output for user to select the direction they want to go
    if (n == true && e == true)
    {
        cout << "1: " << west << l->getLeft() << endl;
        cout << "2: " << south << l->getBottom() << endl;
        cout << door;
        cin.clear();
        cin >> choice;
        while (choice != 1 && choice !=2)
        {
            cin.clear();
            cin.ignore();
            cout << incorrect;
            cin >> choice;
        }
        if (choice == 1)
            return l->getLeft();
        else
            return l->getBottom();
    }
    else if (n == true && w == true)
    {
        cout << "1: " << east << l->getRight() << endl;
        cout << "2: " << south << l->getBottom() << endl;
        cout << door;
        cin.clear();
        cin >> choice;
        while (choice != 1 && choice !=2)
        {
            cin.clear();
            cin.ignore();
            cout << incorrect;
            cin >> choice;
        }
        if (choice == 1)
            return l->getRight();
        else
            return l->getBottom();
    }
    else if (s == true && w == true)
    {
        cout << "1: " << north << l->getTop() << endl;
        cout << "2: " << east << l->getRight() << endl;
        cout << door;
        cin.clear();
        cin >> choice;
        while (choice != 1 && choice !=2)
        {
            cin.clear();
            cin.ignore();
            cout << incorrect;
            cin >> choice;
        }
        if (choice == 1)
            return l->getTop();
        else
            return l->getRight();
    }
    else if (s == true && e == true)
    {
        cout << "1: " << north << l->getTop() << endl;
        cout << "2: " << west << l->getLeft() << endl;
        cout << door;
        cin.clear();
        cin >> choice;
        while (choice != 1 && choice !=2)
        {
            cin.clear();
            cin.ignore();
            cout << incorrect;
            cin >> choice;
        }
        if (choice == 1)
            return l->getTop();
        else
            return l->getLeft();
    }
    else if (n == true)
    {
        cout << "1: " << east << l->getRight() << endl << "2: " << south << l->getBottom() << endl << "3: " << west << l->getLeft() << endl;
        cout << door;
        cin.clear();
        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cin.clear();
            cin.ignore();
            cout << incorrect;
            cin >> choice;
        }
        if (choice == 1)
            return l->getRight();
        else if (choice == 2)
            return l->getBottom();
        else
            return l->getLeft();
    }
    else if (e == true)
    {
        cout << "1: " << north << l->getTop() << endl << "2: " << south << l->getBottom() << endl << "3: " << west << l->getLeft() << endl;
        cout << door;
        cin.clear();
        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cin.clear();
            cin.ignore();
            cout << incorrect;
            cin >> choice;
        }
        if (choice == 1)
            return l->getTop();
        else if (choice == 2)
            return l->getBottom();
        else
            return l->getLeft();
    }
    else if (s == true)
    {
        cout << "1: " << north << l->getTop() << endl << "2: " << east << l->getRight() << endl << "3: " << west << l->getLeft() << endl;
        cout << door;
        cin.clear();
        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cin.clear();
            cin.ignore();
            cout << incorrect;
            cin >> choice;
        }
        if (choice == 1)
            return l->getTop();
        else if (choice == 2)
            return l->getRight();
        else
            return l->getLeft();
    }
    else if (w == true)
    {
        cout << "1: " << north << l->getTop() << endl << "2: " << east << l->getRight() << endl << "3: " << south << l->getBottom() << endl;
        cout << door;
        cin.clear();
        cin >> choice;
        while (choice < 1 || choice > 3)
        {
            cin.clear();
            cin.ignore();
            cout << incorrect;
            cin >> choice;
        }
        if (choice == 1)
            return l->getTop();
        else if (choice == 2)
            return l->getRight();
        else
            return l->getBottom();
    }
    else
    {
        cout << "1: " << north << l->getTop() <<  endl << "2: " << east << l->getRight() << endl << "3: " << south << l->getBottom() << endl << "4: " << west << l->getLeft() << endl;
        cout << door;
        cin.clear();
        cin >> choice;
        while (choice < 1 || choice > 4)
        {
            cin.clear();
            cin.ignore();
            cout << incorrect;
            cin >> choice;
        }
        if (choice == 1)
            return l->getTop();
        else if (choice == 2)
            return l->getRight();
        else if (choice == 3)
            return l->getBottom();
        else
            return l->getLeft();
    }
}


//  Sets space pointers based on currentLocation which was previously choosen by the user in the getDirection function
void setDirections(Space *l, int *currentLocation, int *up, int *down, int *left, int *right)
{
    //  Sets up - 8 if it is not on the edge of the cube, otherwise up is set to 0
    if (*currentLocation > 8 && *currentLocation < 65)
    {
        *up = *currentLocation - 8;
    }
    else
    {
        *up = 0;
    }
    
    //  Sets down + 8 if it is not on the edge of the cube, otherwise it is set to 0
    if (*currentLocation > 0 && *currentLocation < 57)
    {
        *down = *currentLocation + 8;
    }
    else
    {
        *down = 0;
    }
    
    //  Sets left - 1 if it not on the edge of the cube, otherwise it is set to 0
    if (*currentLocation != 1 && *currentLocation != 9 && *currentLocation != 17 && *currentLocation != 25 && *currentLocation != 33 && *currentLocation != 41 && *currentLocation != 49 && *currentLocation != 57)
    {
        *left = *currentLocation - 1;
    }
    else
    {
        *left = 0;
    }
    
    //  Sets left - 1 if it not on the edge of the cube, otherwise it is set to 0
    if (*currentLocation != 8 && *currentLocation != 16 && *currentLocation != 24 && *currentLocation != 32 && *currentLocation != 40 && *currentLocation != 48 && *currentLocation != 56 && *currentLocation != 64)
    {
        *right = *currentLocation + 1;
    }
    else
    {
        *right = 0;
    }
    
    //  Sets the 5 pointers in the space object
    l->setSpace(*currentLocation);
    l->setTop(*up);
    l->setBottom(*down);
    l->setRight(*right);
    l->setLeft(*left);
}



//  Fills the board with the numbers for each cube. Prints the cube layout at the beginning of the game.
void printBoard()
{
    cout << endl << "You find a map of the cube etched into the floor of the cube you are in. It shows the following: ";
    int number = 1;
    int rows = 8;
    int columns = 8;
    int cube[8][8];
    
    //  Fill the cube with numbers
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cube[i][j] = number;
            number = number+1;
        }
    }
    
    //  Print the board to the screen
    cout << endl << "|-----------------------------------------------|" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "| ";
        
        for(int n = 0; n < columns; n++)
        {
            cout << setw(3) << cube[i][n] << " | ";
        }
        cout << endl << "|-----------------------------------------------|" << endl;
    }
    cin.clear();
}


//  Extremely long function. All actions entered by user in the game occur here.
void cubeRun(Space *l2, Inventory *b, User *u)
{
    //  Create variables
    int choice;
    char character;
    
    //  Checks if space has trap. If it does
    if (l2->getTrap() == true)
    {
        cout << "You have sprung a trap" << endl;
        if (b->hasTrapPotion() == true)
        {
            cout << "Would you like to use a trap potion for a chance to avoid the trap in the room? (Y/N)" << endl;
            cin.clear();
            cin.ignore();
            cin.get(character);
            while (character != 'Y' && character != 'y' && character != 'N' && character != 'n')
            {
                cin.clear();
                cin.ignore();
                cout << "Selection incorrrect. Please try again: ";
                cin.get(character);
            }
            if (character == 'y' || character == 'Y')
            {
                b->decItem(b->getTrapPotPos());
                b->removeItem(b->getTrapPotPos());
                b->decSize();
                
                int chance = 1 + (rand() % ((2+1)-1));
                if (chance == 1)
                    cout << "You used the trap potion and avoided the trap in the room!" << endl;
                else
                    cout << "You used the trap potion but it had no effect and you have lost 25 health!" << endl;
            }
            else
            {
                cout << "You decided not to use the trap potion and have lost 20 health!" << endl;
                u->reduceHealth();
            }
        }
        else
        {
            cout << "You do not currently have a trap potion and have taken 20 damage from the trap in the room." << endl;
            u->reduceHealth();
        }
    }
    else
        cout << "You cautiously enter the new cube but there does not appear to be a trap." << endl;
    
    
    //  Checks if user has died from a possible trap in the previous if statement
    if (u->getHealth() == 0)
    {
        cout << "You have run out of health and lost the game!";
        u->setLoseGame();
        return;
    }
    
    
    //  Checks if space has an item. Asks user if they would like to pick it up if so
    if (l2->getItem() == true)
    {
        //  Initialize itemNum with random number from 1-3 to represent the 3 different items in the game
        int itemNum = 1 + (rand() % ((3 + 1) - 1));
        
        //  Item is key needed to complete the game
        if (itemNum == 1)
        {
            cout << "There is a key in the room." << endl;
            if (b->isFull() == false)
            {
                cout << "Would you like to pick up the key? (Y/N)" << endl;
                cin.clear();
                cin.ignore();
                cin.get(character);
                while (character != 'Y' && character != 'y' && character != 'N' && character != 'n')
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Selection incorrect. Please try again: ";
                    cin.get(character);
                }
                if (character == 'y' || character == 'Y')
                {
                    cout << "You have picked up the key!" << endl;
                    b->addItem(1);
                    b->incSize();
                    
                }
                else
                    cout << "You did not pick up the key in the room! I hope you do not regret this decision!" << endl;
            }
            else if (b->isFull() == true)
            {
                cout << "Unfortunately your backpack is full! Would you like to remove an item to make room for the key? (Y/N)";
                cin.clear();
                cin.ignore();
                cin.get(character);
                while (character != 'Y' && character != 'y' && character != 'N' && character != 'n')
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Selection incorrect. Please try again: ";
                    cin.get(character);
                }
                if (character == 'Y' || character == 'y')
                {
                    b->displayBackpack();
                    cout << "Select an item to remove from your backpack: ";
                    cin.clear();
                    cin.ignore();
                    cin >> choice;
                    while (choice < 0 || choice > b->getSize())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Selection incorrect. Please try again: ";
                        cin >> choice;
                    }
                    b->decItem(choice);
                    b->removeItem(choice-1);
                    b->decSize();
                    cout << "You have picked up the key!" << endl;
                    b->addItem(1);
                    b->incSize();
                    
                }
                else
                    cout <<"You decided not to pick up the key! I hope you do not regret this!" << endl;
            }
        }
        //  Item is health potion
        else if (itemNum == 2)
        {
            cout << "There is a health potion in the room." << endl;
            if (b->isFull() == false)
            {
                cout << "Would you like to pick up the health potion? (Y/N)" << endl;
                cin.clear();
                cin.ignore();
                cin.get(character);
                while (character != 'Y' && character != 'y' && character != 'N' && character != 'n')
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Selection incorrect. Please try again: ";
                    cin.get(character);
                }
                if (character == 'Y' || character == 'y')
                {
                    cout << "You picked up the health potion!" << endl;
                    b->addItem(2);
                    b->incSize();
                    
                }
                else
                    cout << "You decided not to pick up the health potion." << endl;
            }
            else
            {
                cout << "Unfortunately your backpack is full! Would you like to remove an item to make room for the health potion? (Y/N)";
                cin.clear();
                cin.ignore();
                cin.get(character);
                while (character != 'Y' && character != 'y' && character != 'N' && character != 'n')
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Selection incorrect. Please try again: ";
                    cin.get(character);
                }
                if (character == 'Y' || character == 'y')
                {
                    b->displayBackpack();
                    cout << "Select an item to remove from your backpack: ";
                    cin.clear();
                    cin.ignore();
                    cin >> choice;
                    while (choice < 0 || choice > b->getSize())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Selection incorrect. Please try again: ";
                        cin >> choice;
                    }
                    b->decItem(choice);
                    b->removeItem(choice-1);
                    cout << "You picked up the health potion!" << endl;
                    b->addItem(2);
                    
                }
                else
                    cout <<"You decided not to pick up the health potion!" << endl;
            }
        }
        //  Item is trap potion
        else if (itemNum == 3)
        {
            cout << "There is a trap potion in the room." << endl;
            if (b->isFull() == false)
            {
                cout << "Would you like to pick up the trap potion? (Y/N)" << endl;
                cin.clear();
                cin.ignore();
                cin.get(character);
                while (character != 'Y' && character != 'y' && character != 'N' && character != 'n')
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Selection incorrect. Please try again: ";
                    cin.get(character);
                }
                if (character == 'Y' || character == 'y')
                {
                    cout << "You picked up the trap potion!" << endl;
                    b->addItem(3);
                    b->incSize();
                }
                else
                    cout << "You decided not to pick up the trap avoider potion." << endl;
            }
            else
            {
                cout << "Unfortunately your backpack is full! Would you like to remove an item to make room for the trap potion? (Y/N)";
                cin.clear();
                cin.ignore();
                cin.get(character);
                while (character != 'Y' && character != 'y' && character != 'N' && character != 'n')
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Selection incorrect. Please try again: ";
                    cin.get(character);
                }
                if (character == 'Y' || character == 'y')
                {
                    b->displayBackpack();
                    cout << "Select an item to remove from your backpack: ";
                    cin.clear();
                    cin.ignore();
                    cin >> choice;
                    while (choice < 0 || choice > b->getSize())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Selection incorrect. Please try again: ";
                        cin >> choice;
                    }
                    b->removeItem(choice-1);
                    cout << "You picked up the trap potion!" << endl;
                    b->addItem(3);
                }
                else
                    cout <<"You decided not to pick up the trap potion!" << endl;
            }
        }
    }
    if (l2->getItem() == false)
        cout << "There is no item in this room." << endl;
    
    //  Checks if there is a space in the room. If the user has a key they may use it to try and escape the cube
    if (l2->getExit() == true)
    {
       cout << "There appears to be an exit in this room!" << endl;
        if (b->hasKey() == true)
        {
            cout << "You currently have a key! Would you like to use it to escape the cube? (Y/N)" << endl;
            cin.clear();
            cin.ignore();
            cin.get(character);
            while (character != 'Y' && character != 'y' && character != 'N' && character != 'n')
            {
                cin.clear();
                cin.ignore();
                cout << "Selection incorrect. Please try again: ";
                cin.get(character);
            }
            if (character == 'Y' || character == 'y')
            {
                int chance = 1 + rand() % ((3 - 1) + 1);
                if (chance == 1 || chance == 2)
                {
                    cout << "You have used the key from your backpack to exit the cube!" << endl;
                    u->setWinGame();
                    return;
                }
                else
                {
                    cout << "You have used the key from your backpack but it has broken in the door! Keep searching!" << endl;
                    b->decItem(b->getKeyPos());
                    b->removeItem(b->getKeyPos());
                    b->decSize();
                }
            }
            else
                cout << "You decided not to use the key to escape! I hope you know what you are doing!" << endl;
        }
        else if (b->hasKey() == false)
            cout << "Unfortunately you currently do not have a key to open the exit to the cube. Keep looking!" << endl;
    }
    else
        cout << "This room does not appear to have an exit. Keep looking!" << endl;
    
    //  If users health is not full  and the user has a health potion they are asked if they want to use a health potion to heal.
    if (u->getHealth() < 100 && b->hasHealthPotion() == true)
    {
        cout << "Would you like to use a health potion before continuing? (Y/N): ";
        cin.clear();
        cin.ignore();
        cin.get(character);
        while (character != 'Y' && character != 'y' && character != 'N' && character != 'n')
        {
            cin.clear();
            cin.ignore();
            cout << "Selection invalid. Please enter Y for yes or N for no: ";
            cin.get(character);
        }
        if (character == 'Y' || character == 'y')
        {
            cout << "You have used a health potion and gained 10 health!" << endl;
            u->addHealth();
            b->decItem(b->getHealthPos());
            b->removeItem(b->getHealthPos());
            b->decSize();
        }
        else
            cout << "You decided not to use the health potion." << endl;
    }
}


//  This is the function that runs the game and creates the derived Space objects.
void runGame()
{
    //  Initiate variables + create random seed;
    srand(time(NULL) + rand());
    int currentLocation;
    int up, down, right, left;
    
    
    
    //  Create objects
    Inventory backpack;
    Space loc;
    User user;
    Inventory *b = &backpack;
    Space *l = &loc;
    User *u = &user;
    
    //Generates random start location
    currentLocation = startLocation();
    setDirections(l, &currentLocation, &up, &down, &right, &left);
    cout << endl << "The room you wake up in is labeled with the number " << currentLocation << " ." << endl;
    
    
    //  Loops unntil user dies or wins
    while (u->getSteps() != 0 && u->getHealth() != 0 && u->getLoseGame() == false && u->getWinGame() == false)
    {
        printBoard();
        cout << endl <<  "The number in the current cube you find yourself in reads " << l->getSpace() << "." << endl;
        b->displayBackpack();
        cout << endl;
        cout << endl << "Your current health is " << u->getHealth() << " and the steps remaining before the cube collapses in on itself is " << u->getSteps() << "." << endl;
        
        //  Gets direction user wants to go and then sets all direction pointers in the space object
        currentLocation = getDirection(l);
        cout << "You enter the door leading to the cube labeled " << currentLocation << "." << endl;
        setDirections(l, &currentLocation, &up, &down, &right, &left);
        
        
        //  If the current space contains a prime power number and is on the edge of the cube it is an ExitSpace object
        if (l->getSpace() == 2 || l->getSpace() == 3 || l->getSpace() == 4 || l->getSpace() == 5 || l->getSpace() == 7 || l->getSpace() == 8 || l->getSpace() == 16 || l->getSpace() == 32 || l->getSpace() == 64 || l->getSpace() == 61 || l->getSpace() == 59 || l->getSpace() == 49 || l->getSpace() == 41 || l->getSpace() == 25 || l->getSpace() == 17 || l->getSpace() == 9)
        {
            //  Create derived class pointer object
            Space *l2 = new ExitSpace();
            setDirections(l2, &currentLocation, &up, &down, &right, &left);
            cubeRun(l2, b, u);
        }
        
        //  If the current space contains a prime power number or prime number that is not one the edge of the cube then it is created as a NormalSpace object
        else if (l->getSpace() == 11 || l->getSpace() == 13 || l->getSpace() == 19 || l->getSpace() == 23 || l->getSpace() == 27 || l->getSpace() == 29 || l->getSpace() == 31 || l->getSpace() == 32 || l->getSpace() == 37 || l->getSpace() == 41 || l->getSpace() == 43 || l->getSpace() == 47 || l->getSpace() == 53)
        {
            Space *l2 = new NormalSpace();
            setDirections(l2, &currentLocation, &up, &down, &right, &left);
            cubeRun(l2, b, u);
        }
        
        //  If the current space contains a composite number then it is created as a TrapSpace object
        else
        {
            Space *l2 = new TrapSpace();
            setDirections(l2, &currentLocation, &up, &down, &right, &left);
            cubeRun(l2, b, u);
        }
        
        //  Checks if user has won the game
        if (u->getWinGame())
        {
            cout << "You have exited the cube and won the game! Congratulations!" << endl;
            return;
        }
        
        //  Reduces step
        u->setSteps();
        //  Checks if steps has run out resulting in user losing
        if (u->getSteps() == 0)
        {
            u->setLoseGame();
            cout << "You have ran out of time and the cube has collapsed in on itself resulting in your demise!" << endl;
        }
        //  Checks if user has lost the game
        if (u->getLoseGame())
        {
            return;
        }
    }
}


//  Function that asks user if they would like to play again. The game loops indefinitely until the user decides they want to quit.
bool playAgain()
{
    char choice;
    
    cout << endl << "Would you like to play again? (Y/N): ";
    cin.clear();
    cin.ignore();
    cin.get(choice);
    while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
    {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid. Please try again: " << endl;
        cin.get(choice);
    }
    if (choice == 'Y' || choice == 'y')
        return true;
    else
        return false;
}
