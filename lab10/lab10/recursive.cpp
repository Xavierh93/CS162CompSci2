//  This is the function file for the recursive implementation of the Fibonacci Numbers Calculation
//  Created by Xavier Elon Hollingsworth on 3/13/18.
//  Copyright © 2018 Xavier Elon Hollingsworth. All rights reserved.


#include "recursive.hpp"
#include <iostream>
#include <ctime>
using namespace std;


//  Recursive function for finding the nth term of the Fibonacci sequence
int recursiveFibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return (recursiveFibonacci(n-1) + recursiveFibonacci(n-2));
    }
}


//  Function that displays how long it took to find the nth term of the Fibonacci sequence
void displayFibonacci(int n, vector<long> *recursive)
{
    int i = 0;
    int fibonacci;
    clock_t time = clock();
    
    cout << "Calling Recursive Fibonacci implementation...";
    
    while (i < n)
    {
        fibonacci = recursiveFibonacci(i);
        i++;
    }
    time = clock() - time;
    long t = (time / CLOCKS_PER_SEC);
    recursive->push_back(t);
    cout << endl << "The recursive program took " << (time / CLOCKS_PER_SEC) << " seconds to reach the Fibonacci number " << n << endl << endl;
    
}
