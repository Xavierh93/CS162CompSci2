//  This is the file that contains various functions like the menu, rolling the die, and
//  Created by Xavier on 2/16/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cmath>
#include <unistd.h>
#include "character.hpp"
#include "functions.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"
using namespace std;



void titleDisplay()
{
    cout << "*** Welcome to the Fantasy Combat Game *** " << endl;
}


//  Displays opening menu
void playMenu()
{
    int choice;
    
    cout << "***Please select an option below***" << endl;
    cout << "1: Play" << endl;
    cout << "2: Exit" << endl;
    cout << "Enter a choice: ";
    cin >> choice;
    while(choice != 1 && choice != 2)   {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid." << endl;
        playMenu();
    }
    if (choice == 1)
    {
        retrieveNumbers();
    }
    else
    {
        cout << "Thanks for playing!" << endl << endl;
        usleep(1000000);
        exit(0);
    }
}


//  Retrieves number of fighters for each team
void retrieveNumbers()
{
    int team1 = 0;
    int team2 = 0;
    
    
    cout << "Enter the number of fighters for Team 1: ";
    cin >> team1;
    while (team1 < 1 || team1 > 10)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection invalid. Please enter between 1 and 10 for the number of fighters on Team 1: ";
        cin >> team1;
    }
    cout << "Enter the number of fighters for Team 2: ";
    cin >> team2;
    while (team2 < 1 || team2 > 10)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection invalid. Please enter between 1 and 10 for the number of fighters on Team 2: ";
        cin >> team2;
    }
    retrieveTeams(team1, team2);
}


//  Retrieves the characters being used on each team
void retrieveTeams(int team1, int team2)
{
    int numbers1 = team1;
    int numbers2 = team2;
    int fighter[team1];
    int fighter2[team2];
    Queue q1, q2;
    Queue *teamOne = &q1;
    Queue *teamTwo = &q2;
    Queue losers;
    Queue *losersPtr = &losers;
    
    //  Get characters for team1
    for (int i = 0; i < team1; i++)
    {
        cout << "Select the number for the fighter you would like to use for poisition " << (i +1) << " on Team 1." << endl;
        cout << "1: Vampire" << endl;
        cout << "2: Barbarian" << endl;
        cout << "3: Blue Men" << endl;
        cout << "4: Medusa" << endl;
        cout << "5: Harry Potter" << endl;
        cout << "Enter a choice: ";
        cin.clear();
        cin >> fighter[i];
        while (fighter[i] < 1 || fighter[i] > 10)
        {
            cin.clear();
            cin.ignore();
            cout << "Selection invalid. Please enter between 1 and 10 for the fighter you would like at position " << (i + 1) << " on Team 1: " ;
            cin >> fighter[i];
        }
    }
    cin.clear();
    cin.ignore();
    createTeam1(fighter, numbers1, teamOne);
    
    //  Get characters for team2
    for (int j = 0; j < team2; j++)
    {
        cout << "Select the number for the fighter you would like to use for poisition " << (j+1) << " on Team 2." << endl;
        cout << "1: Vampire" << endl;
        cout << "2: Barbarian" << endl;
        cout << "3: Blue Men" << endl;
        cout << "4: Medusa" << endl;
        cout << "5: Harry Potter" << endl;
        cout << "Enter a choice: ";
        cin.clear();
        cin >> fighter2[j];
        while (fighter2[j] < 1 || fighter2[j] > 10)
        {
            cin.clear();
            cin.ignore();
            cout << "Selection invalid. Please enter between 1 and 10 for the fighter you would like at position " << (j + 1) << " on Team 2: " ;
            cin >> fighter2[j];
        }
    }
    cin.clear();
    cin.ignore();
    createTeam2(fighter2, numbers2, teamTwo);
    
    //  Tournament fights run here until one team is out of fighters
    while (!teamOne->isEmpty() && !teamTwo->isEmpty())
    {
        fightMain(teamOne, teamTwo, losersPtr);
    }
    
    // If to else if statement to determine winners
    if (teamOne->getPoints() == teamTwo->getPoints())
    {
        cout << "The game has ended in a tie!" << endl;
        cout << "Team 1 Points: " << teamOne->getPoints() << endl;
        cout << "Team 2 Points: " << teamTwo->getPoints() << endl;
    }
    else if (teamOne->getPoints() > teamTwo->getPoints())
    {
        cout << "Final Scores" << endl;
        cout << "***************************" << endl;
        cout << "Team 1 Points: " << teamOne->getPoints() << endl;
        cout << "Team 2 Points: " << teamTwo->getPoints() << endl << endl;
        cout << "Team 1 WINS!" << endl;
        showWinners(teamOne, 1);
        
    }
    else if (teamTwo->getPoints() > teamOne->getPoints())
    {
        cout << "Final Scores" << endl;
        cout << "***************************" << endl;
        cout << "Team 1 Points: " << teamOne->getPoints() << endl;
        cout << "Team 2 Points: " << teamTwo->getPoints() << endl;
        cout << "***************************" << endl;
        cout << "Team 2 WINS!" << endl << endl;
        showWinners(teamTwo, 2);
    }
    //  Ask user to display losers bracket and ask user if they want to play again
    showLosers(losersPtr);
    playAgain();
}


