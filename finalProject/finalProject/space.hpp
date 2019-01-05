//  This is the header file for the Space Class
//  Created by Xavier Elon Hollingsworth on 3/15/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#ifndef space_hpp
#define space_hpp

#include <stdio.h>

class Space
{
protected:
    int rows;
    int columns;
    int number;
    int space;
    int top;
    int bottom;
    int right;
    int left;
    int cube[8][8];
    bool trap;
    bool item;
    bool exit;
    int itemNumber;
    
    
    
public:
    Space(){}
    ~Space(){};
    void setSpace(int userLoc);
    int getSpace();
    void setTop(int topLoc);
    int getTop();
    void setBottom(int bottomLoc);
    int getBottom();
    void setRight(int rightLoc);
    int getRight();
    void setLeft(int leftLoc);
    int getLeft();
    virtual bool getItem();
    virtual bool getExit();
    virtual bool getTrap();
    
};

#endif /* space_hpp */
