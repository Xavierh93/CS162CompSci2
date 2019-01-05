//  This is the function file for the User Class.
//  Created by Xavier on 3/16/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#include "user.hpp"


//  Default constructor
User::User()
{
    health = 100;
    steps = 15;
    win = false;
    lose = false;
}


//  Returns users current health
double User::getHealth()
{
    return health;
}


//  Reduces steps variable by 1
void User::setSteps()
{
    this -> steps = steps - 1;
}


//  Returns steps variable
int User::getSteps()
{
    return steps;
}


//  Reduces users health by 20
void User::reduceHealth()
{
    health = health - 20;
}


//  Adds 15 to users health
void User::addHealth()
{
    health = health + 15;
}


//  Sets win variable to true
void User::setWinGame()
{
    win = true;
}


//  Returns win variable
bool User::getWinGame()
{
    return win;
}


//  Sets lose variable to true
void User::setLoseGame()
{
    lose = true;
}


//  Returns lose variable
bool User::getLoseGame()
{
    return lose;
}