//  Creates character objects for team1 based on user input
void createTeam1(int fighter[], int number, Queue *q1)
{
    string name;
    
    for (int i = 0; i < number; i++)
    {
        cin.clear();
        if (fighter[i] == 1)
        {
            Character *fighter = new Vampire();
            cout << "Enter a name for the fighter " << (i+1) << ": ";
            getline(cin, name);
            fighter->setName(name);
            q1 -> addTailNode(fighter);
        }
        else if (fighter[i] == 2)
        {
            Character *fighter = new Barbarian();
            cout << "Enter a name for the fighter " << (i+1) << ": ";
            getline(cin, name);
            fighter->setName(name);
            q1 ->addTailNode(fighter);
        }
        else if (fighter[i] == 3)
        {
            Character *fighter = new BlueMen();
            cout << "Enter a name for the fighter " << (i+1) << ": ";
            getline(cin, name);
            fighter->setName(name);
            q1 -> addTailNode(fighter);
        }
        else if (fighter[i] == 4)
        {
            Character *fighter = new Medusa();
            cout << "Enter a name for the fighter " << (i+1) << ": ";
            getline(cin, name);
            fighter->setName(name);
            q1 -> addTailNode(fighter);
        }
        else if (fighter[i] == 5)
        {
            Character *fighter = new HarryPotter();
            cout << "Enter a name for the fighter " << (i+1) << ": ";
            getline(cin, name);
            fighter->setName(name);
            q1 -> addTailNode(fighter);
        }
    }
}

//  Function to create character objects for team2 based on user input
void createTeam2(int fighter2[], int number2, Queue *q2)
{
    string name;
    
    for (int i = 0; i < number2; i++)
    {
        cin.clear();
        if (fighter2[i] == 1)
        {
            Character *fighter2 = new Vampire();
            cout << "Enter a name for the fighter " << (i+1) << ": ";
            getline(cin, name);
            fighter2->setName(name);
            q2->addTailNode(fighter2);
        }
        else if (fighter2[i] == 2)
        {
            Character *fighter2 = new Barbarian();
            cout << "Enter a name for the fighter " << (i+1) << ": ";
            getline(cin, name);
            fighter2->setName(name);
            q2->addTailNode(fighter2);
        }
        else if (fighter2[i] == 3)
        {
            Character *fighter2 = new BlueMen();
            cout << "Enter a name for the fighter " << (i+1) << ": ";
            getline(cin, name);
            fighter2->setName(name);
            q2->addTailNode(fighter2);
        }
        else if (fighter2[i] == 4)
        {
            Character *fighter2 = new Medusa();
            cout << "Enter a name for the fighter " << (i+1) << ": ";
            getline(cin, name);
            fighter2->setName(name);
            q2->addTailNode(fighter2);
        }
        else if (fighter2[i] == 5)
        {
            Character *fighter2 = new HarryPotter();
            cout << "Enter a name for the fighter " << (i+1) << ": ";
            getline(cin, name);
            fighter2->setName(name);
            q2->addTailNode(fighter2);
        }
    }
}


