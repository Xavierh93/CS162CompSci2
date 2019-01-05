//  This is the header file for the Ant class file.
//  Created by Xavier on 1/12/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#ifndef ant_hpp
#define ant_hpp
#include <iostream>
#include <stdio.h>
using namespace std;

enum Direction {north, east, south, west};

class Ant
{
private:
    Direction direction;
    int prevRow, prevCol, currentRow, currentCol;
    char currentColor;
    
public:
    Ant();
    ~Ant();
    Ant(int row, int column);
    void setDirection(Direction d);
    Direction getDirection();
    void setPrevRow(int pr);
    int getPrevRow();
    void setPrevCol(int pc);
    int getPrevCol();
    void setCurrentRow(int cr);
    int getCurrentRow();
    void setCurrentCol(int cc);
    int getCurrentCol();
    void setCurrentColor(char ccc);
    char getCurrentColor();
};
#endif /* ant_hpp */
