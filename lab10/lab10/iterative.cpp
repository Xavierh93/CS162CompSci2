//  This is the function file for the recursive implementation of the Fibonacci Numbers Calculation
//  Created by Xavier Elon Hollingsworth on 3/13/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.


#include "iterative.hpp"
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;


//  Function that finds the nth term of the Fibonacci sequence through iteration and then displays the amount of time it took to find the term.
void iterativeFibonacci(int n, vector<long> *iterative)
{
    int term1 = 0, term2 = 1, nextTerm;
    clock_t time = clock();
    
    cout << "Calling Iterative Fibonacci implementation... ";
    

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            continue;
        }
        else if (i == 1)
        {
            continue;
        }
        
        else
        {
            nextTerm = term1 + term2;
            term1 = term2;
            term2 = nextTerm;
        }
        
    }
    
    time = clock() - time;
    long t = (time / CLOCKS_PER_SEC);
    
    cout << endl << "The iterative program took " << (time / CLOCKS_PER_SEC) << " seconds to reach the Fibonacci number " << n << endl << endl;
    
    iterative->push_back(t);
            
}
