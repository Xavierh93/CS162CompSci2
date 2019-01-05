//  This is the function file for the ExitSpace class.
//  Created by Xavier Elon Hollingsworth on 3/16/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#include "exitSpace.hpp"
#include <iostream>
using namespace std;


//  Default constructor
ExitSpace::ExitSpace()
{
    trap = false;
    item = false;
    exit = true;
}


//  Returns item variable
bool ExitSpace::getItem()
{
    return item;
}


//  Returns exit variable
bool ExitSpace::getExit()
{
    return exit;
}


//  Returns trap variable
bool ExitSpace::getTrap()
{
    return trap;
}

