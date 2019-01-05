//  This is the file for the base Character class.
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.


#include "character.hpp"
#include "dice.hpp"
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;


void Character::setArmor(int armor)
{
    this -> armor = armor;
}

int Character::getArmor()
{
    return armor;
}

void Character::setStrength(double strength)
{
    this -> strength = strength;
}

double Character::getStrength()
{
    return strength;
}

string Character::getType()
{
    return type;
}


void Character::setLives(int lives)
{
    this -> lives = lives;
}


int Character::getLives()
{
    return lives;
}

void Character::setName(string name)
{
    
    alias = name;
}

string Character::getName()
{
    return alias;
}


void Character::setPoints(int points)
{
    this -> points = points;
}


int Character::getPoints()
{
    return points;
}


//  Winner recovers half of their starting strength.
void Character::recover()
{
    int strength1;
    int strength2;
    int totalStrength;
    strength1 = (maxStrength/2);
    strength2 = getStrength();
    totalStrength = strength1 + strength2;
    setStrength(totalStrength);
}



//  Function that gets the attack and displays it on the screen
void Character::attack(Character *opponent)
{
    int damage = 0;
    double totalDamage;
    string name1 = this -> getType();
    int attack = rollAttackDice();
    
    if (name1 == "Medusa" && attack == 12)
    {
        opponent -> lives = --lives;
        opponent -> strength = 0;
        opponent -> setStrength(strength);
        opponent -> setLives(lives);
        cout << "Medusa used glare on " << opponent -> getType() << " and turned him into stone!" << endl;
    }
    else
    {
        damage = attack;
        totalDamage = damage;
        
        cout << endl << this -> alias << " attacks " << opponent -> alias;
        cout << " and deals " << damage << " damage." << endl;
        opponent -> applyDamage(totalDamage);
    }
    
}

int Character::defense()
{
    
    return rollDefenseDice();
}


//  Function to apply the damage to the defending character and substract it from its strength
void Character::applyDamage(double damage)
{
    
    int def = defense();
    double totalDamage = (damage - armor) - def;
    
    if (totalDamage < 0)
    {
        totalDamage = 0;
    }
    
    double newStrength = strength - totalDamage;
    strength = newStrength;
    this -> setStrength(strength);
    if (getStrength() <= 0)
    {
        strength = 0;
        this -> setStrength(strength);
        lives -= 1;
        this -> setLives(lives);
        
        if (this -> getLives() == 1)
        {
           //   Harry Potter uses Hogwarts skill
            this -> strength = 20;
            this -> setStrength(strength);
            cout << "Harry Potter used Hogwarts special ability and has been resurrected with 20 strength!" << endl;
        }
    }
    cout << this -> alias << " defends " << def << " with " << armor << " armor." << endl;
    cout << this -> alias << " takes " << totalDamage <<  " damage.";
}


//  Function to check if character is dead
bool Character::isDead()
{
    bool dead = false;
    if (strength <= 0 && lives == 0)
    {
        return dead = true;
    }
    else
    {
        return dead = false;
    }
}
