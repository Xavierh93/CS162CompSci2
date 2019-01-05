//  This is the file that contains various functions like the menu, rolling the die, and 
//  Created by Xavier on 2/16/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cmath>
#include <unistd.h>
#include "functions.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"
using namespace std;


void titleDisplay()
{
    cout << "*** Welcome to the Fantasy Combat Game *** " << endl;
}


//  Function that runs a test fight and only lasts one round
void fightTest(Character *player1, Character *player2)
{
    cout << endl << "*******************************************" << endl;
    cout << player1 -> getType() << " Versus " << player2 -> getType();
    cout << endl << "*******************************************" << endl << endl;
    
    player1 -> attack(player2);
    player2 -> attack(player1);
    
    usleep(750000);
    cout << endl << player1 -> getType() << " remaining strength: " << player1 -> getStrength();
    usleep(750000);
    cout << endl << player2 -> getType() << " remaining strength: " << player2 -> getStrength();
    
    delete player1;
    delete player2;
}

//Function to return first character entered by user.
int getCharacter1()
{
    int character1 = 0;
    
    cout << endl;
    cout << "Which character will Player 1 be using?" << endl;
    cout << "1: Vampire" << endl;
    cout << "2: Barbarian" << endl;
    cout << "3: Blue Men" << endl;
    cout << "4: Medusa" << endl;
    cout << "5: Harry Potter" << endl;
    cout << "Enter a choice: ";
    cin >> character1;
    
    while(character1 < 0 || character1 > 5)
    {
        cout << "Selection incorrect. Please enter an integer between 1 and 5: ";
        cin.clear();
        cin.ignore();
        cin >> character1;
    }
    return character1;
}

//  Function to return second character entered by user.
int getCharacter2()
{
    int character2 = 0;
    
    cout << endl;
    cout << "Which character will Player 2 be using?" << endl;
    cout << "1: Vampire" << endl;
    cout << "2: Barbarian" << endl;
    cout << "3: Blue Men" << endl;
    cout << "4: Medusa" << endl;
    cout << "5: Harry Potter" << endl;
    cout << "Enter a choice: ";
    cin >> character2;
    
    while(character2 < 0 || character2 > 5)
    {
        cout << "Selection incorrect. Please enter an integer between 1 and 5: ";
        cin.clear();
        cin.ignore();
        cin >> character2;
    }
    return character2;
}

/*******************************************************************************************
 ** Function: testMenu
 ** Description: This function displays the test menu and displays the results of the characters fighting
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Returns result of random die roll
 *******************************************************************************************/
void testMenu()
{
    int choice = 0;
    
    cout << endl << endl << "*** Welcome to the testing center ***" << endl;
    cout << "Please select an option below: " << endl;
    cout << "1: Vampire vs Vampire" << endl;
    usleep(100000);
    cout << "2: Vampire vs Barbarian" << endl;
    usleep(100000);
    cout << "3: Vampire vs Blue Men" << endl;
    usleep(100000);
    cout << "4: Vampire vs Medusa" << endl;
    usleep(100000);
    cout << "5: Vampire vs Harry Potter" << endl;
    usleep(100000);
    cout << "6: Barbarian vs Barbarian" << endl;
    usleep(100000);
    cout << "7: Barbarian vs Blue Men" << endl;
    usleep(100000);
    cout << "8: Barbarian vs Medusa" << endl;
    usleep(100000);
    cout << "9: Barbarian vs Harry Potter" << endl;
    usleep(100000);
    cout << "10: Blue Men vs Blue Men" << endl;
    usleep(100000);
    cout << "11: Blue Men vs Medusa" << endl;
    usleep(100000);
    cout << "12: Blue Men vs Harry Potter" << endl;
    usleep(100000);
    cout << "13: Medusa vs Medusa" << endl;
    usleep(100000);
    cout << "14: Medusa vs Harry Potter" << endl;
    usleep(100000);
    cout << "15: Harry Potter vs Harry Potter" << endl;
    usleep(100000);
    cout << "16: Return to Main Menu" << endl;
    usleep(100000);
    cout << "Enter a choice: ";
    
    cin.clear();
    cin.ignore();
    cin >> choice;
    
    //  Input validation
    while (choice < 1 || choice > 16)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection incorrect. Please select an integer between 1 and 16: ";
        cin >> choice;
    }
   
    if (choice == 1)
    {
        fightTest(new Vampire, new Vampire);
        testMenu();
    }
    else if (choice == 2)
    {
        fightTest(new Vampire, new Barbarian);
        testMenu();
    }
    else if (choice == 3)
    {
        fightTest(new Vampire, new BlueMen);
        testMenu();
    }
    else if (choice == 4)
    {
        fightTest(new Vampire, new Medusa);
        testMenu();
    }
    else if (choice == 5)
    {
        fightTest(new Vampire, new HarryPotter);
        testMenu();
    }
    else if (choice == 6)
    {
        fightTest(new Barbarian, new Barbarian);
        testMenu();
    }
    else if (choice == 7)
    {
        fightTest(new Barbarian, new BlueMen);
        testMenu();
    }
    else if (choice == 8)
    {
        fightTest(new Barbarian, new Medusa);
        testMenu();
    }
    else if (choice == 9)
    {
        fightTest(new Barbarian, new HarryPotter);
        testMenu();
    }
    else if (choice == 10)
    {
        fightTest(new BlueMen, new BlueMen);
        testMenu();
    }
    else if (choice == 11)
    {
        fightTest(new BlueMen, new Medusa);
        testMenu();
    }
    else if (choice == 12)
    {
        fightTest(new BlueMen, new HarryPotter);
        testMenu();
    }
    else if (choice == 13)
    {
        fightTest(new Medusa, new Medusa);
        testMenu();
    }
    else if (choice == 14)
    {
        fightTest(new Medusa, new HarryPotter);
        testMenu();
    }
    else if (choice == 15)
    {
        fightTest(new HarryPotter, new HarryPotter);
        testMenu();
    }
    else if (choice == 16)
    {
        showMenu();
    }
}


