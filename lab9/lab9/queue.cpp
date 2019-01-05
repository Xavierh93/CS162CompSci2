//  This is the function file for the queue/buffer portion of the program.
//  Created by Xavier on 3/9/18.
//  Copyright © 2018 Xavier. All rights reserved.
//

#include "queue.hpp"
#include "functions.hpp"
#include <iostream>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
using namespace std;

void queueContainer()
{
    //  Create variables
    int rounds, N, N2, pushStatus, popStatus;
    double pushChance, popChance;
    double avg = 0, avgPrev;
    queue<int, list<int>> que, queTemp;
    
    //  Generate random seed
    unsigned seed;
    seed = time(0);
    srand(seed);
    
    //  Receive variable inputs from user
    
    rounds = mainMenuRounds();
    pushChance = mainMenuPush();
    popChance = mainMenuPop();
    
    for (int i = 0; i < rounds; i++)
    {
        pushStatus = 0;
        popStatus = 0;
        avgPrev = avg;
        
        N = rand() % 1000 + 1;
        
        N2 = rand() % 100 + 1;
        
        if (N2 <= pushChance)
        {
            que.push(N);
            pushStatus++;
        }
        
        N2 = rand() % 100 + 1;
        
        if (N2 <= popChance && !que.empty())
        {
            que.pop();
            popStatus++;
        }
        
        queTemp = que;
        
        cout << endl << "Round " << (i + 1) << endl;
        
        if (pushStatus && popStatus)
        {
            cout << "Both push and pop have been triggered." << endl;
        }
        else if (pushStatus)
        {
            cout << "Only the push function has been triggered." << endl;
        }
        else if (popStatus)
        {
            cout << "Only the pop function has been triggered." << endl;
        }
        else
        {
            cout << "Neither the push nor pop function has been triggered." << endl;
        }
        
        cout << "Elements of the queue from the front are: ";
        while (!queTemp.empty())
        {
            cout << queTemp.front() << " ";
            queTemp.pop();
        }
        
        cout << endl;
        
        cout << "The length of the buffer after round " << (i + 1) << " is: " << que.size() << endl;
        
        avg =(avgPrev * i + que.size()) / (i + 1);
        cout << "The average of the buffer after round " << (i + 1) << " is: " << avg << endl;
    }
}
