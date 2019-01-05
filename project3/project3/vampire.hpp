//  This is the header file for the derived Vampire class.
//  vampire.hpp
//  project3
//
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#ifndef vampire_hpp
#define vampire_hpp

#include "character.hpp"
#include <stdio.h>
#include "dice.hpp"


//  Derived class
class Vampire : public Character
{
public:
    Vampire();
    Dice attack1;
    Dice defense1;
    virtual int rollAttackDice();
    virtual int rollDefenseDice();
    bool fiftyFifty();
};

#endif /* vampire_hpp */
