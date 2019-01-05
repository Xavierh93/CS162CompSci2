//  This is the header file for the base Character class.
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.


#ifndef character_hpp
#define character_hpp

#include <stdio.h>
#include <string>
using namespace std;


//  Base Class
class Character
{
protected:
    string type;
    double strength;
    int armor;
    int damage;
    int lives;
    int *mobDamage = &damage;
    
    virtual int rollAttackDice() = 0;
    virtual int rollDefenseDice() = 0;
    
public:
    string getType();
    void setArmor(int armor);
    int getArmor();
    void setStrength(double strength);
    double getStrength();
    int getDamage();
    void setLives(int lives);
    int getLives();
    virtual ~Character(){};
    virtual void attack(Character* opponent);
    virtual int defense();
    virtual void applyDamage(double damage);
    bool isDead();
};


#endif /* character_hpp */
