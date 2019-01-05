//  This is the class file for the derived TrapSpace class.
//  Created by Xavier Elon Hollingsworth on 3/16/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#include "trapSpace.hpp"


//  Default constructor
TrapSpace::TrapSpace()
{
    trap = true;
    item = true;
    exit = false;
}


//  Checks if space has an item
bool TrapSpace::getItem()
{
    return item;
}


//  Checks if space has an exit
bool TrapSpace::getExit()
{
    return exit;
}


//  Checks if space has a trap
bool TrapSpace::getTrap()
{
    return trap;
}
