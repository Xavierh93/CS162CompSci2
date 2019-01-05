//
//  Created by Xavier on 1/24/18.
//  Copyright © 2018 Xavier. All rights reserved.

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "die.cpp"

using namespace std;

int main() {
    
    //  Create object
    Game g;
    //  Run game
    g.menu();
    g.getDynamics();
    g.rollDice();
    g.results();
    return 0;
}
