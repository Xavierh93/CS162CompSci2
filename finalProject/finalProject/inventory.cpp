//  This is the file for the Inventory Class.
//  Created by Xavier Elon Hollingsworth on 3/16/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#include "inventory.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <list>
using namespace std;


//  Default constructor
Inventory::Inventory()
{
    size = 0;
    healthPotion = false;
    key = false;
    trapPotion = false;
    keyPos = 0;
    healthPotPos = 0;
    trapPotPos = 0;
    keyQuant = 0;
    healthPotQuant = 0;
    trapPotQuant = 0;
}


//  Increases size variable by 1
void Inventory::incSize()
{
    size = size + 1;
}


//  Decreases size variable by 1
void Inventory::decSize()
{
    size = size - 1;
}


//  Returns the variable size
int Inventory::getSize()
{
    return size;
}


//  Adds an item to the backpack based on the number and sets the appropriate variable
void Inventory::addItem(int item)
{
    backpack.push_back(item);
    if (item == 1)
    {
        keyQuant = keyQuant + 1;
        key = true;
    }
    else if (item == 2)
    {
        healthPotQuant = healthPotQuant + 1;
        healthPotion = true;
    }
    else
    {
        trapPotQuant = trapPotQuant + 1;
        trapPotion = true;
    }
}


//  Checks what item is being removed and then decrements the appropriate variable and changes the bool value accordingly
void Inventory::decItem(int item)
{
    if (backpack.at(item) == 1)
    {
        keyQuant = keyQuant - 1;
        if (keyQuant < 1)
        {
            key = false;
        }
        else
        {
            key = true;
        }
    }
    else if (backpack.at(item) == 2)
    {
        healthPotQuant = healthPotQuant - 1;
        if (healthPotQuant < 1)
        {
            healthPotion = false;
        }
        else
        {
            healthPotion = true;
        }
    }
    else
    {
        trapPotQuant = trapPotQuant - 1;
        if (trapPotQuant < 1)
        {
            trapPotion = false;
        }
        else
        {
            trapPotion = true;
        }
    }
}


//  Returns number at index location
int Inventory::getItem(int itemNumber)
{
    return backpack.at(itemNumber);
}


//  Removes indexed item
void Inventory::removeItem(int itemNumber)
{
    backpack.erase(backpack.begin() + (itemNumber));
}


//  Check is backpack is full
bool Inventory::isFull()
{
    if (backpack.size() == 4)
    {
        return true;
    }
    else
        return false;
}



//  Displays contents of backpack
void Inventory::displayBackpack()
{
    int number = 1;
    vector<int> temp = backpack;
    string currentItem;
    
    cout << "The items in your backpack currently are:" << endl;
    
    while (temp.size() != 0)
    {
        if (temp.front() == 1)
        {
            currentItem = "Key";
        }
        else if (temp.front() == 2)
        {
            currentItem = "Health Potion";
        }
        else if (temp.front() == 3)
        {
            currentItem = "Trap Potion";
        }
        
        cout << number << ". " << currentItem << endl;
        number++;
        temp.erase(temp.begin());
    }
}


//  Checks if user has key
bool Inventory::hasKey()
{
    return key;
}


//  Check is user has a health potion
bool Inventory::hasHealthPotion()
{
    return healthPotion;
}


//  Checks if user has a trap potion
bool Inventory::hasTrapPotion()
{
    return trapPotion;
}


//  Returns the position of a health potion
int Inventory::getHealthPos()
{
    if (backpack.at(0) == 2)
    {
        return 0;
    }
    else if (backpack.at(1) == 2)
    {
        return 1;
    }
    else if (backpack.at(2) == 2)
    {
        return 2;
    }
    else
        return 3;
}


//  Returns the position of a key
int Inventory::getKeyPos()
{
    if (backpack.at(0) == 1)
    {
        return 0;
    }
    else if (backpack.at(1) == 1)
    {
        return 1;
    }
    else if (backpack.at(2) == 1)
    {
        return 2;
    }
    else
        return 3;
}


//  Returns the position of a trap potion
int Inventory::getTrapPotPos()
{
    if (backpack.at(0) == 3)
    {
        return 0;
    }
    else if (backpack.at(1) == 3)
    {
        return 1;
    }
    else if (backpack.at(2) == 3)
    {
        return 2;
    }
    else
        return 3;
}


//  Return keyQuant variable
int Inventory::getKeyQuant()
{
    return keyQuant;
}


//  Returns healthPotQuant variable
int Inventory::getHealthPotQuant()
{
    return healthPotQuant;
}


//  Returns trapPotQuant variable
int Inventory::getTrapPotQuant()
{
    return trapPotQuant;
}