//  Main fight function. One character from each team fights until one loses. Adjusts all points and lists at the end.
void fightMain(Queue *team1, Queue *team2, Queue *losers)
{
    int formerPoints1;
    int formerPoints2;
    int points1;
    int points2;
    int teamPoints1;
    int teamPoints2;
    
    Character *player1 = team1->getFront();
    Character *player2 = team2->getFront();
    bool gameOver = false;
    cout << endl << "*******************************************" << endl;
    cout << player1 -> getType() << " (" << player1 -> getName() << ")" << " VS. " << player2 -> getType() << " (" << player2 -> getName() << ")" << endl;
    cout << endl << "*******************************************" << endl << endl;
    cout << player1 -> getName() << " starting strength: " << player1 -> getStrength() << endl;
    cout << player2 -> getName() << " starting strength: " << player2 -> getStrength() << endl;
    while (!gameOver)
    {
        player1 -> attack(player2);
        player2 -> attack(player1);
        
        cout << endl << player1 -> getName() << " remaining strength: " << player1 -> getStrength();
        cout << endl << player2 -> getName() << " remaining strength: " << player2 -> getStrength();
        cout << endl;
        
        
        //  Displays fight winner. Adjusts winner strength. Adjust team and players points. Adjust linked list for both teams and adds loser to losers linked list
        if (player1 -> isDead())
        {
            cout << endl << player1 -> getName() << " is dead! " << player2->getName() << " has won the battle!" << endl;
            gameOver = true;
            formerPoints1 = player1 -> getPoints();
            points1 = formerPoints1 - 1;
            player1 -> setPoints(points1);
            formerPoints2 = player2 -> getPoints();
            points2 = formerPoints2 + 2;
            player2 -> setPoints(points2);
            player2 -> recover();
            cout << player2->getName() << " has recovered 50% of their original health!" << endl;
            teamPoints2 = 2 + team2->getPoints();
            team2->setPoints(teamPoints2);
            teamPoints1 = team1->getPoints() - 1;
            team1->setPoints(teamPoints1);
            team1->removeFront();
            team2->moveToLastNode();
            losers->addHeadNode(player1);
        }
        if (player2 -> isDead())
        {
            cout << endl << player2 -> getName() << " is dead! " << player1->getName() << " has won the battle!" << endl;
            gameOver = true;
            formerPoints1 = player1 -> getPoints();
            points1 = formerPoints1 + 2;
            player1 -> setPoints(points1);
            player1 -> recover();
            cout << player1->getName() << " has recovered 50% of their original health!" << endl;
            formerPoints2 = player2 -> getPoints();
            points2 = formerPoints2 - 1;
            player2 -> setPoints(points2);
            teamPoints2 = team2->getPoints() - 1;
            team2->setPoints(teamPoints2);
            teamPoints1 = team1->getPoints() + 2;
            team1->setPoints(teamPoints1);
            team2->removeFront();
            team1->moveToLastNode();
            losers->addHeadNode(player2);
        }
    }
    cout << endl;
}



//  Displays the winners bracket
void showWinners(Queue *winners, int team)
{
    Character *winner;
    int count = 1;
    cout << "Team " << team << " scores: " << endl;
    while (!winners->isEmpty())
    {
        winner = winners->getFront();
        cout << count << ": " << winner -> getName() << " (" << winner -> getType() << ")" << " Points = " << winner -> getPoints() << endl;
        count++;
        winners->removeFront();
    }
}


//  Asks user if they want to see the losers bracket
void showLosers(Queue *losers)
{
    char input;
    Character *loser;
    int count = 1;
    cout << endl << "Would you like to display the losers bracket? (Y/N)" << endl;
    cin >> input;
    
    while (input != 'y' && input != 'Y' && input != 'n' && input != 'N')
    {
        cout << "Selection incorrect. Please enter 'Y' for yes or 'N' for no: ";
        cin.get(input);
    }
    
    if (input == 'y' || input == 'Y')
    {
        cout << endl << "Losers Bracket: " << endl;
        while (!losers->isEmpty())
        {
            loser = losers->getFront();
            cout << count << ": " << loser -> getName() << " (" << loser -> getType() << ")" << " Points = " << loser -> getPoints() << endl;
            count++;
            losers->removeFront();
        }
    }
    else if (input == 'n' || input == 'N')
    {
        return;
    }
}


//  Function to give player an option to run the game again
void playAgain()
{
    int choice;
    
    
    cout << endl << "***Please select an option below***" << endl;
    cout << "1: Play game again." << endl;
    cout << "2: Quit game." << endl;
    cout << "Enter a choice: ";
    cin >> choice;
    while(choice != 1 && choice != 2)
    {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid. Please try again: " << endl;
        cin >> choice;
    }
    if (choice == 1)
    {
        cin.ignore();
        retrieveNumbers();
    }
    else
    {
        cout << "Thanks for playing!" << endl << endl;
        usleep(1000000);
        exit(0);
    }
}




