//  This is the file for the base Character class.
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.


#include "character.hpp"
#include "dice.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
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


//  Function that gets the attack and displays it on the screen
void Character::attack(Character *opponent)
{
    int damage = 0;
    double totalDamage;
    string name1 = this -> type;
    string name2 = opponent -> type;
    int attack = rollAttackDice();
    
    if (name1 == "Medusa" && name2 == "Harry Potter" && attack == 12)
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
        usleep(400000);
        cout << endl << this -> type << " attacks " << opponent -> type;
        cout << " and deals " << damage << " damage." << endl;
        usleep(400000);
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
    if (getStrength() <= 0)
    {
        strength = 0;
        --lives;
        this -> setLives(lives);
    }
    
    cout << this -> type << " defends " << def << " with " << armor << " armor." << endl;
    usleep(400000);
    cout << this -> type << " takes " << totalDamage <<  " damage.";
}


//  Function to check if character is dead
bool Character::isDead()
{
    bool dead = false;
    if (getStrength() <= 0 && getLives() == 0)
    {
        return dead = true;
    }
    else
    {
        return dead = false;
    }
}
