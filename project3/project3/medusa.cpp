//  This is the file for the derived Medusa class.
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include "medusa.hpp"
#include "dice.hpp"
#include "character.hpp"
#include "functions.cpp"
#include <iostream>
#include <string>
using namespace std;


//  Constructor to initialize character traits
Medusa::Medusa()
{
    type = "Medusa";
    strength = 8;
    armor = 3;
    attack1 = Dice(6);
    attack2 = Dice(6);
    defense1 = Dice(6);
}

int Medusa::rollAttackDice()
{
    return Dice::rollTwo(attack1, attack2);
}

int Medusa::rollDefenseDice()
{
    return Dice::rollOne(defense1);
}
