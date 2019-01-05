//  This is the header file for the User class
//  Created by Xavier on 3/16/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.
//

#ifndef user_hpp
#define user_hpp

#include <stdio.h>

class User
{
private:
    double health;
    int steps;
    bool win;
    bool lose;
public:
    User();
    double getHealth();
    void setSteps();
    int getSteps();
    void reduceHealth();
    void addHealth();
    void setWinGame();
    bool getWinGame();
    void setLoseGame();
    bool getLoseGame();
};

#endif /* user_hpp */
