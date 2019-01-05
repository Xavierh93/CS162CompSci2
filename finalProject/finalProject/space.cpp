//  This is the function file for the base Space class
//  Created by Xavier Elon Hollingsworth on 3/15/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#include "space.hpp"


//  Sets the number variable to the current space
void Space::setSpace(int userLoc)
{
    space = userLoc;
    number = space;
}


//  Returns users current location
int Space::getSpace()
{
    return number;
}


//  Sets top space
void Space::setTop(int topLoc)
{
    top = topLoc;
}


//  Returns value in top space
int Space::getTop()
{
    return top;
}


//  Sets bottom space
void Space::setBottom(int bottomLoc)
{
    bottom = bottomLoc;
}


//  Returns value in bottom space
int Space::getBottom()
{
    return bottom;
}


//  Sets right space
void Space::setRight(int rightLoc)
{
    right = rightLoc;
}


//  Returns value in right space
int Space::getRight()
{
    return right;
}


//  Sets left space
void Space::setLeft(int leftLoc)
{
    left = leftLoc;
}


//  Returns value in left space
int Space::getLeft()
{
    return left;
}


//  Pure virtual function that checks if space has an item
bool Space::getItem()
{
    return item;
}


//  Pure virtual function that checks if space has an exit
bool Space::getExit()
{
    return exit;
}


//  Pure virtual function that checks if space has a trap
bool Space::getTrap()
{
    return trap;
}