void fightMain(Character *player1, Character *player2)
{
    bool gameOver = false;
    
    cout << endl << "*******************************************" << endl;
    cout << player1 -> getType() << " Versus " << player2 -> getType()
    << endl;
    cout << endl << "*******************************************" << endl << endl;
    cout << player1 -> getType() << " starting strength: " << player1 -> getStrength() << endl;
    cout << player2 -> getType() << " starting strength: " << player2 -> getStrength() << endl;
    usleep(1000000);
    while (!gameOver)
    {
        player1 -> attack(player2);
        player2 -> attack(player1);
        
        usleep(400000);
        cout << endl << player1 -> getType() << " remaining strength: " << player1 -> getStrength();
        usleep(400000);
        cout << endl << player2 -> getType() << " remaining strength: " << player2 -> getStrength();
        usleep(400000);
        cout << endl;
        
        if (player1 -> isDead())
        {
            cout << endl << player1 -> getType() << " is dead! Game Over!" << endl;
            gameOver = true;
            usleep(1000000);
        }
        if (player2 -> isDead())
        {
            cout << endl << player2 -> getType() << " is dead! Game Over!" << endl;
            gameOver = true;
            usleep(1000000);
        }
    }
    cout << endl << endl << endl;
    delete player1;
    delete player2;
}

/*******************************************************************************************
 ** Function: runGame
 ** Description: This function runs the game.
 ** Parameters: Character1, and character2
 ** Pre-Conditions: None
 ** Post-Conditions: Displays results of game
 *******************************************************************************************/

void runGame(int character1, int character2)
{
    if (character1 == 1 && character2 == 1)
    {
        fightMain(new Vampire, new Vampire);
    }
    else if (character1 == 1 && character2 == 2)
    {
        fightMain(new Vampire, new Barbarian);
    }
    else if (character1 == 1 && character2 == 3)
    {
        fightMain(new Vampire, new BlueMen);
    }
    else if (character1 == 1 && character2 == 4)
    {
        fightMain(new Vampire, new Barbarian);
    }
    else if (character1 == 1 && character2 == 5)
    {
        fightMain(new Vampire, new HarryPotter);
    }
    else if (character1 == 2 && character2 == 1)
    {
        fightMain(new Barbarian, new Vampire);
    }
    else if (character1 == 2 && character2 == 2)
    {
        fightMain(new Barbarian, new Barbarian);
    }
    else if (character1 == 2 && character2 == 3)
    {
        fightMain(new Barbarian, new BlueMen);
    }
    else if (character1 == 2 && character2 == 4)
    {
        fightMain(new Barbarian, new Medusa);
    }
    else if (character1 == 2 && character2 == 5)
    {
        fightMain(new Barbarian, new HarryPotter);
    }
    else if (character1 == 3 && character2 == 1)
    {
        fightMain(new BlueMen, new Vampire);
    }
    else if (character1 == 3 && character2 == 2)
    {
        fightMain(new BlueMen, new Barbarian);
    }
    else if (character1 == 3 && character2 == 3)
    {
        fightMain(new BlueMen, new BlueMen);
    }
    else if (character1 == 3 && character2 == 4)
    {
        fightMain(new BlueMen, new Medusa);
    }
    else if (character1 == 3 && character2 == 5)
    {
        fightMain(new BlueMen, new HarryPotter);
    }
    else if (character1 == 4 && character2 == 1)
    {
        fightMain(new Medusa, new Vampire);
    }
    else if (character1 == 4 && character2 == 2)
    {
        fightMain(new Medusa, new Barbarian);
    }
    else if (character1 == 4 && character2 == 3)
    {
        fightMain(new Medusa, new BlueMen);
    }
    else if (character1 == 4 && character2 == 4)
    {
        fightMain(new Medusa, new Medusa);
    }
    else if (character1 == 4 && character2 == 5)
    {
        fightMain(new Medusa, new HarryPotter);
    }
    else if (character1 == 5 && character2 == 1)
    {
        fightMain(new HarryPotter, new Vampire);
    }
    else if (character1 == 5 && character2 == 2)
    {
        fightMain(new HarryPotter, new Barbarian);
    }
    else if (character1 == 5 && character2 == 3)
    {
        fightMain(new HarryPotter, new BlueMen);
    }
    else if (character1 == 5 && character2 == 4)
    {
        fightMain(new HarryPotter, new Medusa);
    }
    else if (character1 == 5 && character2 == 5)
    {
        fightMain(new HarryPotter, new HarryPotter);
    }
}



