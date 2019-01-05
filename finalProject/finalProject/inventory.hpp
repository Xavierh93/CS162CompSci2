//  This is the header file for the Inventory class.
//  Created by Xavier Elon Hollingsworth on 3/16/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#ifndef inventory_hpp
#define inventory_hpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Inventory
{
private:
    int size;
    bool key;
    bool healthPotion;
    bool trapPotion;
    int keyPos;
    int healthPotPos;
    int trapPotPos;
    int keyQuant;
    int healthPotQuant;
    int trapPotQuant;
    
public:
    vector<int> backpack;
    
    Inventory();
    void incSize();
    void decSize();
    int getSize();
    void addItem(int item);
    void decItem(int item);
    int getItem(int itemNumber);
    void removeItem(int itemNumber);
    bool isFull();
    void displayBackpack();
    bool hasKey();
    bool hasHealthPotion();
    bool hasTrapPotion();
    int getHealthPos();
    int getKeyPos();
    int getTrapPotPos();
    int getKeyQuant();
    int getHealthPotQuant();
    int getTrapPotQuant();
};

#endif /* inventory_hpp */
