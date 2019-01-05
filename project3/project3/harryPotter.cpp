//  This is the file for the derived HarryPotter class.
//  Created by Xavier on 2/13/18.
//  Copyright © 2018 Xavier. All rights reserved.


#include <iostream>
#include <string>
#include "harryPotter.hpp"
#include "dice.hpp"
using namespace std;

//  Constructor to initialize character traits
HarryPotter::HarryPotter()
{
    type = "Harry Potter";
    strength = 10;
    armor = 0;
    lives = 2;
    attack1 = Dice(6);
    attack2 = Dice(6);
    defense1 = Dice(6);
    defense2 = Dice(6);
}

int HarryPotter::rollAttackDice()
{
    if (getStrength() < 1 && lives > 1)
    {
        //  Hogwarts
        setStrength(20);
        lives = 1;
        cout << endl << "Harry Potter has used his special ability Hogwarts and has been resurrected with 20 strength!" << endl;
        return Dice::rollTwo(attack1, attack2);
    }
    else
    {
        return Dice::rollTwo(attack1, attack2);
    }
}

int HarryPotter::rollDefenseDice()
{
    return Dice::rollTwo(defense1, defense2);
}
