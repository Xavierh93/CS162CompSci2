//  This is the file for the Die, LoadedDie, and Game classes.
//  Created by Xavier on 1/26/18.
//  Copyright © 2018 Xavier. All rights reserved.
//
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

//  ************************************************************************************************
//  Class for a normal die
//
//  ************************************************************************************************
class Die
{
    
    
protected:
    int N;
    string typeDie;
    
public:

Die(int sides)
{
    N = sides;
    typeDie = "normal";
}

//  Returns a random number in the range of 1 to the number of sides input by the user.
int getRoll()
{
    int number;
    
    number = rand() % N + 1;
    return number;
}

string getDie()
{
    return typeDie;
}

int getSides()
{
    return N;
}
};

//  ************************************************************************************************
//  Class for the loaded die. I made it a child class of the Die class
//
//  ************************************************************************************************
class LoadedDie : public Die
{
private:
    int N;
public:
    LoadedDie(int sides): Die(sides)
    {
        typeDie = "loaded";
    }
    
    //  I could not figure out how to properly load the die (i.e. just rolling it once and giving it a higher chance of its average landing being higher so I just generated two random values and then returning the higher of the two.
    int getRoll()
    {
        int value1, value2;
        
        value1 = rand() % N + 1;
        value2 = rand() % N + 1;
        if (value1 > value2)
            return value1;
        else
            return value2;
    }
    
    int getSides()
    {
        return N;
    }
    
    string getDie()
    {
        return typeDie;
    }
};

//  ************************************************************************************************
//  This class basically runs the whole game. It displays the start menu, the end results, gets
//  the user's input, and calls for the functions to roll the dice.
//  ************************************************************************************************
class Game
{

    //  Create objects as pointers because you don't know if they'll be loaded or not
    Die *d1, *d2;
private:
    int rounds;
    
public:
    //  Create 2 dynamically allocated arrays to hold the number of rounds input by user since it is nonstatic
    int* player1 = new int[rounds];
    int* player2 = new int[rounds];
    
    //  Basic start menu
    bool menu()
    {
        bool choice;
        int c;
        cout << "1: Play Game " << endl << "2: Exit game " << endl;
        cin >> c;
        while (c != 1 && c !=2)   {
            cin.clear();
            cin.ignore();
            cout << "Selection incorrect. Please enter 1 or 2: ";
            cin >> c;
        }
        if (c == 2){
            exit(0);
        }
        else
            return choice = 1;
    }
    
  //    This function retrieves all the user input needed to run the game.
    void getDynamics()
    {
        
        int faces;
        char type;
        
        
        cout << "How many rounds will be played? " << endl;
        cin >> rounds;
        while (rounds <=  0)    {
            cin.clear();    //  Used to prevent program from crashing from character input
            cin.ignore();
            cout << "Selection incorrect. Please enter an integer greater than 0: ";
            cin >> rounds;
        }
        
        cout << "For Player 1:" << endl << "Enter the number of sides on the die: ";
        cin >> faces;
        while (faces <= 0)   {
            cin.clear();
            cin.ignore();
            cout << "Selection incorrect. Please enter an integer greater than 0: ";
            cin >> faces;
        }
        cout << "Will Player 1 be playing with a loaded die (Y/N)?" << endl;
        cin >> type;
        while (type != 'Y' && type != 'N' && type != 'y' && type != 'n')   {
            cin.clear();
            cin.ignore();
            cout << "Selection incorrect. Please enter Y for yes or N for no: ";
            cin >> type;
        }
        //  Use the new keyword to dynamically allocate the objects to the LoadedDie class or Die class based on the user's input
        if (type == 'Y' || type == 'y')
            d1 = new LoadedDie(faces);
        else
            d1 = new Die(faces);
        
        cout << "For Player 2:" << endl << "Enter the number of sides on the die: ";
        cin >> faces;
        while (faces <= 0)  {
            cin.clear();
            cin.ignore();
            cout << "Selection incorrect. Please enter an integer greater than 0: ";
            cin >> faces;
        }
        cout << "Will Player 2 be playing with a loaded die (Y/N)?" << endl;
        cin >> type;
        while (type != 'Y' && type != 'N' && type != 'y' && type != 'n')   {
            cin.clear();
            cin.ignore();
            cout << "Selection incorrect. Please enter yes or no: ";
            cin >> type;
        }
        if (type == 'Y' || type == 'y')
            d2 = new LoadedDie(faces);
        else
            d2 = new Die(faces);
    }
    
    //  This function uses a for loop to iterate through each round and calls each objects getRoll function and stores the result in the 2d array
    void rollDice()
    {
        //  Creates a seed to generate a random number for the getRoll functions
        unsigned seed;
        seed = time(0);
        srand(seed);
        
        for(int n = 0; n < rounds; n++)
        {
            player1[n] = d1 -> getRoll();
            player2[n] = d2 -> getRoll();
        }
    }
    
    //  Function to display all of the results of the game
    void results()
    {
        int p1Score = 0;
        int p2Score = 0;
        int ties = 0;
        int i = 1;
        
        cout << endl << "Round  \tPlayer 1 \tPlayer2 " << endl;
        cout << "----------------------------------" << endl;
        
        //  Loops through every round iteration and adjusts variables accordingly
        for(int n = 0; n < rounds; n++)
        {
            
            cout << "Round " << i << ": \t" << player1[n] << "\t \t " << player2[n] << endl;
            i++;
            if(player1[n] > player2[n])
                p1Score++;
            else if(player1[n] < player2[n])
                p2Score++;
            else
                ties++;
        }
        cout << "----------------------------------" << endl << endl;
        cout << "\nPlayer 1 won " << p1Score << " games with a " << d1->getDie() << " die with " << d1->getSides() << " faces." << endl;
        cout << "Player 2 won " << p2Score << " games with a " << d2->getDie() << " die with "  << d2->getSides() << " faces." << endl;
        cout << "And there were " << ties << " ties." << endl;
        
        if (p1Score > p2Score)
            cout << "\nPlayer 1 won by " << p1Score - p2Score << " games." << endl << endl;
        else if (p2Score> p1Score)
            cout << "\nPlayer 2 won by " << p2Score - p1Score << " games." << endl << endl;
        else
            cout << "\nIt was a tie." << endl << endl;
        
        //  Delete the objects and the dynamically allocated arrays
        delete d1;
        delete d2;
        delete [] player1;
        delete [] player2;
    }
};