//  Displays the menu. The entire program runs from this function.
void showMenu()
{
    int userInput = 0;
    int character1 = 0;
    int character2 = 0;
    
    
    while(userInput != 4 && userInput != 2 && userInput != 3)
    {
        cout << endl << endl << "Please select one of the options below: " << endl;
        usleep(250000);
        cout << "1: View game rules and descriptions of characters." << endl;
        usleep(250000);
        cout << "2: Start combat between two characters." << endl;
        usleep(250000);
        cout << "3: Run test driver to simulate all possible creature attacks." << endl;
        usleep(250000);
        
        cout << "4: Exit game." << endl;
        cout << "Enter a choice: ";
        cin >> userInput;
       
        while (userInput < 0 || userInput > 4)
        {
            cout << "Selection incorrect. Please enter an integer between 1 and 4: ";
            cin.clear();
            cin.ignore();
            cin >>userInput;
        }
        
        switch(userInput)
        {
            case 1:
                cout << endl << endl << endl;
                cout << "\t\t\t\t **RULES***" << endl << endl;
                cout << "*In this game two characters battle each other at a time." << endl;
                cout << "*Each character starts with its own unique attack, defense, armor, and stregnth attributes." << endl;
                cout << "*Each character will take turns rolling the die for attack and defense." << endl;
                cout << "*The game ends one of the characters dies." << endl;
                cout << "*Each round consists of two attacks, one for each character." << endl;
                cout << "*For each attack, attacker and defender both generate dice rolls." << endl;
                cout << "*Damage = attacker’s roll – defender’s roll – defender’s armor" << endl;
                cout << "*Then the value of that damage is subtracted from the defender’s strength points." << endl << endl;
                usleep(2500000);
                cout << "***\t\tCharacters\t\t***" << endl << endl;
                cout << "**Vampire: Suave, debonair, but vicious and surprisingly resilient." << endl;
                cout << "**Special Ability: Charm: Vampires can charm an opponent into not attacking. For a given attack there is a 50% chance that their opponent does not actually attack them." << endl << endl;
                cout << "**Barbarian: Think Conan or Hercules from the movies. Big sword, big muscles, bare torso." << endl;
                cout << "**Special Ability: None" << endl << endl;
                cout << "**Blue Men: They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies’ armor or clothing." << endl;
                cout << "**Special Ability: Mob: Blue Men are actually a swarm of small individuals. For every 4 points of damage, they lose one defense die. For example, if they have a strength of 8, they would have 2d6 for defense." << endl << endl;
                usleep(2500000);
                cout << "**Medusa: Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!" << endl;
                cout << "**Special Ability: Glare: If a Medusa rolls a 12 when attacking then the target instantly gets turned into stone and Medusa wins! If Medusa uses Glare on Harry Potter on his first life, then Harry Potter comes back to life." << endl << endl;
                cout << "**Harry Potter: Harry Potter is a wizard." << endl;
                cout << "**Special Ability: Hogwarts: If Harry Potter's strength reaches 0 or below, he immediately recovers and his total strength becomes 20. If he were to die again, then he’s dead." << endl << endl;
                cout << "\t\t\t Extras: " << endl;
                cout << "*If Medusa uses glare on Harry Potter on his first life, then Harry Potter comes back to life after using hogwarts." << endl;
                cout << "*If the Vampire’s charm ability activates when Medusa uses glare, the Vampire’s charm trumps Medusa’s glare." << endl << endl;
                usleep(2500000);
                
                userInput = 0;
                showMenu();
                break;
            case 2:
                character1 = getCharacter1();
                character2 = getCharacter2();
                runGame(character1, character2);
                playAgain();
                break;
            case 3:
                testMenu();
                userInput = 0;
                cin.clear();
                cin.ignore();
                break;
            case 4:
                cout << "Thank you for using the program" << endl << endl;
                usleep(1000000);
                exit(0);
        }
    }
}




//  Function to give player an option to run the game again
void playAgain()
{
    int choice;
    
    cout << "***Please select an option below***" << endl;
    cout << "1: Play game again." << endl;
    cout << "2: Quit game." << endl;
    cout << "Enter a choice: ";
    cin >> choice;
    while(choice != 1 && choice != 2)   {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid." << endl;
        playAgain();
    }
    if (choice == 1)
    {
        showMenu();
    }
    else
    {
        cout << "Thanks for playing!" << endl << endl;
        usleep(1000000);
        exit(0);
    }
}
