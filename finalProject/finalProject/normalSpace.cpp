//  This is the function file for the NormalSpace class.
//  Created by Xavier Elon Hollingsworth on 3/16/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#include "normalSpace.hpp"


//  Default constructor
NormalSpace::NormalSpace()
{
    int itemChance = 1 + rand() % ((2+1) - 1);
    if (itemChance == 1)
        item = true;
    else
        item = false;
    trap = false;
    
    exit = false;
}


//  Returns item variable
bool NormalSpace::getItem()
{
    return item;
}


//  Returns exit variable
bool NormalSpace::getExit()
{
    return exit;
}


//  Returns trap variable
bool NormalSpace::getTrap()
{
    return trap;
}
